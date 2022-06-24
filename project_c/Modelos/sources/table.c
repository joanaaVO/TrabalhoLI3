#include "../Includes/table.h"
#include <ctype.h>

struct table{
    char** business_by_letter_name;
    int business_by_letter_number;
    char** business_info;
    float business_info_stars;
    int business_info_num_reviews;
    char** user_review_id;
    char** user_review_name;
    char** n_or_more_stars_city_id;
    char** n_or_more_stars_city_name;
    char** top_n_business_city_name;
    char** top_n_business_city_id;
    float* top_n_business_city_stars;
    char** users_id; 
    int num_users_estado;
    char** n_or_more_category_id;
    char** n_or_more_category_name;
    float* n_or_more_category_stars;
    char** reviews_id;
    int index;
};

char** get_business_by_letter_name(TABLE table) {
    if(table->business_by_letter_name == NULL) return NULL;
    int num = get_business_by_letter_number(table);
    int i;
    char** res;
    if(num == 0) res = malloc(sizeof(char*));
    else res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->business_by_letter_name[0]);
        return res;
    }

    for(i=0; i<num; i++) {
        res[i] = strdup(table->business_by_letter_name[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_business_info(TABLE table) {
    if(table->business_info == NULL) return NULL;
    int i;
    char** res = malloc(sizeof(char*) * 4);

    for(i=0; i<3; i++) {
        res[i] = strdup(table->business_info[i]);
    }
    res[i] = NULL;

    return res;
}

float get_business_info_stars(TABLE table) {
    return table->business_info_stars;
}

int get_business_info_num_reviews(TABLE table) {
    return table->business_info_num_reviews;
}

int get_business_by_letter_number(TABLE table) {
    return table->business_by_letter_number;
}

char** get_user_review_id(TABLE table) {
    if(table->user_review_id == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->user_review_id[0]);
        return res;
    }

    for(i=0; table->user_review_id[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->user_review_id[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_user_review_name(TABLE table) {
    if(table->user_review_name == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->user_review_name[0]);
        return res;
    }

    for(i=0; table->user_review_name[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->user_review_name[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_n_or_more_stars_city_id(TABLE table) {
    if(table->n_or_more_stars_city_id == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->n_or_more_stars_city_id[0]);
        return res;
    }

    for(i=0; table->n_or_more_stars_city_id[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->n_or_more_stars_city_id[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_n_or_more_stars_city_name(TABLE table) {
    if(table->n_or_more_stars_city_name == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->n_or_more_stars_city_name[0]);
        return res;
    }

    for(i=0; table->n_or_more_stars_city_name[i]!=NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->n_or_more_stars_city_name[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_top_n_business_city_name(TABLE table) {
    if(table->top_n_business_city_name == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->top_n_business_city_name[0]);
        return res;
    }

    for(i=0; table->top_n_business_city_name[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->top_n_business_city_name[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_top_n_business_city_id(TABLE table) {
    if(table->top_n_business_city_id == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->top_n_business_city_id[0]);
        return res;
    }

    for(i=0; table->top_n_business_city_id[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->top_n_business_city_id[i]);
    }
    res[i] = NULL;

    return res;
}

float* get_top_n_business_city_stars(TABLE table) {
    return table->top_n_business_city_stars;
}

char** get_n_or_more_category_id(TABLE table) {
    if(table->n_or_more_category_id == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->n_or_more_category_id[0]);
        return res;
    }

    for(i=0; table->n_or_more_category_id[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->n_or_more_category_id[i]);
    }
    res[i] = NULL;

    return res;
}

char** get_n_or_more_category_name(TABLE table) {
    if(table->n_or_more_category_name == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->n_or_more_category_name[0]);
        return res;
    }

    for(i=0; table->n_or_more_category_name[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->n_or_more_category_name[i]);
    }
    res[i] = NULL;

    return res;
}

float* get_n_or_more_category_stars(TABLE table) {
    return table->n_or_more_category_stars;
}

char** get_users_id(TABLE table) {
    if(table->users_id == NULL) return NULL;
    int num = get_num_users_estado_from_table(table);
    int i;
    char** res;
    if(num == 0) res = malloc(sizeof(char*));
    else res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->users_id[0]);
        return res;
    }

    for(i=0; i < num; i++) {
        res[i] = strdup(table->users_id[i]);
    }
    res[i] = NULL;

    return res;
}

int get_num_users_estado_from_table(TABLE table){
    return table->num_users_estado;
}

char** get_reviews_id(TABLE table) {
    if(table->reviews_id == NULL) return NULL;
    int num = 10000;
    int i;
    char** res = malloc(sizeof(char*) * num);

    if(table->index == 1) {
        res[0] = strdup(table->reviews_id[0]);
        return res;
    }

    for(i=0; table->reviews_id[i]!= NULL; i++) {
        if(i>=num) {
            num *= 1.5;
            res = realloc(res,sizeof(char*) * num);
        }
        res[i] = strdup(table->reviews_id[i]);
    }
    printf("get reviews %d\n",i);
    res[i] = NULL;

    return res;
}

int get_table_index(TABLE table){
    return table->index;
}

void update_business_by_letter_name(char* name, TABLE table) {
    table->business_by_letter_name[table->index] = strdup(name); 
}

void update_business_by_letter_number(int number, TABLE table) {
    table->business_by_letter_number = number;
}

void update_business_info(char* info, TABLE table) {
    table->business_info[table->index] = strdup(info);
}

void update_business_info_stars(float stars, TABLE table) {
    table->business_info_stars = stars;
}

void update_business_info_num_reviews(int reviews, TABLE table) {
    table->business_info_num_reviews = reviews;
}

void update_user_review_id(char* id, TABLE table) {
    table->user_review_id[table->index] = strdup(id);
}

void update_user_review_name(char* name, TABLE table) {
    table->user_review_name[table->index] = strdup(name);
}

void update_n_or_more_stars_city_id(char* id, TABLE table) {
    table->n_or_more_stars_city_id[table->index] = strdup(id);
}

void update_n_or_more_stars_city_name(char* name, TABLE table) {
    table->n_or_more_stars_city_name[table->index] = strdup(name);
}

void update_top_n_business_city_name(char* name, TABLE table) {
    table->top_n_business_city_name[table->index] = strdup(name);
}

void update_top_n_business_city_id(char* id, TABLE table) {
    table->top_n_business_city_id[table->index] = strdup(id);
}

void update_top_n_business_city_stars(float stars, TABLE table) {
    table->top_n_business_city_stars[table->index] = stars;
}

void update_users_id(char* id, TABLE table) {
    table->users_id[table->index] = strdup(id);
}

void update_num_users_estado(int number, TABLE table) {
    table->num_users_estado = number;
}

void update_n_or_more_category_id(char* id, TABLE table) {
    table->n_or_more_category_id[table->index] = strdup(id);
}

void update_n_or_more_category_name(char* name, TABLE table) {
    table->n_or_more_category_name[table->index] = strdup(name);
}

void update_n_or_more_category_stars(float stars, TABLE table) {
    table->n_or_more_category_stars[table->index] = stars;
}

void update_reviews_id(char* id, TABLE table) {
    table->reviews_id[table->index] = strdup(id);
}

void update_table_index(TABLE table) {
    table->index++;
}

TABLE init_table_user_review_id() {
    TABLE table = init_table_null();
    table->user_review_id = malloc(sizeof(char*));

    return table;
}

TABLE init_table_user_review_name() {
    TABLE table = init_table_null();
    table->user_review_name = malloc(sizeof(char*));

    return table;
}

TABLE init_table_n_or_more_stars_city_id() {
    TABLE table = init_table_null();
    table->n_or_more_stars_city_id = malloc(sizeof(char*));

    return table;
}

TABLE init_table_n_or_more_stars_city_name() {
    TABLE table = init_table_null();
    table->n_or_more_stars_city_name = malloc(sizeof(char*));

    return table;
}

TABLE init_table_n_or_more_cateogry_id() {
    TABLE table = init_table_null();
    table->n_or_more_category_id = malloc(sizeof(char*));

    return table;
}

TABLE init_table_n_or_more_cateogry_name() {
    TABLE table = init_table_null();
    table->n_or_more_category_name = malloc(sizeof(char*));

    return table;
}

//Função que servirá no interpetador como guia para saber quais queries estão na table
TABLE init_table_null() {
    TABLE table = malloc(sizeof(struct table));
    table->business_by_letter_name = NULL;
    table->business_by_letter_number = 0;
    table->business_info = NULL;
    table->business_info_stars = 0;
    table->business_info_num_reviews = 0;
    table->user_review_id = NULL;
    table->user_review_name = NULL;
    table->n_or_more_stars_city_id = NULL;
    table->n_or_more_stars_city_name = NULL;
    table->top_n_business_city_name = NULL;
    table->top_n_business_city_id = NULL;
    table->top_n_business_city_stars = 0;
    table->users_id = NULL; 
    table->num_users_estado = 0;
    table->n_or_more_category_id = NULL;
    table->n_or_more_category_name = NULL;
    table->n_or_more_category_stars = NULL;
    table->reviews_id = NULL;
    table->index = 0; 

    return table;
}

void free_table(TABLE table) {
    int i;
    for(i=0; table->business_by_letter_name[i] != NULL; i++) free(table->business_by_letter_name[i]);
    free(table->business_by_letter_name);
    for(i=0; table->business_info[i] != NULL; i++) free(table->business_info[i]);
    free(table->business_info);
    for(i=0; table->user_review_id[i] != NULL; i++) free(table->user_review_id[i]);
    free(table->user_review_id);
    for(i=0; table->user_review_name[i] != NULL; i++) free(table->user_review_name[i]);
    free(table->user_review_name);
    for(i=0; table->n_or_more_stars_city_id[i] != NULL; i++) free(table->n_or_more_stars_city_id[i]);
    free(table->n_or_more_stars_city_id);
    for(i=0; table->n_or_more_stars_city_name[i] != NULL; i++) free(table->n_or_more_stars_city_name[i]);
    free(table->n_or_more_stars_city_name);
    for(i=0; table->top_n_business_city_name[i] != NULL; i++) free(table->top_n_business_city_name[i]);
    free(table->top_n_business_city_name);
    for(i=0; table->top_n_business_city_id[i] != NULL; i++) free(table->top_n_business_city_id[i]);
    free(table->top_n_business_city_id);
    free(table->top_n_business_city_stars);
    for(i=0; table->users_id[i] != NULL; i++) free(table->users_id[i]);
    free(table->users_id);
    for(i=0; table->n_or_more_category_id[i] != NULL; i++) free(table->n_or_more_category_id[i]);
    free(table->n_or_more_category_id);
    for(i=0; table->n_or_more_category_name[i] != NULL; i++) free(table->n_or_more_category_name[i]);
    free(table->n_or_more_category_name);
    free(table->n_or_more_category_stars);
    for(i=0; table->reviews_id[i] != NULL; i++) free(table->reviews_id[i]);
    free(table->reviews_id);
    free(table);
}

//Funções query 2
TABLE init_table_businesses_started_by_letter() {
    TABLE table = init_table_null();
    table->business_by_letter_name = malloc(sizeof(char*) * 20000);
    table->business_by_letter_number = 0;
    table->index = 0;

    return table;
}

void businesses_by_letter_to_table(char* name, TABLE table) {
    if(table->index >= 20000) {
        table->business_by_letter_name = realloc(table->business_by_letter_name, sizeof(char*) * (table->index * 2));
    } 

    table->business_by_letter_name[table->index] = strdup(name);
    table->business_by_letter_number++;
    table->index++;
    table->business_by_letter_name[table->index] = NULL; 
}

//Funções query 3
TABLE init_table_business_info() {
    TABLE table = init_table_null();
    table->business_info = malloc(sizeof(char*) * 4);

    return table;
}

void get_name_city_and_state(GHashTable* businesses, char* business_id, TABLE table) {
    BUSINESS business = g_hash_table_lookup(businesses, business_id);
    table->business_info[table->index++] = getBusinessName(business);
    table->business_info[table->index++] = getBusinessCity(business);
    table->business_info[table->index++] = getBusinessState(business); 
}

void stars_and_reviews_to_table(TABLE table, BSAUX bsaux) {
    table->business_info_stars = get_business_aux_stars(bsaux);
    table->business_info_num_reviews = get_business_aux_num_reviews(bsaux);
}

//Funções query 4
TABLE init_table_businesses_reviewed() {
    TABLE table = init_table_null();
    table->user_review_name = malloc(sizeof(char*) * 20000);
    table->user_review_id = malloc(sizeof(char*) * 20000);

    return table;
}

void get_businesses_reviewed_to_table(GHashTable* reviews, GHashTable* businesses, char* user_id, TABLE table) {
    GHashTableIter iter;
    gpointer key, value;
    int num = 20000;

     g_hash_table_iter_init (&iter, reviews);
     while (g_hash_table_iter_next (&iter, &key, &value)) {
        REVIEW review = (REVIEW) value;
        char* us_id = getUser_id(review);
        char* bs_id = get_review_business_id(review);

        if(table->index >= num) {
            num *= 2;
            table->user_review_name = realloc(table->user_review_name, sizeof(char*) * num);
            table->user_review_id = realloc(table->user_review_id, sizeof(char*) * num);
        } 

        if(strcmp(us_id, user_id) == 0) {
            BUSINESS business = g_hash_table_lookup(businesses, bs_id);
            char* bs_name = getBusinessName(business);
            table->user_review_name[table->index] = bs_name;
            table->user_review_id[table->index] = bs_id;
            table->index++;
        } 
     }
     table->user_review_name[table->index] = NULL;
     table->user_review_id[table->index] = NULL;

     g_free(key);
     g_free(value);
}

//Funções query 5
TABLE init_table_n_or_more_stars_city() {
    TABLE table = init_table_null();
    table->n_or_more_stars_city_name = malloc(sizeof(char*) * 20000);
    table->n_or_more_stars_city_id = malloc(sizeof(char*) * 20000);
    table->index = 0;

    return table;
}

void add_to_table(TABLE table, BSCITY newbs) {
    BUSINESSESAUX bscity_businesses = get_businesses_aux(newbs);
    GHashTable* businesses = get_businesses_businessesaux(bscity_businesses);

    GHashTableIter iter;
    gpointer key, value;
    int num = 20000;

    g_hash_table_iter_init (&iter, businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BSAUX business = (BSAUX) value;
        char* name = get_business_aux_name(business);
        char* business_id = get_business_aux_id(business);

        if(table->index >= num) {
            num *= 2;
            table->n_or_more_stars_city_name = realloc(table->n_or_more_stars_city_name, sizeof(char*) * num);
            table->n_or_more_stars_city_id = realloc(table->n_or_more_stars_city_id, sizeof(char*) * num);
        } 

        table->n_or_more_stars_city_name[table->index] = name;
        table->n_or_more_stars_city_id[table->index] = business_id;
        table->index++;
    }
    table->n_or_more_stars_city_name[table->index] = NULL;
    table->n_or_more_stars_city_id[table->index] = NULL;

    g_free(key);
    g_free(value);
}

//Funcoes query 6
TABLE init_table_top_businesses(int top){
    TABLE table = init_table_null();
    table->top_n_business_city_name = malloc(sizeof(char *)*top);
    table->top_n_business_city_id = malloc(sizeof(char *)*top);
    table->top_n_business_city_stars= malloc(sizeof(float)*top);
    table->index = 0;
    return table;
}

void insert_business_by_stars_to_table(TABLE table, char*bus_name, char* bus_id , float aux){
    int i = table->index;
    table->top_n_business_city_name[i] = strdup(bus_name);
    table->top_n_business_city_id[i] = strdup(bus_id);
    table->top_n_business_city_stars[i]= aux;
    table->index ++;

}

//Funcoes query 7
TABLE init_table_users_more_than_one_state(int totalUsersComMaisDeUmState){
    TABLE table = init_table_null();
    table->num_users_estado = 0;
    table->index = 0;
    table->users_id = malloc(sizeof(char*) * totalUsersComMaisDeUmState);
    return table;
}

void add_userId_by_states_to_table(TABLE table, char* userId){
    table->users_id[table->num_users_estado] = strdup(userId);
    table->num_users_estado++;
    table->index++;
    table->users_id[table->num_users_estado] = NULL;
}


//Funções query 8
TABLE init_table_n_or_more_category(int top) {
    TABLE table = init_table_null();
    table->n_or_more_category_id = malloc(sizeof(char*) * top);
    table->n_or_more_category_name = malloc(sizeof(char*) * top);
    table->n_or_more_category_stars = malloc(sizeof(float) * top);
    table->index = 0;

    return table;
}

void get_top_businesses(GList* list_stars, TABLE table, int top) {
    GList *l;
    l = list_stars;

    for(int i=0; i<top; i++) {
        BSAUX business = (BSAUX) l->data;
        char* business_id = get_business_aux_id(business);
        char* business_name = get_business_aux_name(business);
        float business_stars = get_business_aux_stars(business);
        table->n_or_more_category_id[table->index] = strdup(business_id);
        table->n_or_more_category_name[table->index] = strdup(business_name);
        table->n_or_more_category_stars[table->index] = business_stars;
        table->index++;
        l = l->next;
    }
    table->n_or_more_category_id[table->index] = NULL;
    table->n_or_more_category_name[table->index] = NULL;
    table->n_or_more_category_stars[table->index] = -1;
}


//Funcoes query 9
TABLE init_table_top_reviews_by_word_count(int top){
    TABLE table = init_table_null();
    table->reviews_id = malloc(sizeof(char*)*top);
    table->index = 0;
    return table;
}

TABLE table_set_reviews_by_word_count(GList * glist, int top){
    TABLE table = init_table_top_reviews_by_word_count(top);
    int i=0;
    while(glist!=NULL){
        GList* next = glist->next;
        REVIEWS_WRD_CNT_AUX reviews_by_wordCount = (REVIEWS_WRD_CNT_AUX)(glist->data);
        int ocorrences = reviews_by_wordCount_getWordCount(reviews_by_wordCount);
        GList * reviews_Ids = g_hash_table_get_keys(reviews_by_wordCount_getReviewsIdsHash(reviews_by_wordCount));
        while(reviews_Ids!=NULL){
            GList *next2 = reviews_Ids->next;
            table->reviews_id[i] = strdup((char *)(reviews_Ids->data));
            reviews_Ids = next2;
            table->index++;
            i++;
            if(i==top) break;
        }
        if(i==top) break;
        glist = next;
    }
    
    table->reviews_id[i] = NULL;
    printf("Inseriu no table %d reviews\n", i);
    return table;

}