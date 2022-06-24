#ifndef PROJECT_C_BUSINESS_H
#define PROJECT_C_BUSINESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glibWarningAvoid.h"

typedef struct business *BUSINESS;

char* getBusinessID(BUSINESS b);
char* getBusinessName(BUSINESS b);
char* getBusinessCity(BUSINESS bs);
char* getBusinessState(BUSINESS bs);
GHashTable* getBusinessCategories(BUSINESS bs);
GHashTable* getReviewsIds(BUSINESS bs);
void destroyBusiness(BUSINESS u);
BUSINESS InitBusinessFromLine(char *businessLinha);
BUSINESS init_business(char *business_id, char *name, char *city, char *state, GHashTable *categorias);
void print_business(BUSINESS business);
#endif //PROJECT_C_BUSINESS_H
