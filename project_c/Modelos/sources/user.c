#include "../Includes/user.h"

struct user {
    char *user_id;
    char *name;
    GHashTable *friends;
    GHashTable *states;
};

USER InitUserFromLine(char* linhaUser){
    char* linha = linhaUser;
    char *user_id = strdup(strsep(&linha,";"));
    char *name = strdup(strsep(&linha,";"));
    char *buffer = strdup(strsep(&linha,"\n"));
    GHashTable* friends = g_hash_table_new(g_str_hash, g_str_equal);
    char* buf;
    while ((buf = strsep(&buffer,",")) != NULL) {
        g_hash_table_insert(friends, buf, buf);
    }
    free(buffer);
    free(buf);
    
    return init_USER(user_id,name,friends);  
}

USER init_USER(char* user_id, char *nome, GHashTable* amigos){

    USER user = malloc(sizeof(struct user));

    user->user_id =strdup(user_id);
    user->name = strdup(nome);
    user->friends = amigos;
    user->states = g_hash_table_new(g_str_hash, g_str_equal);
    
    free(user_id);
    free(nome);

    return user;
}


char* getUserName(USER u){
	return strdup(u->name);
}

char* getUserID(USER u) {
    return strdup(u->user_id);
}

GHashTable * getStates(USER u){
    return u->states;
}

void destroyUser(USER u){
	free(u->name);
	free(u->user_id);
	free(u->friends);
    free(u);
}