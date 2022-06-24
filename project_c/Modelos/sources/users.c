#include "../Includes/users.h"
#define BUFF_SIZE 400000 //tem que se assim grande porque as linhas chegam mesmo a 390 mil de comprimento

struct users {
    GHashTable *users;    
};

USERS init_Users(){
    USERS users = malloc(sizeof(struct users));
    users->users = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroyUser);
    
    return users;
}

void InsertUserToUsers(USERS users, USER user){
    char* user_id = getUserID(user);
    g_hash_table_insert(users->users, user_id, user);
}

void destroyUsers(USERS users) {
    //g_hash_table_destroy (users->users);
    free(users);
}

USERS read_users(char* filename){
	FILE* f = fopen(filename, "r");

	if (f==NULL){
        fprintf(stderr, "Erro ao abrir ficheiro %s\n",filename);
		return NULL;
	}

    USERS users = init_Users();

    char buffer[BUFF_SIZE];
    fgets(buffer,BUFF_SIZE,f);
    while (fgets(buffer,BUFF_SIZE,f)){
        char* userLinha = buffer;

        USER user = InitUserFromLine(userLinha);
        InsertUserToUsers(users,user);
    }
    printf("Lidos %d users\n",g_hash_table_size(users->users));

    fclose(f);

    return users;
}

GHashTable* get_HashTable_users (USERS users) {
    return users->users;
}