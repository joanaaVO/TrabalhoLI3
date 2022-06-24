#ifndef PROJECT_C_VIEW_H
#define PROJECT_C_VIEW_H
#include "../Modelos/Includes/table.h"

void menu();
void print_business_info_name(char* name);
void print_business_info_city(char* city);
void print_business_info_state(char* state);
void print_business_info_stars(float stars);
void print_business_info_num_reviews(int reviews);
void show(TABLE table);

#endif