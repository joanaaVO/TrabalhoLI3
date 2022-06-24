#ifndef PROJECT_C_STRUCTS_AUX_H
#define PROJECT_C_STRUCTS_AUX_H

#include "businesses.h"
#include "review.h"
typedef struct business_aux *BSAUX;
typedef struct businesses_city *BSCITY;
typedef struct businesses_aux *BUSINESSESAUX;
typedef struct businesses_by_stars *BUSINESSES_BY_STARS;
typedef struct business_by_stars_aux *BUSINESSES_BY_STARS_AUX;
typedef struct reviews_by_wordCount  *REVIEWS_WRD_CNT_AUX;


BSAUX init_business_aux(char *business_id, char *name, float totalstars, float stars, int num_reviews);
void free_business_aux(BSAUX bs);
BUSINESSESAUX init_BusinessesAux();
void free_businesses_aux(BUSINESSESAUX bs);
void insertBusinessToBusinessesAux(BUSINESSESAUX businesses, BSAUX business);
BSCITY init_bscity_with_stars_and_city(float stars, char* city);
BSCITY init_bscity_with_category (char* category);
void free_bscity(BSCITY bs);
char* get_business_aux_id(BSAUX business);
char* get_business_aux_name(BSAUX business);
float get_business_aux_stars(BSAUX business);
int get_business_aux_num_reviews(BSAUX business);

//Query 3
void num_of_stars_and_reviews(GHashTable* reviews, BSAUX bsaux);

//Query 5
void businesses_in_city(GHashTable* businesses, BSCITY bscity);
void updateStars(BSAUX business, float stars);
void num_of_stars_business(GHashTable* reviews, BSCITY bscity);
void get_n_or_more_stars_businesses(BSCITY bscity, BSCITY newbs);

//Query 8
void businesses_in_category(GHashTable* businesses, BSCITY bscity);
GList* get_stars_sorted(BSCITY bscity, GList* list_stars);
GHashTable* get_businesses_businessesaux(BUSINESSESAUX b);
BUSINESSESAUX get_businesses_aux(BSCITY bscity);

//query 6
float getStars_businesses_by_stars(BUSINESSES_BY_STARS bs);
BUSINESSES_BY_STARS_AUX create_business_aux(char* business_id, char* business_name);
BUSINESSES_BY_STARS create_businesses_by_stars(float stars);
GHashTable* getBusinessesAux_by_stars(BUSINESSES_BY_STARS bs);
char * getName_business_by_stars_aux(BUSINESSES_BY_STARS_AUX bs);
char * getBusinessId_business_by_stars_aux(BUSINESSES_BY_STARS_AUX bs);

//Query 9
int reviews_by_wordCount_getWordCount(REVIEWS_WRD_CNT_AUX reviews_by_wordCout);
void reviews_by_wordCount_setWordCount(REVIEWS_WRD_CNT_AUX reviews_by_wordCout, int wordCount);
GHashTable * reviews_by_wordCount_getReviewsIdsHash(REVIEWS_WRD_CNT_AUX reviews_by_wordCount);
void reviews_by_wordCount_sethash_reviews(REVIEWS_WRD_CNT_AUX reviews_by_wordCount, char * review_id);
#endif