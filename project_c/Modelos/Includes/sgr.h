#ifndef PROJECT_C_SGR_H
#define PROJECT_C_SGR_H
#include <stdio.h>
#include "users.h"
#include "reviews.h"
#include "businesses.h"
#include "table.h"
#include "glibWarningAvoid.h"

typedef struct sgr *SGR;

typedef struct usersComTantosStates {
    int numStates;
    GList *users;
} *USERSCOMTANTOSSTATES;

SGR init_sgr();
void free_sgr(SGR sgr);
REVIEWS read_reviews(SGR sgr, char *filename);
SGR load_sgr(char* UsersFilePath, char* BusinessesFilePath, char* ReviewsFilePath);
BUSINESSES get_sgr_businesses(SGR sgr);
USERS get_sgr_users(SGR sgr);

//Query 2
TABLE businesses_started_by_letter(SGR sgr, char letter);

//Query 3
TABLE business_info(SGR sgr, char *business_id);

//Query 4
TABLE businesses_reviewed(SGR sgr, char *user_id);

//Query 5
TABLE businesses_with_stars_and_city(SGR sgr, float stars, char *city);

//query 6
TABLE top_businesses_by_city(SGR sgr, int top, char *city);

//Query 7
TABLE international_users(SGR sgr);

//Query 8
TABLE top_businesses_with_category(SGR sgr, int top, char *category);

//Query 9
TABLE reviews_with_word(SGR sgr, int top, char *word);
#endif