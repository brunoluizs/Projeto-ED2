#include "../hdr/control.h"

void run(node_Arvore **raiz)
{
    int op;

    do {
        system("cls");

        menu();

        scanf("%d", &op);

        system("cls");

        switch(op)
        {
            case 1:
            {
                listar_Arvore(*raiz);
                system("pause");
                break;
            }
            case 2:
            {
                struct Evento info;

                visual_get_evento(5);

                get_Evento(&info);

                inserir_node(*(&raiz), info);
                break;
            }
            case 3:
            {
                tp_Evento info;

                visual_get_evento(4);

                get_Evento(&info);

                node_Arvore *cursor = busca_evento(*raiz, info);

                if (cursor == NULL)
                {
                    erro(4);
                    break;
                }

                printf("\n\n");

                visual_get_evento(5);

                get_Evento(&info);

                cursor->info = info;
                break;
            }
            case 4:
            {
                tp_Evento info;

                visual_get_evento(6);

                get_Evento(&info);

                node_Arvore *cursor = busca_evento(*raiz, info);

                if (cursor == NULL)
                {
                    erro(4);
                    break;
                }

                cursor->visivel = FALSE;
                break;

            }
            case 5:
            {
                struct Data data;

                visual_get_evento(7);

                scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

                busca_evento_data(*raiz, data);

                system("pause");

                break;

            }

        }

    } while (op != 0);

    encerrar_Arvore(*(&raiz));
}
