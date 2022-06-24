#ifndef PROJECT_C_TABLE_H
#define PROJECT_C_TABLE_H
#include "structs_aux.h"

typedef struct table *TABLE;

char** get_business_by_letter_name(TABLE table);
int get_business_by_letter_number(TABLE table);
char** get_business_info(TABLE table);
float get_business_info_stars(TABLE table);
int get_business_info_num_reviews(TABLE table);
char** get_user_review_id(TABLE table);
char** get_user_review_name(TABLE table);
char** get_n_or_more_stars_city_id(TABLE table);
char** get_n_or_more_stars_city_name(TABLE table);
char** get_top_n_business_city_name(TABLE table);
char** get_top_n_business_city_id(TABLE table);
float* get_top_n_business_city_stars(TABLE table);
char** get_n_or_more_category_id(TABLE table);
char** get_n_or_more_category_name(TABLE table);
float* get_n_or_more_category_stars(TABLE table);
char** get_users_id(TABLE table);
int get_num_users_estado_from_table(TABLE table);
char** get_reviews_id(TABLE table);
int get_table_index(TABLE table);
void update_business_by_letter_name(char* name, TABLE table);
void update_business_by_letter_number(int number, TABLE table);
void update_business_info(char* info, TABLE table);
void update_business_info_stars(float stars, TABLE table);
void update_business_info_num_reviews(int reviews, TABLE table);
void update_user_review_id(char* id, TABLE table);
void update_user_review_name(char* name, TABLE table);
void update_n_or_more_stars_city_id(char* id, TABLE table);
void update_n_or_more_stars_city_name(char* name, TABLE table);
void update_top_n_business_city_name(char* name, TABLE table);
void update_top_n_business_city_id(char* id, TABLE table);
void update_top_n_business_city_stars(float stars, TABLE table);
void update_users_id(char* id, TABLE table);
void update_num_users_estado(int number, TABLE table);
void update_n_or_more_category_id(char* id, TABLE table);
void update_n_or_more_category_name(char* name, TABLE table);
void update_n_or_more_category_stars(float stars, TABLE table);
void update_reviews_id(char* id, TABLE table);
void update_table_index(TABLE table);
TABLE init_table_user_review_id();
TABLE init_table_user_review_name();
TABLE init_table_n_or_more_stars_city_id();
TABLE init_table_n_or_more_stars_city_name();
TABLE init_table_n_or_more_cateogry_id();
TABLE init_table_n_or_more_cateogry_name();
TABLE init_table_null();
void free_table(TABLE table);

//Query 2
TABLE init_table_businesses_started_by_letter();
void businesses_by_letter_to_table(char* name, TABLE table);

//Query 3
TABLE init_table_business_info();
void get_name_city_and_state(GHashTable* businesses, char* business_id, TABLE table);
void stars_and_reviews_to_table(TABLE table, BSAUX bsaux);

//Query 4
TABLE init_table_businesses_reviewed();
void get_businesses_reviewed_to_table(GHashTable* reviews, GHashTable* businesses, char* user_id, TABLE table);

//Query 5 
TABLE init_table_n_or_more_stars_city();
void add_to_table(TABLE table, BSCITY newbs);

//query 6
TABLE init_table_top_businesses(int top);
void insert_business_by_stars_to_table(TABLE table, char*bus_name, char* bus_id , float aux);

//query 7
TABLE init_table_users_more_than_one_state(int totalUsersComMaisDeUmState);
void add_userId_by_states_to_table(TABLE table, char* userId);


//Query 8
TABLE init_table_n_or_more_category(int top);
void get_top_businesses(GList* list_stars, TABLE table, int top);


//Query 9 
TABLE init_table_top_reviews_by_word_count(int top);
TABLE table_set_reviews_by_word_count(GList * glist, int top);
#endif