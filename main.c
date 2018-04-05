#include "hdr/control.h"

#include <string.h>

int main()
{
    node_Arvore *raiz = NULL;

    conecta("localhost","root","root","agenda");
    carregaEventos();

    //run(&raiz);

    return 0;
}
