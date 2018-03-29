#include "../hdr/tree.h"

node_Arvore* alocar_node()
{
    node_Arvore *node;

    node = (node_Arvore*) malloc (sizeof(node_Arvore));
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

void liberar_node(node_Arvore *node)
{
    if (node == NULL)
        return;

    liberar_node(node->esq);
    liberar_node(node->dir);

    node->dir = NULL;
    node->esq = NULL;

    free(node);
}

void encerrar_Arvore(node_Arvore **raiz)
{
    if (*raiz == NULL){
        return;
    }

    liberar_node(*raiz);

    free(raiz);

    *raiz = NULL;
}

void inserir_node(node_Arvore **raiz, struct Evento info)
{
    node_Arvore *novo = alocar_node();

    novo->info = info;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->visivel = TRUE;

    if (*raiz == NULL)
        *raiz = novo;

    else
    {
        node_Arvore *cursor = *raiz;
        node_Arvore *anterior;
        int cmp;

        while (cursor != NULL){
            cmp = comparar_datas(cursor->info.dataEvento, novo->info.dataEvento);

            if (cmp == 0) /* data e hora já ocupadas */
            {
                erro(CONFLITO_DATA);
                free(novo);
                return;
            }

            else if (cmp == -1) /* cursor < novo */
            {
                anterior = cursor;
                cursor = cursor->dir;
            }

            else if (cmp == 1) /* cursor > novo */
            {
                anterior = cursor;
                cursor = cursor->esq;
            }


        }
        cursor = novo;

        if (cmp == 1)
            anterior->esq = cursor;


        else if (cmp == -1)
            anterior->dir = cursor;

    }

}

void listar_Arvore(node_Arvore *node) /* Percurso em-ordem. Para listagem geral, o parâmetro será a raiz. */
{
    if (node == NULL){
        return;
    }

    else
    {
        listar_Arvore(node->esq);
        printar_node(node);
        listar_Arvore(node->dir);
    }
}

int abracadabra(node_Arvore *raiz, struct Data data) /* Faz os eventos sumirem! */
{
    node_Arvore *cursor = raiz;
    int cmp;

    while (cursor != NULL){
            cmp = comparar_datas(cursor->info.dataEvento, data);

            if (cmp == 0)
            {
                cursor->visivel = FALSE;
                return 1;
            }

            else if (cmp == -1) /* cursor.data < data */
            {
                cursor = cursor->dir;
            }

            else if (cmp == 1) /* cursor.data > data */
            {
                cursor = cursor->esq;
            }
    }

    return 0;
}

void busca_evento_data(node_Arvore *raiz, struct Data data)
{
    node_Arvore *cursor = raiz;
    int cmp;

    while (cursor != NULL){
            cmp = comparar_datas_sem_hora(cursor->info.dataEvento, data);

            if (cmp == 0)
            {
                printar_node(cursor);
                busca_evento_data(cursor->dir, data);
                busca_evento_data(cursor->esq, data);
                return;
            }

            else if (cmp == -1) /* cursor.data < data */
            {
                cursor = cursor->dir;
            }

            else if (cmp == 1) /* cursor.data > data */
            {
                cursor = cursor->esq;
            }
    }

}

node_Arvore *busca_evento(node_Arvore *raiz, tp_Evento evento)
{
    node_Arvore *cursor = raiz;
    int cmp;

    while (cursor != NULL)
    {
            cmp = comparar_datas(cursor->info.dataEvento, evento.dataEvento);

            if (cmp == 0)
            {
                if (comparar_dados(cursor->info, evento) == 1)
                    return cursor;
                else
                    return NULL;
            }

            else if (cmp == -1) /* cursor.data < data */
            {
                cursor = cursor->dir;
            }

            else if (cmp == 1) /* cursor.data > data */
            {
                cursor = cursor->esq;
            }
    }

    return NULL;
}
