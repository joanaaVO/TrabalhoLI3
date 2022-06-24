#ifndef PROJECT_C_INTERPRETADOR_H
#define PROJECT_C_INTERPRETADOR_H
#include "../../Modelos/Includes/table.h"

enum OPERATOR{LT, EQ, GT};

TABLE fromCSV(char *path, char* delim);
TABLE indice(int i, int j, TABLE table);
void toCSV(TABLE x, char *path, char* delim);
TABLE filter(TABLE table, char* column_name, char* value, enum OPERATOR oper);

#endif