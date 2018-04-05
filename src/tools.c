#include "../hdr/tools.h"

void erro(int cod)
{
    switch(cod){
        case CONFLITO_DATA:
            printf("\nE01: Voce ja tem um evento neste horario.\n");
            break;

        case EV_NAO_ENCONTRADO:
            printf("\nE04: Evento nao encontrado!\n");
            break;

        case 5:
            printf("Nao foi possivel estabelecer a conexao.");
            break;

    }

    system("pause");
}

void info(int cod){

    switch(cod){
        case 1:
            printf("Conexao estabelecida com sucesso!\n");
            break;
        case 2:
            printf("Estabelecendo conexao...\n");
            break;

    }
}


int comparar_datas(struct Data input_A, struct Data input_B) /* -1: A < B / 0: A = B / 1: A > B / 2: Erro */
{
    if (input_A.ano == input_B.ano)
    {
        if (input_A.mes == input_B.mes)
        {
            if (input_A.dia == input_B.dia)
            {
                if (input_A.hora < input_B.hora)
                    return -1;

                else if (input_A.hora == input_B.hora)
                    return 0;

                else
                    return 1;
            }


            else if (input_A.dia < input_B.dia)
                return -1;

            else
                return 1;
        }

        else if (input_A.mes < input_B.mes)
            return -1;

        else
            return 1;
    }

    else if (input_A.ano < input_B.ano)
        return -1;

    else
        return 1;

    return 2; /* warning: control reaches end of non-void function */
}

int comparar_datas_sem_hora(struct Data input_A, struct Data input_B) /* -1: A < B / 0: A = B / 1: A > B / 2: Erro */
{
    if (input_A.ano == input_B.ano)
    {
        if (input_A.mes == input_B.mes)
        {
            if (input_A.dia == input_B.dia)
                return 0;

            else if (input_A.dia < input_B.dia)
                return -1;

            else
                return 1;
        }

        else if (input_A.mes < input_B.mes)
            return -1;

        else
            return 1;
    }

    else if (input_A.ano < input_B.ano)
        return -1;

    else
        return 1;

    return 2; /* warning: control reaches end of non-void function */
}

int comparar_dados(struct Evento input_A, struct Evento input_B) /* 1: True / 0: False */
{
    if (strcmp(toupper(input_A.assunto), toupper(input_B.assunto)) == 0 &&
        strcmp(toupper(input_A.local), toupper(input_B.local)) == 0 &&
        comparar_datas(input_A.dataEvento, input_B.dataEvento) == 0)

            return 1;

    return 0;
}

void get_Evento(tp_Evento *info)
{
    visual_get_evento(1); /* Assunto do Evento */
    gets(info->assunto);

    visual_get_evento(2); /* Local do Evento */
    gets(info->local);

    visual_get_evento(3);
    scanf("%d/%d/%d %d", &(*info).dataEvento.dia, &(*info).dataEvento.mes, &(*info).dataEvento.ano, &(*info).dataEvento.hora);
}
