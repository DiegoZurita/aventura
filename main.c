#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lista_ligada.h"
#include "lib/tabela_espalhamento.h"

int main (int argc, char** argv) {

    printf("Criando elementos comuns para o teste.\n");
    Elemento* e1 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e1->nome, "e1");

    Elemento* e2 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e2->nome, "e2");

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
        printf("Exibindo o valor do elemento buscado: %s\n", buscado->nome);
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
    
    printf("\n");

    printf("Testando a lista ligada.\n");
    Lista* l = criaListaLigada();

    printf("Inserindo elementos.\n");
    insereListaLigada(l, e1);
    insereListaLigada(l, e2);

    printf("Buscando elementos.\n");
    Elemento* buscadoListaLigada = buscaListaLigada(l, "e1");

    if (buscadoListaLigada != NULL) {
        printf("Exibindo o valor do elemento buscado: %s\n", buscadoListaLigada->nome);
    } else {
        printf("O ELEMENTO BUSCADO NÃO EXISTE!\n");
    }

    printf("Retirando um elemento.\n");
    retiraListaLigada(l, e1);

    printf("Destruindo a lista ligada.\n");
    destroiListaLigada(l);

    printf("Terminei de testar a lista ligada.\n");

    return 0;
}