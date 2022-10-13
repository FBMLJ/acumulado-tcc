#define NUMERO_ATRIBUTO 5
typedef struct atributo
{
    int numero_de_valor_distinto;
    int* vetor;
} ATRIBUTO;




typedef struct t_contador{
    int *vetor;
    int tamanho;
    int pos;
    ATRIBUTO *atributo;
} CONTADOR;

typedef struct t_arvore{
    t_arvore **filhos;
    int num_de_filhos;
    int contador_de_elementos;
    t_contador ** contador;
    int id_atributo;


    
} ARVORE;