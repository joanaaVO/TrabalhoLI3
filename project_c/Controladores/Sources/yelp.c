#include <stdio.h>
#include <string.h>
#include "../../Modelos/Includes/sgr.h"
#include "../../Modelos/Includes/table.h"
#include "../Includes/interpretador.h"
#include "../../View/view.h"

// Linhas Users: 2189458
// Linhas Business: 160586
// Linhas reviews: 100000

int isSubSequence (char s1[], char s2[]) {
   int i = 0, j = 0;
 
   while (s1[i] != '\0') {
      while (s1[i] != s2[j] && s2[j] != '\0') j++;
      if (s2[j] == '\0') break;
      i++;
      j++;
   }
   if (s1[i] == '\0') return 1;
   
   return 0;
}

int main() {
    
    SGR sgr = load_sgr(NULL,NULL,NULL);
    
    TABLE* list_var = malloc(sizeof(TABLE) * 25); //index: ascii-97
    for(int i=0; i<25; i++) list_var[i] = NULL;

    char* commands = malloc(sizeof(char) * 1000);
    char* iterate; //variável apenas para iterar no strsep
    char variable;
    char* content;
    int i;

    do {
        system("clear");
        menu();
        fgets(commands,1000,stdin);

        while(commands[0]!= '\n' && strncmp(commands,"quit;",5) !=0) {

            if(strncmp(commands,"show",4) == 0 || strncmp(commands,"toCSV",5) == 0) {
                if(strncmp(commands,"show",4) == 0) {
                    content = strdup(strsep(&commands,";"));

                    iterate = strdup(strsep(&content,"("));
                    free(iterate);
                    iterate = strdup(strsep(&content,")"));
                    variable = iterate[0];
                    int ind = (int) (variable-97);
                    show(list_var[ind]);
                }

                else {
                    content = strdup(strsep(&commands,")"));

                    iterate = strdup(strsep(&content,","));
                    variable = iterate[0];
                    int ind = (int) (variable-97);
                    free(iterate);
                    char* delim = strdup(strsep(&content,","));
                    char* filepath = strdup(strsep(&content,")"));
                    toCSV(list_var[ind], delim, filepath);
                    free(delim);
                    free(filepath);
                    iterate = strdup(strsep(&commands,";"));
                    free(iterate);
                }
            }

            else {
                iterate = strdup(strsep(&commands," "));
                variable = iterate[0];
                int ind = (int) (variable-97);
                free(iterate);

                if(strncmp(commands,"= fromCSV",9) == 0) {
                    content = strdup(strsep(&commands,")"));

                    iterate = strdup(strsep(&content,"\""));
                    char* filepath = strdup(strsep(&content,"\""));
                    free(iterate);
                    iterate = strdup(strsep(&content,"'"));
                    free(iterate);
                    char* delim = strdup(strsep(&content,"'"));
                    TABLE table = fromCSV(filepath,delim);
                    list_var[ind] = table;
                    free(filepath);
                    free(delim);
                    iterate = strdup(strsep(&commands,";"));
                    free(iterate);
                }

                else {

                    if(strncmp(commands,"= businesses_started_by_letter",28) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,"\""));
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        char letter = iterate[0];
                        TABLE table = businesses_started_by_letter(sgr,letter);
                        list_var[ind] = table;
                        free(iterate);
                    } 

                    else if(strncmp(commands,"= business_info",15) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,"\""));
                        char* id = strdup(strsep(&content,"\""));
                        TABLE table = business_info(sgr,id);
                        list_var[ind] = table; 
                        free(id);
                        free(iterate);
                    }

                    else if(strncmp(commands,"= businesses_reviewed",21) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,"\""));
                        char* id = strdup(strsep(&content,"\""));
                        TABLE table = businesses_reviewed(sgr,id);
                        list_var[ind] = table;
                        char** names = get_user_review_name(list_var[ind]);
                        char** ids = get_user_review_id(list_var[ind]);
                        free(id);
                        free(iterate);
                    }

                    else if(strncmp(commands,"= businesses_with_stars_and_city",32) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,","));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        float stars = atof(iterate);
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        char* city = strdup(strsep(&content,"\""));
                        TABLE table = businesses_with_stars_and_city(sgr,stars,city);
                        list_var[ind] = table;
                        free(city);
                        free(iterate);
                    }

                    else if(strncmp(commands,"= top_businesses_by_city",24) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,","));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        int top = atoi(iterate);
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        free(iterate);
                        char* city = strdup(strsep(&content,"\""));
                        TABLE table = top_businesses_by_city(sgr,top,city);
                        list_var[ind] = table;
                        free(city);
                    }

                    else if(strncmp(commands,"= international_users",21) == 0) {
                        content = strdup(strsep(&commands,";"));

                        TABLE table = international_users(sgr);
                        list_var[ind] = table;
                    }

                    else if(strncmp(commands,"= top_businesses_with_category",30) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,","));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        int top = atoi(iterate);
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        char* category = strdup(strsep(&content,"\""));
                        TABLE table = top_businesses_with_category(sgr,top,category);
                        list_var[ind] = table;
                        free(category);
                        free(iterate);
                    }

                    else if(strncmp(commands,"= reviews_with_word",19) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,","));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        int top = atoi(iterate);
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        char* word = strdup(strsep(&content,"\""));
                        TABLE table = reviews_with_word(sgr,top,word);
                        list_var[ind] = table;  
                        free(word);
                        free(iterate);
                    }

                    else if(strncmp(commands, "= filter",8) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,"("));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        variable = iterate[0];
                        int ind2 = (int) (variable-97);
                        free(iterate);
                        iterate = strdup(strsep(&content,"\""));
                        free(iterate);
                        char* column_name = strdup(strsep(&content,"\""));
                        iterate = strdup(strsep(&content,"\""));
                        free(iterate);
                        char* value = strdup(strsep(&content,"\""));
                        iterate = strdup(strsep(&content,","));
                        free(iterate);
                        iterate = strdup(strsep(&content,")"));
                        enum OPERATOR oper = atoi(iterate);
                        TABLE table = filter(list_var[ind2], column_name, value, oper);
                        list_var[ind] = table;  
                        free(column_name);
                        free(value);
                        free(iterate);
                        
                    }

                    else if(strncmp(commands, "= proj", 6) == 0) {
                        content = strdup(strsep(&commands,";"));

                        iterate = strdup(strsep(&content,"("));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        variable = iterate[0];
                        int ind = (int) (variable-97);
                        free(iterate);
                        iterate = strdup(strsep(&content,"{"));
                        free(iterate);
                        iterate = strdup(strsep(&content,","));
                        int num1 = atoi(iterate);
                        free(iterate);
                        iterate = strdup(strsep(&content,"}"));
                        int num2 = atoi(iterate);
                        free(iterate);
                        //proj(variable, num1, num2);
                    }

                    else if(isSubSequence("= [][]", content = strdup(strsep(&commands,";")))) {

                        iterate = strdup(strsep(&content,"["));
                        variable = iterate[2];
                        int ind2 = (int) (variable-97);
                        int i = atoi(strdup(strsep(&content,"]")));
                        free(iterate);
                        iterate = strdup(strsep(&content,"["));
                        int j = atoi(strdup(strsep(&content,"]")));
                        TABLE table = indice(i,j,list_var[ind2]);
                        list_var[ind] = table;
                        free(iterate);
                    }

                }
                
            }

        }

    }
    while(strncmp(commands,"quit;",5) != 0);
    free_sgr(sgr);
    
    return 0;
}
