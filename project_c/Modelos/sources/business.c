#include "../Includes/business.h"

struct business{
    char *business_id;
    char *name;
    char *city;
    char* state;
    GHashTable* categories;
    GHashTable* reviews_ids;
};

BUSINESS InitBusinessFromLine(char *linha){
    char* businessLinha = linha;
    char *business_id = strdup(strsep(&businessLinha,";"));
    char *name = strdup(strsep(&businessLinha,";"));
    char *city = strdup(strsep(&businessLinha,";"));
    char *state = strdup(strsep(&businessLinha,";"));
    char * buffer = strdup(strsep(&businessLinha,"\n"));
    GHashTable* categorias = g_hash_table_new(g_str_hash, g_str_equal);
    
    char* buf;
    while ((buf = strsep(&buffer,",")) != NULL) {
        g_hash_table_insert(categorias, buf, buf);
    }

    return init_business(business_id, name, city, state, categorias);
}

BUSINESS init_business(char *business_id, char *name, char *city, char *state, GHashTable *categorias){
    BUSINESS business = malloc(sizeof(struct business));
    business->business_id = strdup(business_id);
    business->name = strdup(name);
    business->city = strdup(city);
    business->state = strdup(state);
    business->categories = categorias;
    business-> reviews_ids = g_hash_table_new(g_str_hash, g_str_equal); //preenchido na leitura dos reviews
    free(business_id);
    free(name);
    free(city);
    free(state);

    return business;
}

char* getBusinessID(BUSINESS b) {
    return strdup(b->business_id);
}

char* getBusinessName(BUSINESS u){
	return strdup(u->name);
}

char* getBusinessCity(BUSINESS bs) {
    return strdup(bs->city);
}

char* getBusinessState(BUSINESS bs) {
    return strdup(bs->state);
}

GHashTable* getBusinessCategories(BUSINESS bs) {
    return bs->categories;
}

GHashTable* getReviewsIds(BUSINESS bs){
    return bs->reviews_ids;
}

void destroyBusiness(BUSINESS u){
	free(u->name);
	free(u->business_id);
	free(u->city);
    free(u->categories);
    free(u->state);
    free(u);
}

void print_business(BUSINESS business){
    printf("Business ID: %s\n",business->business_id );
    printf("Business name: %s\n",business->name);
    printf("Business city: %s\n",business->city);
    printf("Business state: %s\n",business->state);
}