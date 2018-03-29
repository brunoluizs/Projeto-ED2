#include "../hdr/tree.h"

int Arvore_vazia(node_Arvore *raiz)
{
    return raiz == NULL;
}

node_Arvore *alocar_node()
{
    node_Arvore *node = (node_Arvore*) malloc(sizeof(node_Arvore));

    if (node == NULL)
        /* Erro: memória insuficiente */
        return NULL;

    node->node_Esq = NULL;
    node->node_Dir = NULL;

    node->visivel = FALSE;

    return node;
}

void liberar_node(node_Arvore *node)
{
    if (node == NULL)
        return;

    liberar_node(node->node_Dir);
    liberar_node(node->node_Esq);

    free(node);
}

void liberar_Arvore(node_Arvore *raiz)
{
    if (raiz == NULL)
        return;

    liberar_node(raiz);

    free(raiz);
}

void inserir_node(node_Arvore *node)
{

}

node_Arvore *buscar_node()
{

}
