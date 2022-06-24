#include "../Includes/interpretador.h"
#include "../../Modelos/Includes/table.h"
#include <unistd.h>
#include <fcntl.h>
#define MAX_SIZE 500000

//escrita CSV 
void toCSV(TABLE x, char *path, char* delim) {
	FILE *csvFile;
	csvFile = fopen(path,"w+");
	//query2
	printf("QUERY 2\n");
	char **query2 = get_business_by_letter_name(x);
	if(query2!=NULL){
		printf("A escrever query 2 em ficheiro\n");
		fprintf(csvFile,"2.Business_Name; 2.counter\n");
		int totalBusinnesesByLetter = get_business_by_letter_number(x);
		printf("vai escrever %d businesse\n",totalBusinnesesByLetter);
		int i=0;
		while(i<totalBusinnesesByLetter){
			if(i==0) fprintf(csvFile,"%s;%d\n",query2[i], totalBusinnesesByLetter);
			else fprintf(csvFile,"%s; \n",query2[i]);
			i++;
		}
		fclose(csvFile);
		return;
	}

	//query3
	printf("QUERY 3\n");
	char **business_info = get_business_info(x);
	float bus_stars =  get_business_info_stars(x);
	int bus_reviews = get_business_info_num_reviews(x);
	if(business_info!=NULL){
		printf("A escrever query 3 em ficheiro\n");
		fprintf(csvFile,"3.Business_Name; 3.Business_City; 3.Business_State; 3.Business_TotalStars; 3.Business_TotalReviews \n");
		fprintf(csvFile,"%s; %s; %s; %f; %d\n",business_info[0],business_info[1],business_info[2],bus_stars,bus_reviews);
		fclose(csvFile);
		return;
	}

	//query4
	printf("QUERY 4\n");
	char **query4_User_review_id = get_user_review_id(x);
	char **query4_User_review_name = get_user_review_name(x);
	if(query4_User_review_id != NULL && query4_User_review_name != NULL){
		fprintf(csvFile,"4.Business_id; 4.Business_name\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s; %s\n",query4_User_review_id[i],query4_User_review_name[i] );
			i++;
		}
		fclose(csvFile);
		return;
	}

	printf("QUERY 5\n");
	//query5
	char **query5_Business_names = get_n_or_more_stars_city_name(x);
	char **query5_Business_id = get_n_or_more_stars_city_id(x);
	if(query5_Business_names!=NULL && query5_Business_id!=NULL){
		printf("A escrever query 5 em ficheiro\n");
		fprintf(csvFile,"5.Business_ID; 5.Business_Name\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s; %s\n",query5_Business_id[i],query5_Business_names[i] );
			i++;
		}
		fclose(csvFile);
		return;
	}
	//query6
	printf("1\n");
	char **query6_Top_n_business_city_id = get_top_n_business_city_id(x);
	printf("2\n");
	char **query6_Top_n_business_city_name = get_top_n_business_city_name(x);
	printf("3\n");
	float *query6_Top_n_business_city_stars = get_top_n_business_city_stars(x);
	if(query6_Top_n_business_city_id != NULL && query6_Top_n_business_city_name != NULL && query6_Top_n_business_city_stars != NULL){
		printf("Escrever query 6 em ficheiro\n");
		fprintf(csvFile,"6.City_id; 6.City_name; 6.City_stars\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s; %s; %f\n",query6_Top_n_business_city_id[i],query6_Top_n_business_city_name[i],query6_Top_n_business_city_stars[i]);
			i++;
		}
		fclose(csvFile);
		return;
	}



	//query7
	printf("QUERY 7\n");
	char **query7_Users_id = get_users_id(x);
	int query7_num_Users_state = get_num_users_estado_from_table(x);
	if(query7_Users_id != NULL && query7_num_Users_state > 0){
		printf("Escrever query 7 em ficheiro\n");
		fprintf(csvFile,"7.Users_ID;\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s;\n",query7_Users_id[i]);
			i++;
		}
		//fprintf(csvFile,";%d",query7_num_Users_state);
		fclose(csvFile);
		return;
	}

	//query8
	char **query8_N_or_more_category_id = get_n_or_more_category_id(x);	
	char **query8_N_or_more_category_name = get_n_or_more_category_name(x);	
	float *query8_N_or_more_category_stars =  get_n_or_more_category_stars(x);
	
	if(query8_N_or_more_category_id != NULL && query8_N_or_more_category_name != NULL && query8_N_or_more_category_stars != NULL){
		printf("A escrever query 8 em ficheiro\n");
		fprintf(csvFile,"8.Id_category; 8.Name_business; 8.Stars_category\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s; %s; %f\n",query8_N_or_more_category_id[i],query8_N_or_more_category_name[i],query8_N_or_more_category_stars[i]);
			i++;
		}
		fclose(csvFile);
		return;
	}

	//query9
	char **query9_Reviews_id = get_reviews_id(x);
	if(query9_Reviews_id != NULL){
		printf("A escrever query 9 em ficheiro\n");
		fprintf(csvFile,"9.Review_Id\n");
		int i=0;
		int total = get_table_index(x);
		while(i<total){
			fprintf(csvFile,"%s\n",query9_Reviews_id[i]);
			i++;
		}
		printf("%d reviews\n",i);
		fclose(csvFile);
		return;
	}



}

TABLE fromCSV(char *path, char* delim) {
	FILE* fp = fopen(path, "r");

	if(fp == NULL) {
		printf("Ficheiro inválido.\n");
		return NULL;
	}

	TABLE table = init_table_null();
	char* buffer = malloc(sizeof(char) * MAX_SIZE);

	fgets(buffer,MAX_SIZE,fp); //lê o cabeçalho
	char* first = buffer;

	char* line = malloc(sizeof(char) * MAX_SIZE);
	char* word; //cada campo da linha
	int num;
	float numf;

	char* content = strdup(strsep(&first,delim)); //campo do cabeçalho
	char c = content[0];
	switch ((int)(c)) {
		case '2' : 
			table = init_table_businesses_started_by_letter();
		    fgets(buffer,MAX_SIZE,fp);
			line = buffer;
            word = strdup(strsep(&line,delim));
			update_business_by_letter_name(word,table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			num = atoi(word);
			update_business_by_letter_number(num,table);
			update_table_index(table);
			free(word);

		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,"\n"));
			update_business_by_letter_name(word,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '3' :
		table = init_table_business_info();
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_business_info(word,table); //name
			update_table_index(table);
			free(word);
			word = strdup(strsep(&line,delim));
			update_business_info(word,table); //city
			update_table_index(table);
			free(word);
			word = strdup(strsep(&line,delim));
			update_business_info(word,table); //state
			update_table_index(table);
			free(word);
			word = strdup(strsep(&line,delim));
			numf = atof(word);
			update_business_info_stars(numf,table); //stars
			free(word);
			word = strdup(strsep(&line,"\n"));
			num = atoi(word);
			update_business_info_num_reviews(num,table); //reviews
			free(word);
		}
		break;

		case '4' : 
		table = init_table_businesses_reviewed();
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_user_review_id(word,table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			update_user_review_name(word,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '5' :
		table = init_table_n_or_more_stars_city();
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_n_or_more_stars_city_id(word,table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			update_n_or_more_stars_city_name(word,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '6' :
		table = init_table_top_businesses(20000);
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_top_n_business_city_id(word,table);
			free(word);
			word = strdup(strsep(&line,delim));
			update_top_n_business_city_name(word,table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			numf = atof(word);
			update_top_n_business_city_stars(numf,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '7' :
		table = init_table_users_more_than_one_state(20000);
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_users_id(word, table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			int num = atoi(word);
			update_num_users_estado(num,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '8' :
		table = init_table_n_or_more_category(20000);
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,delim));
			update_n_or_more_category_id(word,table);
			free(word);
			word = strdup(strsep(&line,delim));
			update_n_or_more_category_name(word,table);
			free(word);
			word = strdup(strsep(&line,"\n"));
			numf = atof(word);
			update_n_or_more_category_stars(numf,table);
			update_table_index(table);
			free(word);
		}
		break;

		case '9' :
		table = init_table_top_reviews_by_word_count(20000);
		while(fgets(buffer,MAX_SIZE,fp) != NULL) {
			line = buffer;

			word = strdup(strsep(&line,"\n"));
			update_reviews_id(word,table);
			update_table_index(table);
			free(word);
		}
		break;
	}
	fclose(fp);
	free(buffer);
	free(content);

	return table;
}

//Indexação: Aceder a registos/valores contidos numa determinada posição da tabela.
//i : table->index
//j : campo da query
TABLE indice(int i, int j, TABLE table) {
	TABLE result;
	char* content;
	char** qr;
	int num;
	float numf;
	float* qrf;

	if(get_business_by_letter_name(table) != NULL) {
		if(j == 1) {
			result = init_table_null();
			num = get_business_by_letter_number(table);
			update_business_by_letter_number(num, result);
		}
		else if (j == 0) {
			result = init_table_businesses_started_by_letter();
			qr = get_business_by_letter_name(table);
			content = strdup(qr[i]);
			update_business_by_letter_name(content, result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if(get_business_info(table) != NULL) {
		if(j == 4) {
			result = init_table_null();
			num = get_business_info_num_reviews(table);
			update_business_info_num_reviews(num, result);
		}
		else if(j == 3) {
			result = init_table_null();
			numf = get_business_info_stars(table);
			update_business_info_stars(numf, result);
		}
		else if(j == 2) {
			result = init_table_business_info();
			qr = get_business_info(table);
			content = strdup(qr[2]);
			update_business_info("none",result);
			update_table_index(result);
			update_business_info("none",result);
			update_table_index(result);
			update_business_info(content, result);
		}
		else if(j == 1) {
			result = init_table_business_info();
			qr = get_business_info(table);
			content = strdup(qr[1]);
			update_business_info("none", result);
			update_table_index(result);
			update_business_info(content,result);
			update_table_index(result);
			update_business_info("none", result);
		}
		else if(j == 0) {
			result = init_table_business_info();
			qr = get_business_info(table);
			content = strdup(qr[0]);
			update_business_info(content,result);
			update_table_index(result);
			update_business_info("none",result);
			update_table_index(result);
			update_business_info("none",result);
		}
		else return NULL;
	}

	else if(get_user_review_name(table) != NULL) {
		if(j == 1) {
			result = init_table_user_review_name();
			qr = get_user_review_name(table);
			content = strdup(qr[i]);
			update_user_review_name(content, result);
			update_table_index(result);
		}
		else if(j == 0) {
			result = init_table_user_review_id();
			qr = get_user_review_id(table);
			content = strdup(qr[i]);
			update_user_review_id(content,result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if(get_n_or_more_stars_city_name(table) != NULL) {
		if(j == 1) {
			result = init_table_n_or_more_stars_city_name();
			qr = get_n_or_more_stars_city_name(table);
			content = strdup(qr[i]);
			update_n_or_more_stars_city_name(content,result);
			update_table_index(result);
		}
		else if (j == 0) {
			result = init_table_n_or_more_stars_city_id();
			qr = get_n_or_more_stars_city_id(table);
			content = strdup(qr[i]);
			update_n_or_more_stars_city_id(content,result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if(get_top_n_business_city_stars(table) != NULL) {
		//result = init;
		if(j == 2) {
			qrf = get_top_n_business_city_stars(table);
			numf = qrf[i];
			update_top_n_business_city_stars(numf,result);
			update_table_index(result);
		}
		else if(j == 1) {
			qr = get_top_n_business_city_name(table);
			content = strdup(qr[i]);
			update_top_n_business_city_name(content,result);
			update_table_index(result);
		}
		else if (j == 0) {
			qr = get_top_n_business_city_id(table);
			content = strdup(qr[i]);
			update_top_n_business_city_id(content,result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if(get_users_id(table) != NULL) {
		if(j == 1) {
			result = init_table_null();
			num = get_num_users_estado_from_table(table);
			update_num_users_estado(num,result);
		}
		else if (j == 0) {
			result = init_table_users_more_than_one_state(1);
			qr = get_users_id(table);
			content = strdup(qr[i]);
			update_users_id(content,result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if(get_n_or_more_category_id(table) != NULL) {
		if(j == 2) {
			result = init_table_null();
			qrf = get_n_or_more_category_stars(table);
			numf = qrf[i];
			update_n_or_more_category_stars(numf,result);
			update_table_index(result);
		}
		else if (j == 1) {
			result = init_table_n_or_more_cateogry_name();
			qr = get_n_or_more_category_name(table);
			content = strdup(qr[i]);
			update_n_or_more_category_name(content,result);
			update_table_index(result);
		}
		else if (j == 0) {
			result = init_table_n_or_more_cateogry_id();
			qr = get_n_or_more_category_id(table);
			content = strdup(qr[i]);
			update_n_or_more_category_id(content,result);
			update_table_index(result);
		}
		else return NULL;
	}

	else if (get_reviews_id(table) != NULL) {
		result = init_table_top_reviews_by_word_count(1);
		qr = get_reviews_id(table);
		content = strdup(qr[i]);
		update_reviews_id(content,result);
		update_table_index(result);
	}	

	else return NULL;

	return result;
}

TABLE filter(TABLE table, char* column_name, char* value, enum OPERATOR oper) {
	TABLE result = NULL;

	if(strcmp(column_name, "BUSINESS ID") == 0) {
		if(get_user_review_id(table) != NULL) {
			result = init_table_business_info();
			char** ids = get_user_review_id(table);
			char** names = get_user_review_name(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(ids[i],value) < 0) || (oper == 1 && strcmp(ids[i],value) == 0) || (oper == 2 && strcmp(ids[i],value) > 0)) {
					update_user_review_id(ids[i],result);
					update_user_review_name(names[i],result);
					update_table_index(result);

				}
			}

		}

		else if(get_n_or_more_stars_city_id(table) != NULL) {
			result = init_table_n_or_more_stars_city();
			char** ids = get_n_or_more_stars_city_id(table);
			char** names = get_n_or_more_stars_city_name(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(ids[i],value) < 0) || (oper == 1 && strcmp(ids[i],value) == 0) || (oper == 2 && strcmp(ids[i],value) > 0)) {
					update_n_or_more_stars_city_id(ids[i],result);
					update_n_or_more_stars_city_name(names[i],result);
					update_table_index(result);
				}
			}

		}

		else if(get_n_or_more_category_id(table) != NULL) {
			result = init_table_n_or_more_category(20000);
			char** ids = get_n_or_more_category_id(table);
			char** names = get_n_or_more_category_name(table);
			float* stars = get_n_or_more_category_stars(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(ids[i],value) < 0) || (oper == 1 && strcmp(ids[i],value) == 0) || (oper == 2 && strcmp(ids[i],value) > 0)) {
					update_n_or_more_category_id(ids[i], result);
					update_n_or_more_category_name(names[i], result);
					update_n_or_more_category_stars(stars[i], result);
					update_table_index(result);
				}
			}

		}
	}

	else if(strcmp(column_name, "NAME") == 0) {
		if(get_business_by_letter_name(table) != NULL) {
			result = init_table_businesses_started_by_letter();
			char** names = get_business_by_letter_name(table);
			int num = get_business_by_letter_number(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(names[i],value) < 0) || (oper == 1 && strcmp(names[i],value) == 0) || (oper == 2 && strcmp(names[i],value) > 0)) {
					update_business_by_letter_name(names[i], result);
					update_table_index(result);
				}
			}
			update_business_by_letter_number(get_table_index(result), result);

		}

		else if(get_business_info(table) != NULL) return table;

		else if(get_user_review_name(table) != NULL) {
			result = init_table_business_info();
			char** ids = get_user_review_id(table);
			char** names = get_user_review_name(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(names[i],value) < 0) || (oper == 1 && strcmp(names[i],value) == 0) || (oper == 2 && strcmp(names[i],value) > 0)) {
					update_user_review_id(ids[i],result);
					update_user_review_name(names[i],result);
					update_table_index(result);

				}
			}

		}

		else if(get_n_or_more_stars_city_name(table) != NULL) {
			result = init_table_n_or_more_stars_city();
			char** ids = get_n_or_more_stars_city_id(table);
			char** names = get_n_or_more_stars_city_name(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(names[i],value) < 0) || (oper == 1 && strcmp(names[i],value) == 0) || (oper == 2 && strcmp(names[i],value) > 0)) {
					update_n_or_more_stars_city_id(ids[i],result);
					update_n_or_more_stars_city_name(names[i],result);
					update_table_index(result);
				}
			}

		}

		else if(get_n_or_more_category_name(table) != NULL) {
			result = init_table_n_or_more_category(20000);
			char** ids = get_n_or_more_category_id(table);
			char** names = get_n_or_more_category_name(table);
			float* stars = get_n_or_more_category_stars(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && strcmp(names[i],value) < 0) || (oper == 1 && strcmp(names[i],value) == 0) || (oper == 2 && strcmp(names[i],value) > 0)) {
					update_n_or_more_category_id(ids[i], result);
					update_n_or_more_category_name(names[i], result);
					update_n_or_more_category_stars(stars[i], result);
					update_table_index(result);
				}
			}

		}
	}

	else if(strcmp(column_name, "NUMBER OF BUSINESSES")) return table;

	else if(strcmp(column_name, "CITY")) return table;

	else if(strcmp(column_name, "STATE")) return table;

	else if(strcmp(column_name, "STARS")) {
		if(get_business_info_stars(table) != 0) return table;

		else if(get_n_or_more_category_stars(table) != NULL) {
			result = init_table_n_or_more_category(20000);
			char** ids = get_n_or_more_category_id(table);
			char** names = get_n_or_more_category_name(table);
			float* stars = get_n_or_more_category_stars(table);
			int num = get_table_index(table);
			for(int i=0; i<num; i++) {
				if((oper == 0 && stars[i] < atof(value)) || (oper == 1 && stars[i] == atof(value)) || (oper == 2 && stars[i] > atof(value))) {
					update_n_or_more_category_id(ids[i], result);
					update_n_or_more_category_name(names[i], result);
					update_n_or_more_category_stars(stars[i], result);
					update_table_index(result);
				}
			}
		}

	}

	else if(strcmp(column_name, "NUMBER OF BUSINESSES")) return table;

	else if(strcmp(column_name, "NUMBER OF REVIEWS")) return table;

	else if(strcmp(column_name, "USER ID")) {
		result = init_table_users_more_than_one_state(20000);
		char** ids = get_users_id(table);
		int num = get_num_users_estado_from_table(table);
		for(int i=0; i<num; i++) {
			if((oper == 0 && strcmp(ids[i],value) < 0) || (oper == 1 && strcmp(ids[i],value) == 0) || (oper == 2 && strcmp(ids[i],value) > 0)) {
				update_users_id(ids[i], result);
				update_table_index(result);
			}

		}
		update_num_users_estado(get_table_index(result),result);
	}

	else if(strcmp(column_name, "NUMBER OF USERS")) return table;

	else if(strcmp(column_name, "REVIEW ID")) {
		result = init_table_top_reviews_by_word_count(20000);
		char** ids = get_reviews_id(table);
		int num = get_table_index(table);
		for(int i=0; i<num; i++) {
			if((oper == 0 && strcmp(ids[i],value) < 0) || (oper == 1 && strcmp(ids[i],value) == 0) || (oper == 2 && strcmp(ids[i],value) > 0)) {
				update_reviews_id(ids[i], result);
				update_table_index(result);
			}
		}
	}
	return result;
}



