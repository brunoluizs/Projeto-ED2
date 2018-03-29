#define TRUE 1
#define FALSE 0

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Evento
{
    char assunto[20];
    char local[20];
    struct Data dataEvento;
    int horario;
};

typedef struct node_Arvore
{
    short int visivel;
    struct Evento info;
    struct node_Arvore *node_Esq;
    struct node_Arvore *node_Dir;
}node_Arvore;
