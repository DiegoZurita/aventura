#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lista_ligada.h"
#include "lib/tabela_espalhamento.h"
#include "lib/objeto.h"

int main() {

    printf("Criando elementos comuns para o teste.\n");
    Elemento* e1 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e1->nome, "e1");

    Elemento* e2 = (Elemento*)malloc(sizeof(Elemento*));
    strcpy(e2->nome, "e2");

    printf("\n");

    // Tabela de espalhamento
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

    // Lista ligada
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

    printf("\n");

    // Objeto
    printf("Testando a struct objeto.\n");
    Objeto* obj = (Objeto*)malloc(sizeof(Objeto*));
    printf("Destruindo a struct objeto.\n");
    free(obj);
    printf("Terminei de testar a struct objeto.\n");    

    printf("\n");

    // Lugar
    printf("Testando a struct lugar.\n");
    Lugar** lugares = (Lugar**)malloc(3 * sizeof(Lugar**));
    for (int i = 0; i < 3; i++) {
        lugares[i] = (Lugar*)malloc(sizeof(Lugar*));
    }

    printf("Destruindo a struct lugares.\n");
    for (int i = 0; i < 3; i++) {
        free(lugares[i]);
    }
    free(lugares);

    printf("Terminei de testar a struct lugar.\n");

    printf("\n");

    // Elemento
    printf("Testando a struct elemento.\n");
    Elemento* elem = (Elemento*)malloc(sizeof(Elemento));

    printf("Atribuindo valores aos atributos da struct elemento.\n");

    strcpy(elem->nome, "Muchacho da Silva");
    strcpy(elem->longa, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam ut leo nec lacus condimentum faucibus vitae vel massa. Proin in nibh quam. Morbi eu sem ut orci ullamcorper posuere.");
    strcpy(elem->curta, "Lorem ipsum dolor sit amet");
    elem->ativo = true;
    elem->visivel = true;
    elem->conhecido = false;
    elem->conteudo = NULL;
    // TODO: Testar os métodos acoes, animacao e a union detalhe.

    printf("Destruindo a struct elemento.\n");
    free(elem);

    printf("Terminei de testar a struct elemento.\n");
    return 0;
}