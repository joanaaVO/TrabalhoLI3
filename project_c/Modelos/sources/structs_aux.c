#include "../Includes/structs_aux.h"

#include <math.h>

//Structs de apoio às querys 5 e 8
struct business_aux {
    char* business_id;
    char* name;
    float totalstars;
    float stars;
    int num_reviews;
};

struct businesses_aux {
    GHashTable* businesses;
};

struct businesses_city {
    BUSINESSESAUX businesses;
    char* city;
    float stars;
    char* category;
};

BSAUX init_business_aux(char *business_id, char *name, float totalstars, float stars, int num_reviews){
    BSAUX business = malloc(sizeof(struct business_aux));
    business->business_id = strdup(business_id);
    business->name = strdup(name);
    business->totalstars = totalstars;
    business->stars = stars;
    business->num_reviews = num_reviews;

    return business;
}

void free_business_aux(BSAUX bs) {
    free(bs->business_id);
    free(bs->name);
    free(bs);
}

BUSINESSESAUX init_BusinessesAux(){
    BUSINESSESAUX businesses = malloc(sizeof(struct businesses_aux));
    businesses->businesses = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroyBusiness);

    return businesses;
}

void free_businesses_aux(BUSINESSESAUX bs) {
    g_free(bs->businesses);
    free(bs);
}

void insertBusinessToBusinessesAux(BUSINESSESAUX businesses, BSAUX business){
    g_hash_table_insert(businesses->businesses, business->business_id, business);
}

BSCITY init_bscity_with_stars_and_city(float stars, char* city) {
    BSCITY bscity = malloc(sizeof (BSCITY));
    bscity->city = strdup(city);
    bscity->stars = stars;
    BUSINESSESAUX businesses = init_BusinessesAux();
    bscity->businesses = businesses;

    return bscity;
}

BSCITY init_bscity_with_category (char* category) {
    BSCITY bscity = malloc(sizeof (BSCITY));
    bscity->category = strdup(category);
    BUSINESSESAUX businesses = init_BusinessesAux();
    bscity->businesses = businesses;

    return bscity;
}

void free_bscity(BSCITY bs) {
    free_businesses_aux(bs->businesses);
    free(bs->city);
    free(bs->category);
    free(bs);
}

BUSINESSESAUX get_businesses_aux(BSCITY bscity) {
    return bscity->businesses;
}

GHashTable* get_businesses_businessesaux(BUSINESSESAUX b) {
    return b->businesses;
}

char* get_business_aux_id(BSAUX business) {
    return strdup(business->business_id);
}

char* get_business_aux_name(BSAUX business) {
    return strdup(business->name);
}

float get_business_aux_stars(BSAUX business) {
    return business->stars;
}

int get_business_aux_num_reviews(BSAUX business) {
    return business->num_reviews;
}

//Funções query 3
void num_of_stars_and_reviews(GHashTable* reviews, BSAUX bsaux) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, reviews);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        REVIEW review = (REVIEW) value;
        float stars = get_review_stars(review);
        char* business_id = get_review_business_id(review);
        if(strcmp(business_id,bsaux->business_id) == 0) updateStars(bsaux,stars);
    }
    g_free(key);
    g_free(value);
}


//Funções query 5
void businesses_in_city(GHashTable* businesses, BSCITY bscity) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BUSINESS business = (BUSINESS) value;
        BSAUX business_aux = init_business_aux(getBusinessID(business),getBusinessName(business),0,0,0);
        char* city = getBusinessCity(business);
        if(strcmp(city,bscity->city) == 0) insertBusinessToBusinessesAux(bscity->businesses,business_aux);
    }
    g_free(key);
    g_free(value);
}

void updateStars(BSAUX business, float stars) {
    business->totalstars = business->totalstars + stars;
    business->num_reviews++;
    business->stars = business->totalstars/business->num_reviews;
}

void num_of_stars_business(GHashTable* reviews, BSCITY bscity) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, reviews);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        REVIEW review = (REVIEW) value;
        float stars = get_review_stars(review);
        char* business_id = get_review_business_id(review);
        BSAUX business = g_hash_table_lookup(bscity->businesses->businesses, business_id);
        if (business != NULL) updateStars(business,stars);
    }
    g_free(key);
    g_free(value);
}



void get_n_or_more_stars_businesses(BSCITY bscity, BSCITY newbs) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, bscity->businesses->businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BSAUX business = (BSAUX) value;
        if (business->stars >= newbs->stars) insertBusinessToBusinessesAux(newbs->businesses,business);
    }
    g_free(key);
    g_free(value);
}

//structs de apoio query 6
struct business_by_stars_aux {
    char* business_id;
    char* name;
};

char * getBusinessId_business_by_stars_aux(BUSINESSES_BY_STARS_AUX bs){
    return strdup(bs->business_id);
}

char * getName_business_by_stars_aux(BUSINESSES_BY_STARS_AUX bs){
    return strdup(bs->name);
}

struct businesses_by_stars{
    float stars;
    GHashTable *businesses_aux;
};

float getStars_businesses_by_stars(BUSINESSES_BY_STARS bs){
    return bs->stars;
}

GHashTable* getBusinessesAux_by_stars(BUSINESSES_BY_STARS bs){
    return bs->businesses_aux;
}

BUSINESSES_BY_STARS_AUX create_business_aux(char* business_id, char* business_name){
    BUSINESSES_BY_STARS_AUX res = malloc(sizeof(BUSINESSES_BY_STARS_AUX));
    res->business_id =  strdup(business_id);
    res->name = strdup(business_name);
    return res;
}

BUSINESSES_BY_STARS create_businesses_by_stars(float stars){
    BUSINESSES_BY_STARS novo_businesses_by_stars = malloc(sizeof(BUSINESSES_BY_STARS));
    novo_businesses_by_stars->stars = stars;
    novo_businesses_by_stars->businesses_aux = g_hash_table_new(g_str_hash, g_str_equal);
    return novo_businesses_by_stars;
    
}

//Funcões query 8
void businesses_in_category(GHashTable* businesses, BSCITY bscity) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BUSINESS business = (BUSINESS) value;
        BSAUX business_aux = init_business_aux(getBusinessID(business),getBusinessName(business),0,0,0);
        GHashTable* categories = getBusinessCategories(business);
        if (g_hash_table_lookup(categories, bscity->category) != NULL) insertBusinessToBusinessesAux(bscity->businesses,business_aux);
    }
    g_free(key);
    g_free(value);
}

gint stars_compare_func (gconstpointer a, gconstpointer b) {
    BSAUX bs_a = (BSAUX) a;
    BSAUX bs_b = (BSAUX) b;

    return round((bs_b->stars) - (bs_a->stars)); //decrescente
}

GList* get_stars_sorted(BSCITY bscity, GList* list_stars) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init (&iter, bscity->businesses->businesses);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        BSAUX business = (BSAUX) value;
        list_stars = g_list_prepend(list_stars, business);
        list_stars = g_list_sort(list_stars, stars_compare_func);
    }
    g_free(key);
    g_free(value);

    return list_stars;
}

//STRUCT AUX APOIO QUERY 9

struct reviews_by_wordCount{
    int wordCount;
    GHashTable * hash_reviews;
};

int reviews_by_wordCount_getWordCount(REVIEWS_WRD_CNT_AUX reviews_by_wordCount){
    return reviews_by_wordCount->wordCount;
}

GHashTable * reviews_by_wordCount_getReviewsIdsHash(REVIEWS_WRD_CNT_AUX reviews_by_wordCount){
    return reviews_by_wordCount->hash_reviews;
}

void reviews_by_wordCount_setWordCount(REVIEWS_WRD_CNT_AUX reviews_by_wordCount, int wordCount){
    reviews_by_wordCount->wordCount = wordCount;
}

void reviews_by_wordCount_sethash_reviews(REVIEWS_WRD_CNT_AUX reviews_by_wordCount, char * review_id){
    reviews_by_wordCount->hash_reviews = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(reviews_by_wordCount->hash_reviews, strdup(review_id), GUINT_TO_POINTER(1));
}