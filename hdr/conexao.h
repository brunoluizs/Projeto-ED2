#ifndef CONEXAO_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define CONEXAO_H

#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include "tools.h"
#include <stdlib.h>

MYSQL conexao;
int conecta(char * host, char * usuario, char * senha, char * banco);
void carregaEventos();

#endif
