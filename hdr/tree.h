#ifndef _TREE_H_
#define _TREE_H_

#include "../src/struct.c"
#include <stdlib.h>

int Arvore_vazia(node_Arvore *raiz);

node_Arvore *inicializar_Arvore();

void liberar_node(node_Arvore *node);

void liberar_Arvore(node_Arvore *raiz);

void inserir_node(node_Arvore *node);



#endif // _TREE_H_
