#ifndef PROJECT_C_USER_H
#define PROJECT_C_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glibWarningAvoid.h"

typedef struct user *USER;

char* getUserName(USER u);
char* getUserID(USER u);
void destroyUser(USER u);
USER InitUserFromLine(char* linha);
USER init_USER(char* user_id, char *nome, GHashTable* amigos);
GHashTable * getStates(USER u);
#endif //PROJECT_C_USER_H
