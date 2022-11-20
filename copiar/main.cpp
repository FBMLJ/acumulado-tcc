#include<stdio.h>
#include"util.h"
#include<stdlib.h>


ARVORE *ler_arvore(FILE * f){
    ARVORE * arv = (ARVORE*)malloc(sizeof(ARVORE));
    fread(arv, sizeof(ARVORE),1,f);
    printf("%d\n",arv->id_atributo);
    // não folha
    if (arv->id_atributo != -1){
        printf("numero de filhos %d\n", arv->num_de_filhos);
        
        arv->filhos = (ARVORE**) malloc( sizeof(ARVORE*) * arv->num_de_filhos);
        for(int i = 0;i < arv->num_de_filhos;i++) arv->filhos[i] = ler_arvore(f);
    }
    // folha
    else{
        arv->contador = (CONTADOR**) malloc(sizeof(CONTADOR*) * NUMERO_ATRIBUTO);
         for (int i = 0; i < NUMERO_ATRIBUTO; i++){
            arv->contador[i] = (CONTADOR*) malloc(sizeof(CONTADOR));
            fread(arv->contador[i],sizeof(CONTADOR), 1, f );
            arv->contador[i]->vetor = (int*) malloc(sizeof(int) * arv->contador[i]->tamanho);
            fread(arv->contador[i]->vetor, sizeof(int), arv->contador[i]->tamanho,f);

        }

    }


    return arv;
}

int main(){
    FILE *f = fopen("model.bin", "rb");
    ARVORE * arv = ler_arvore(f);
    fclose(f);

}