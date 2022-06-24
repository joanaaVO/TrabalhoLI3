#include <stdio.h>
#include "../Includes/reviews.h"
#include "../Includes/sgr.h"
#define BUFF_SIZE 5500

struct reviews {
    GHashTable *reviews;
};

REVIEWS init_Reviews(){
    REVIEWS reviews = malloc(sizeof(struct reviews));
    reviews->reviews = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroyReview);
    return reviews;
}

void InsertReviewToReviews(REVIEWS reviews, REVIEW review){
	char* review_id = getReview_Id(review);
    g_hash_table_insert(reviews->reviews, review_id, review);
}

REVIEWS read_reviews(SGR sgr, char *filename)
{
    FILE *f = fopen(filename, "r");

    if (f == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro %s\n", filename);
        return NULL;
    }

    REVIEWS reviews = init_Reviews();
    char buffer[BUFF_SIZE];
    fgets(buffer, BUFF_SIZE, f);
    int i = 0;
    while (fgets(buffer, BUFF_SIZE, f) != NULL)
    {
        char *reviewLinha = strtok(buffer, "\r\n");

        REVIEW review = InitReviewFromLine(reviewLinha, ";");
        i++;
        InsertReviewToReviews(reviews, review);

        BUSINESS business = (BUSINESS)g_hash_table_lookup(get_businesses(get_sgr_businesses(sgr)), get_review_business_id(review));
        USER user = (USER)g_hash_table_lookup(get_HashTable_users(get_sgr_users(sgr)), getUser_id(review));

        //auxilio query 6 (associar a cada business os seus reviews)
        g_hash_table_insert(getReviewsIds(business),getReview_Id(review),GUINT_TO_POINTER(1));

        //auxilio query 7 (associar a cada user os seus states)
        g_hash_table_insert(getStates(user), strdup(getBusinessState(business)), GUINT_TO_POINTER(1));
    }
    printf("Lidos %d reviews\n", g_hash_table_size(get_reviews_HashTable(reviews)));

    fclose(f);

    return reviews;
}

void destroyReviews(REVIEWS reviews){
	//g_hash_table_destroy (reviews->reviews);
    free(reviews);
}

GHashTable* get_reviews_HashTable (REVIEWS reviews) {
    return reviews->reviews;
}

