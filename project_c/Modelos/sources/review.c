#include "../Includes/review.h"

struct review {
    char *review_id;
    char *user_id;
    char *business_id;
    float stars;
    int useful;
    int funny;
    int cool;
    DATA date;
    char *text;
};

char* getReview_Id(REVIEW r){
    return strdup(r->review_id);
}

char* getUser_id(REVIEW r){
    return strdup(r->user_id);
}

float get_review_stars(REVIEW r) {
    return r->stars;
}

char* get_review_business_id(REVIEW r) {
    return strdup(r->business_id);
}

char *get_review_text(REVIEW r){
    return strdup(r->text);
}

void destroyReview(REVIEW r){
    free(r->business_id);
    free(r->date);
    free(r->review_id);
    free(r->text);
    free(r->user_id);

    free(r);
}

REVIEW InitReviewFromLine(char *reviewLinha, char* separador){
    char *review_id = strtok(reviewLinha,separador);
    char *user_id = strtok(NULL,separador);
    char *business_id = strtok(NULL,separador);
    char *stars = strtok(NULL,separador);
    char *useful = strtok(NULL,separador);
    char *funny = strtok(NULL,separador);
    char *cool = strtok(NULL,separador);
    char *date = strtok(NULL,separador);
    char *text = strtok(NULL,separador);

    

    return initReview(review_id, user_id, business_id, stars, useful, funny, cool, date, text);
}

REVIEW initReview(char *review_id, char *user_id, char *business_id, char *stars,
                  char *useful, char *funny, char *cool, char *date, char *text){
    
    REVIEW review = (REVIEW)malloc(sizeof(struct review));
    review->review_id = strdup(review_id);
    review->user_id = strdup(user_id);
    review->business_id = strdup(business_id);
    review->stars = atof(stars);
    review->useful = atoi(useful);
    review->funny = atoi(funny);
    review->cool = atoi(cool); 
    review->date = initData(date);
    review->text = strdup(text);

    return review;
}

void print_review(REVIEW review){
    printf("\n");
    printf("Review ID: %s\n",review->review_id);
    printf("Review USER_ID: %s",review->user_id);
    printf("Review BUSINESS_ID %s",review->business_id);
    printf("Review stars: %f",review->stars);
    printf("Review useful: %d",review->useful);
    printf("Review funny: %d",review->funny);
    printf("Review cool: %d",review->cool);
    //printf("Review date %s",review->)
    printf("Review text%s",review->text);
}


