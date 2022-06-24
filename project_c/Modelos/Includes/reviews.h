#ifndef PROJECT_C_REVIEWS_H
#define PROJECT_C_REVIEWS_H

#include "review.h"
#include "glibWarningAvoid.h"

typedef struct reviews *REVIEWS;
REVIEWS init_Reviews();
void InsertReviewToReviews(REVIEWS reviews, REVIEW review);
void destroyReviews(REVIEWS reviews);
GHashTable* get_reviews_HashTable (REVIEWS reviews);


#endif
