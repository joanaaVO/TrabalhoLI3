#ifndef PROJECT_C_USERS_H
#define PROJECT_C_USERS_H

#include "user.h"
#include "glibWarningAvoid.h"

typedef struct users *USERS;

USERS init_Users();
void InsertUserToUsers(USERS users, USER user);
void destroyUsers(USERS users);
USERS read_users(char* filename);
GHashTable* get_HashTable_users (USERS users);
#endif //PROJECT_C_USERS_H
