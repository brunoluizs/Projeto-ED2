#include "../hdr/conexao.h"

int conecta(char * host, char * usuario, char * senha, char * banco){
    //mysql_real_connect(&conexao, "sql3.freemysqlhosting.net", "sql3222753", "XNAw3Payd3", "sql3222753", 0, NULL, 0)

    info(2);
    mysql_init(&conexao);
    if (  mysql_real_connect(&conexao, host, usuario, senha, banco, 0, NULL, 0))
    {
        info(1);
    }
    else
    {
        erro(5);
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        system("PAUSE");
        return(0);
    }
return 1;

}

struct Data sToData(char *sData){
    struct Data data;
    char * pch;

      pch = strtok (sData,"-: ");
      data.ano = atoi(pch);


      pch = strtok (NULL, "-: ");
      data.mes = atoi(pch);

      pch = strtok (NULL, "-: ");
      data.dia = atoi(pch);

      pch = strtok (NULL, "-: ");
      data.hora = atoi(pch);

    return data;
}

void carregaEventos(node_Arvore **raiz){
    char * pch;
    struct Evento evento;
    MYSQL_RES * res;
    MYSQL_ROW * row;
    struct Evento ev;
    char query[200];
    sprintf(query, "select assunto, local, data from agenda.evento where statusreg = 1 order by data");
    mysql_query(&conexao, query);
    res = mysql_store_result(&conexao);

    while( row = mysql_fetch_row(res) )
    {
        //printf("Assunto: %s %s %s\n\n", row[0], row[1], row[2]);
        strcpy(evento.assunto, row[0]);
        strcpy(evento.local, row[1]);
        evento.dataEvento = sToData(row[2]);

      printf("%s %s %d/%d/%d as %d\n", evento.assunto, evento.local, evento.dataEvento.dia, evento.dataEvento.mes, evento.dataEvento.ano, evento.dataEvento.hora);
      inserir_node(*(&raiz), evento);

    }

}

