#include "../hdr/visual.h"

void menu()
{
    printf("\tAGENDA DE EVENTOS\n");
    printf("\n[1] Exibir Eventos");
    printf("\n[2] Incluir Evento");
    printf("\n[3] Alterar Evento");
    printf("\n[4] Excluir Evento");
    printf("\n[5] Listar Eventos por Data");

    printf("\n[0] Sair\n");

    printf("\n-> ");
}

void visual_get_evento(int cod)
{
    switch(cod)
    {
        case 1:
            printf("Assunto do Evento: ");
            fflush(stdin);
            break;
        case 2:
            printf("Local do Evento: ");
            fflush(stdin);
            break;
        case 3:
            printf("Data e Hora do Evento [DD/MM/AAAA HH]: ");
            break;
        case 4:
            printf("\tDADOS DO EVENTO A SER ALTERADO\n\n");
            break;
        case 5:
            printf("\tDADOS DO NOVO EVENTO\n\n");
            break;
        case 6:
            printf("\tDADOS DO EVENTO A SER EXCLUIDO\n\n");
            break;
        case 7:
            printf("Data do(s) Evento(s) [DD/MM/AAAA]: ");
            break;
    }
}


void printar_data(struct Data input)
{
    printf("DATA E HORA: %2d/%2d/%4d %2dh\n", input.dia, input.mes, input.ano, input.hora);
}

void printar_node(node_Arvore *node)
{
    if (node->visivel == FALSE)
        return;

    printf("EVENTO:\t%s\n", node->info.assunto);
    printf("LOCAL: \t%s\n", node->info.local);
    printar_data(node->info.dataEvento);
    printf("- - -\n");

}
