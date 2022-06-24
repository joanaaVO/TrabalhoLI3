#ifndef PROJECT_C_REVIEW_H
#define PROJECT_C_REVIEW_H
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct review *REVIEW;

char* getReview_Id(REVIEW r);
float get_review_stars(REVIEW r);
char* get_review_business_id(REVIEW r);
char* getUser_id(REVIEW r);
char* get_review_text(REVIEW r);
void destroyReview(REVIEW r);
REVIEW InitReviewFromLine(char *reviewLinha, char* separador);
REVIEW initReview(char *review_id, char *user_id, char *business_id, char *stars,
                  char *useful, char *funny, char *cool, char *date, char *text);
void print_review(REVIEW review);

#endif //PROJECT_C_REVIEW_H
