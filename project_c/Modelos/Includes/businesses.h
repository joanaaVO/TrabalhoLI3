#ifndef PROJECT_C_BUSINESSES_H
#define PROJECT_C_BUSINESSES_H

#include "glibWarningAvoid.h"
#include "../Includes/business.h"

typedef struct businesses *BUSINESSES;

BUSINESSES init_Businesses();
void InsertBusinessToBusinesses(BUSINESSES businesses, BUSINESS business);
void destroyBusinesses(BUSINESSES businesses);
BUSINESSES read_businesses(char *filename);
GHashTable* get_businesses (BUSINESSES businesses);
GList* get_businesses_by_letter(GHashTable* businesses, GList* list, char letter);

#endif //PROJECT_C_BUSINESSES_H
