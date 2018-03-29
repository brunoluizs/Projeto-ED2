#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#include "tools.h"
#include "visual.h"

node_Arvore *alocar_node();

void liberar_node(node_Arvore *node);

void encerrar_Arvore(node_Arvore **raiz);

void inserir_node(node_Arvore **raiz, tp_Evento info);

void listar_Arvore(node_Arvore *node);

int abracadabra(node_Arvore *raiz, struct Data data);

node_Arvore *busca_evento(node_Arvore *raiz, tp_Evento evento);

void busca_evento_data(node_Arvore *raiz, struct Data data);

#endif // TREE_H
