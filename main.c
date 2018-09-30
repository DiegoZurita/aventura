#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lista_ligada.h"
#include "lib/tabela_espalhamento.h"

int main (int argc, char** argv) {

    printf("Criando elementos comuns para o teste.\n");
    Elemento* e1 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e1->n, "e1");

    Elemento* e2 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e2->n, "e2");    

    printf("\n");

    printf("Testando a tabela de espalhamento.\n");
    TabSim* t = cria(10);

    printf("Inserindo os elementos criados.\n");
    if (insere(t, "e1", e1) != 0) {
        printf("PRIMEIRO ELEMENTO NÂO FOI INSERIDO!\n");
    }
    if (insere(t, "e2", e2) != 0) {
        printf("SEGUNDO ELEMENTO NÂO FOI INSERIDO!\n");
    }

    printf("Buscando um elemento.\n");
    Elemento* buscado = busca(t, "e1");

    if (buscado != NULL) {
        printf("Exibindo o valor do elemento buscado: %s\n", buscado->n);
    } else {
        printf("O ELEMENTO BUSCADO NÃO EXISTE!");
    }

    printf("Retirando um elemento.\n");
    if (retira(t, "e1") != 0) {
        printf("PRIMEIRO ELEMENTO NÂO FOI REMOVIDO!\n");
    }

    printf("Destruindo a tabela de espalhamento.\n");
    destroi(t);

    printf("Terminei de testar a tabela de espalhamento.\n");

    return 0;
}