#include "view.h"

void menu() {
	
	printf ("\033[0;36m"" \n **************************************************************** ""\033[0m");
    printf ("\033[1m""\n                           BEM-VINDO AO YELP!                         ""\033[0m");
    printf ("\033[0;36m"" \n **************************************************************** ""\033[0m");
    printf ("\033[1m""\n  Atribuição do valor de queries ""\033[0m");
    printf (" \n  sintaxe: x = businesses_started_by_letter(sgr, “A”); ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Visualização de variáveis ""\033[0m"); 
    printf (" \n  sintaxe: show(x); ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Escrita para csv ""\033[0m"); 
    printf (" \n  sintaxe: toCSV(x, delim, filepath); "); 
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Leitura de csv ""\033[0m"); 
    printf (" \n  sintaxe: x = fromCSV(filepath, delim); ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Filtragem de resultados ""\033[0m"); 
    printf (" \n  sintaxe: y = filter(x, column_name, value, oper); ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Projeção de colunas ""\033[0m"); 
    printf (" \n  sintaxe: y = proj(x, cols); ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Indexação ""\033[0m"); 
    printf (" \n  sintaxe: z = x[1][1]; ");
    printf ("\033[0;36m"" \n ---------------------------------------------------------------- ""\033[0m");
    printf ("\033[1m""\n  Terminação ""\033[0m"); 
    printf (" \n  sintaxe: quit; ");
    printf ("\033[0;36m"" \n ----------------------------------------------------------------\n ""\033[0m");
    printf ("\033[1m""\n  Opções:  ""\033[0m");
}

void print_business_info_name(char* name) {
	printf("\033[1m""  %-5s ", "NAME""\033[0m");
	printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");
	printf (" \n  %-60s ", name);
	printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
}

void print_business_info_city(char* city) {
	printf("\033[1m""\n  %-5s ", "CITY""\033[0m");
	printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");
	printf (" \n  %-40s ", city);
	printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
}

void print_business_info_state(char* state) {
	printf("\033[1m""\n  %-6s ", "STATE""\033[0m");
	printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");
	printf (" \n  %-5s ", state);
	printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
}

void print_business_info_stars(float stars) {
	printf("\033[1m""\n  %-6s ", "STARS""\033[0m");
	printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");
	printf (" \n  %-5.2f ", stars);
	printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
}

void print_business_info_num_reviews(int reviews) {
	printf("\033[1m""\n  %-20s ", "NUMBER OF REVIEWS""\033[0m");
	printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");
	printf (" \n  %-10d ", reviews);
	printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
}

void show(TABLE table) {
	system("clear");
	int page = 1;
	int index = 30;
	int set_ind = 1;
	int last_ind;
	char option = 'a';

	if(get_business_by_letter_name(table) != NULL) {
		char** names = get_business_by_letter_name(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;
		int num_bus = get_business_by_letter_number(table);

		if(num_bus == 0) {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s ", "NAME""\033[0m");
				printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-60s ", names[j-1]);

				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		else {
			while(option !='s') {
				system("clear");
				printf("\033[1m""  %-60s %s  %-20s", "NAME", "|", "NUMBER OF BUSINESSES""\033[0m");
				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j<num; j++) { 
					if(j == 1) printf (" \n  %-60s |  %-20d  ", names[j-1],num);
					else printf (" \n  %-60s ", names[j-1]);
				}
				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n       (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}

		}
		
	}

	else if(get_business_by_letter_number(table) != 0) {
		int num = get_business_by_letter_number(table);
		while(option != 's') {
		system("clear");
		printf("\033[1m""  %-20s ", "NUMBER OF BUSINESSES""\033[0m");
		printf ("\033[0;36m"" \n ------------------------------""\033[0m");
		printf (" \n  %-20d ", num);
		printf ("\033[0;36m"" \n ------------------------------""\033[0m");
		printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");
		option = getchar();
		}
	}

	else if(get_business_info(table) != NULL) {
		char** info = get_business_info(table);
		float stars = get_business_info_stars(table);
		int reviews = get_business_info_num_reviews(table);
		int num = get_table_index(table);

		while(option != 's') {

			if(strcmp(info[0],"none") != 0) print_business_info_name(info[0]);

			if(strcmp(info[1],"none") != 0) print_business_info_city(info[1]);

			if(strcmp(info[2],"none") != 0) print_business_info_state(info[2]);

			if(stars != 0) print_business_info_stars(stars);

			if(reviews != 0) print_business_info_num_reviews(reviews);

			printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");

			option = getchar();

		}
	}

	else if(get_business_info_stars(table) != 0) {
		float stars = get_business_info_stars(table);
		int reviews = get_business_info_num_reviews(table);

		while(option != 's') { 

			print_business_info_stars(stars);

			if(reviews != 0) print_business_info_num_reviews(reviews);

			printf ("\033[0;36m"" \n ------------------------------------------------------------""\033[0m");
			printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");

			option = getchar();
		}
	}

	else if(get_business_info_num_reviews(table) != 0) {
		int reviews = get_business_info_num_reviews(table);
		while(option != 's') { 
			system("clear");
			printf("\033[1m""  %-20s ", "NUMBER OF REVIEWS""\033[0m");
			printf ("\033[0;36m"" \n ------------------------------ ""\033[0m");
			printf (" \n  %-20d ", reviews);
			printf ("\033[0;36m"" \n ------------------------------ ""\033[0m");
			printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");
			option = getchar();
		}
	}

	else if(get_user_review_name(table) != NULL) {
		char** names = get_user_review_name(table);
		char** ids = get_user_review_id(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		if(ids == NULL) {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s ", "NAME""\033[0m");
				printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-60s ", names[j-1]);

				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
						system("clear");
						page++;
						set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		else {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s %s  %-60s", "BUSINESS ID", "|", "NAME""\033[0m");
				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s |  %-60s", ids[j-1], names[j-1]);

				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n       (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		
	}

	else if(get_user_review_id(table) != NULL) {
		char** id = get_user_review_id(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		while(option != 's') {
			system("clear");
			printf("\033[1m""  %-30s ", "BUSINESS ID""\033[0m");
			printf ("\033[0;36m"" \n ----------------------------------- ""\033[0m");

			if (page == 1) last_ind = 1;
			else if(j == num) last_ind = ind_last_page-index;
			else last_ind = j-index*2;

			for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s ", id[j-1]);

			printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
			printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

			option = getchar();
			printf("\n");

			if(option == 'p' && j<num) {
				system("clear");
				page++;
				set_ind = j;
			}
			else if(option == 'p' && j>=num) system("clear");

			else if(option == 'a' && page>=2) {
				system("clear");
				page--;
				set_ind = last_ind;
			}
			else if(option == 'a' && page<2) system("clear");
		}	
	}

	else if(get_n_or_more_stars_city_name(table) != NULL) {
		char** names = get_n_or_more_stars_city_name(table);
		char** ids = get_n_or_more_stars_city_id(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		if(ids == NULL) {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s ", "NAME""\033[0m");
				printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-60s ", names[j-1]);

				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		else {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s %s  %-60s", "BUSINESS ID", "|", "NAME""\033[0m");
				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s |  %-60s", ids[j-1], names[j-1]);

				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n       (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}

		}
		
	}

	else if (get_n_or_more_stars_city_id(table) != NULL) {
		char** id = get_n_or_more_stars_city_id(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		while(option != 's') {
			system("clear");
			printf("\033[1m""  %-30s ", "BUSINESS ID""\033[0m");
			printf ("\033[0;36m"" \n ----------------------------------- ""\033[0m");

			if (page == 1) last_ind = 1;
			else if(j == num) last_ind = ind_last_page-index;
			else last_ind = j-index*2;

			for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s ", id[j-1]);

			printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
			printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

			option = getchar();
			printf("\n");

			if(option == 'p' && j<num) {
				system("clear");
				page++;
				set_ind = j;
			}
			else if(option == 'p' && j>=num) system("clear");

			else if(option == 'a' && page>=2) {
				system("clear");
				page--;
				set_ind = last_ind;
			}
			else if(option == 'a' && page<2) system("clear");
		}
	}

	/*else if(get_top_n_business_city_stars(table) != NULL) {
		
	}
	*/

	else if(get_users_id(table) != NULL) {
		char** ids = get_users_id(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;
		int num_users = get_num_users_estado_from_table(table);

		if(num_users == 0) {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s ", "USER ID""\033[0m");
				printf ("\033[0;36m"" \n ----------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s ", ids[j-1]);

				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		else {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s %s  %-10s", "USER ID", "|", "NUMBER OF USERS""\033[0m");
				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) {
					if(j == 1) printf (" \n  %-30s |  %-10d", ids[j-1], num);
					else printf (" \n  %-30s ", ids[j-1]);
				}

				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n       (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
	}

	else if(get_num_users_estado_from_table(table) != 0) {
		int num = get_num_users_estado_from_table(table);
		while(option != 's') {
		system("clear");
		printf("\033[1m""  %-20s ", "NUMBER OF USERS ""\033[0m");
		printf ("\033[0;36m"" \n ------------------------------""\033[0m");
		printf (" \n  %-20d ", num);
		printf ("\033[0;36m"" \n ------------------------------""\033[0m");
		printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");
		option = getchar();
		}
	}

	else if(get_n_or_more_category_id(table) != NULL) {
		char** ids = get_n_or_more_category_id(table);
		char** names = get_n_or_more_category_name(table);
		float* stars = get_n_or_more_category_stars(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		if(names == NULL) {
			if(get_n_or_more_category_stars(table) != NULL) {
				while(option != 's') {
					system("clear");
					printf("\033[1m""  %-30s %s  %-5s", "BUSINESS ID", "|", "STARS""\033[0m");
					printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");

					if (page == 1) last_ind = 1;
					else if(j == num) last_ind = ind_last_page-index;
					else last_ind = j-index*2;

					for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s |  %-5.2f", ids[j-1], stars[j-1]);

					printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------------------- ""\033[0m");
					printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
					printf ("\033[1m""\n  Opção:  ""\033[0m");

					option = getchar();
					printf("\n");

					if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
					}
					else if(option == 'p' && j>=num) system("clear");

					else if(option == 'a' && page>=2) {
						system("clear");
						page--;
						set_ind = last_ind;
					}
					else if(option == 'a' && page<2) system("clear");
				}
			}
			else {
				while(option != 's') {
					system("clear");
					printf("\033[1m""  %-30s ", "BUSINESS ID""\033[0m");
					printf ("\033[0;36m"" \n ----------------------------------- ""\033[0m");

					if (page == 1) last_ind = 1;
					else if(j == num) last_ind = ind_last_page-index;
					else last_ind = j-index*2;

					for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s ", ids[j-1]);

					printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
					printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

					option = getchar();
					printf("\n");

					if(option == 'p' && j<num) {
						system("clear");
						page++;
						set_ind = j;
					}
					else if(option == 'p' && j>=num) system("clear");

					else if(option == 'a' && page>=2) {
						system("clear");
						page--;
						set_ind = last_ind;
					}
					else if(option == 'a' && page<2) system("clear");
				}
			}
			
		}
		else if (stars == NULL) {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s %s  %-60s ", "BUSINESS ID", "|", "NAME""\033[0m");
				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s |  %-60s ", ids[j-1], names[j-1]);

				printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}

		}
		else {
			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s %s  %-60s %s  %-5s", "BUSINESS ID", "|", "NAME", "|", "STARS""\033[0m");
				printf ("\033[0;36m"" \n ------------------------------------------------------------------------------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s |  %-60s |  %-5.2f", ids[j-1], names[j-1], stars[j-1]);

				printf ("\033[0;36m"" \n ------------------------------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
		
	}

	else if (get_n_or_more_category_name(table) != NULL) {
		char** name = get_n_or_more_category_name(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		while(option != 's') {
		system("clear");
		printf("\033[1m""  %-30s ", "NAME""\033[0m");
		printf ("\033[0;36m"" \n ------------------------------------------------------------ ""\033[0m");

		if (page == 1) last_ind = 1;
		else if(j == num) last_ind = ind_last_page-index;
		else last_ind = j-index*2;

		for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-60s ", name[j-1]);

		printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
		printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

		option = getchar();
		printf("\n");

		if(option == 'p' && j<num) {
			system("clear");
			page++;
			set_ind = j;
		}
		else if(option == 'p' && j>=num) system("clear");

		else if(option == 'a' && page>=2) {
			system("clear");
			page--;
			set_ind = last_ind;
		}
		else if(option == 'a' && page<2) system("clear");
		}
	}

	else if (get_n_or_more_category_stars(table) != NULL) {
		float* stars = get_n_or_more_category_stars(table);
		int num = get_table_index(table);
		int ind_last_page;
		if(num == 1) {
			ind_last_page = 1;
			num = 2;
			index = 1;
		}
		else ind_last_page = num/index * index + 1;
		int j = set_ind;

		while(option != 's') {
			system("clear");
			printf("\033[1m""  %-10s ", "STARS""\033[0m");
			printf ("\033[0;36m"" \n ------------------------------ ""\033[0m");

			if (page == 1) last_ind = 1;
			else if(j == num) last_ind = ind_last_page-index;
			else last_ind = j-index*2;

			for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-5.2f ", stars[j-1]);

			printf ("\033[0;36m"" \n -------------------------------------------------------------------------------------------------- ""\033[0m");
			printf ("\033[1m""\n               (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");

			option = getchar();
			printf("\n");

			if(option == 'p' && j<num) {
				system("clear");
				page++;
				set_ind = j;
			}
			else if(option == 'p' && j>=num) system("clear");

			else if(option == 'a' && page>=2) {
				system("clear");
				page--;
				set_ind = last_ind;
			}
			else if(option == 'a' && page<2) system("clear");
		}
	}

	else if (get_reviews_id(table) != NULL) {
		char** reviews = get_reviews_id(table);
		char** ids = get_reviews_id(table);
		int num = get_table_index(table);

		if(num == 1) {
			while(option != 's') {
			system("clear");
			printf("\033[1m""  %-30s ", "REVIEW ID""\033[0m");
			printf ("\033[0;36m"" \n --------------------------------------- ""\033[0m");
			printf (" \n  %-30s ", reviews[0]);
			printf ("\033[0;36m"" \n --------------------------------------- ""\033[0m");
			printf ("\033[1m""\n  PRIMA (s) PARA SAIR : ""\033[0m");
			option = getchar();
			}
		}
		else {
			int ind_last_page = num/index * index + 1;
			int j = set_ind;

			while(option != 's') {
				system("clear");
				printf("\033[1m""  %-30s ", "REVIEW ID""\033[0m");
				printf ("\033[0;36m"" \n --------------------------------------- ""\033[0m");

				if (page == 1) last_ind = 1;
				else if(j == num) last_ind = ind_last_page-index;
				else last_ind = j-index*2;

				for(j = set_ind; j <= index*page && j < num; j++) printf (" \n  %-30s ", ids[j-1]); 

				printf ("\033[0;36m"" \n ----------------------------------------------------------------------------------------- ""\033[0m");
				printf ("\033[1m""\n       (a) PÁGINA ANTERIOR              (s) SAIR              (p) PÁGINA SEGUINTE ""\033[0m");
				printf ("\033[1m""\n  Opção:  ""\033[0m");

				option = getchar();
				printf("\n");

				if(option == 'p' && j<num) {
					system("clear");
					page++;
					set_ind = j;
				}
				else if(option == 'p' && j>=num) system("clear");

				else if(option == 'a' && page>=2) {
					system("clear");
					page--;
					set_ind = last_ind;
				}
				else if(option == 'a' && page<2) system("clear");
			}
		}
	
	}

	else printf("Table inválida.\n");
}