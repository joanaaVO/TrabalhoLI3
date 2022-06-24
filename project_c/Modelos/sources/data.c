//
// Created by josem on 27/03/2021.
//

#include "../Includes/data.h"

struct data{
    int ano;
    int mes;
    int dia;
    int hora;
    int minutos;
    int segundos;
};

DATA initData (char* data) {
	DATA datax = malloc(sizeof(struct data));
	datax->ano = atoi(strtok(data,"-"));
	datax->mes = atoi(strtok(NULL,"-"));
	datax->dia = atoi(strtok(NULL," "));
	datax->hora = atoi(strtok(NULL,":"));
	datax->minutos = atoi(strtok(NULL,":"));
	datax->segundos = atoi(strtok(NULL,";"));
    
    return datax;
}
