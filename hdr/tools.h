#ifndef TOOLS_H
#define TOOLS_H

#define CONFLITO_DATA 1
#define EV_NAO_ENCONTRADO 4

#include <string.h>

#include "../src/struct.c"

void erro(int cod);

int comparar_datas(struct Data input_A, struct Data input_B);

int comparar_datas_sem_hora(struct Data input_A, struct Data input_B);

int comparar_dados(struct Evento input_A, struct Evento input_B);

void get_Evento(tp_Evento *info);

#endif // TOOLS_H
