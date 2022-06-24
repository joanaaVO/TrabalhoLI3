#include "../Includes/businesses.h"
#include <ctype.h>

#define BUFF_SIZE 500

struct businesses{
    GHashTable *businesses;
};

BUSINESSES init_Businesses(){
    BUSINESSES businesses = malloc(sizeof(struct businesses));
    businesses->businesses = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroyBusiness);

    return businesses;
}

void InsertBusinessToBusinesses(BUSINESSES businesses, BUSINESS business){
    char* business_id = getBusinessID(business);
    g_hash_table_insert(businesses->businesses, business_id, business);
}

void destroyBusinesses(BUSINESSES businesses) {
    //g_hash_table_destroy (businesses->businesses);
    free(businesses);
}

GHashTable* get_businesses (BUSINESSES businesses) {
    return businesses->businesses;
}

BUSINESSES read_businesses(char *filename){
    
    FILE* f = fopen(filename,"r");

    if(f==NULL){
        fprintf(stderr, "Erro ao abrir ficheiro %s\n",filename);
        return NULL;
    }

    BUSINESSES businesses = init_Businesses();
    char buffer[BUFF_SIZE];
    fgets(buffer,BUFF_SIZE,f);
    int i = 0;
    while (fgets(buffer,BUFF_SIZE,f)!=NULL){
        char* businessLinha = buffer;
        
        BUSINESS business = InitBusinessFromLine(businessLinha);
        InsertBusinessToBusinesses(businesses, business);
    }
    printf("Lidos %d businesses\n",g_hash_table_size(businesses->businesses));
    fclose(f);

    return businesses;    
}

//Funcões query 2
gint compare_by_letter (gconstpointer a, gconstpointer b) {
    char *str_a = (char*) a;
    str_a[0] = toupper(str_a[0]);
    char *str_b = (char*) b;
    str_b[0] = toupper(str_b[0]);

    return strcmp (str_a, str_b);
}

GList* get_businesses_by_letter(GHashTable* businesses, GList* list, char letter) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BUSINESS business = (BUSINESS) value;
        char* name = strdup(getBusinessName(business));
        if (name[0] == letter) list = g_list_prepend(list,name);
    }
    list = g_list_sort(list, compare_by_letter);

    return list;  
}
