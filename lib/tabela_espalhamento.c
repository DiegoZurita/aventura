#include "tabela_espalhamento.h"
#include <stdlib.h>
#include <string.h>

TabSim* cria(int tam) {
    TabSim* tabsim = (TabSim*)malloc(sizeof(TabSim));
    
    tabsim->tamanho = tam;
    tabsim->lista = (Ligacao**)malloc(sizeof(Ligacao*) * tam);
    
    for(int i=0; i<tam; i++)
        tabsim->lista[i] = NULL;
    
    return tabsim;
}

void destroi(TabSim* t) {
    free(t->lista);
    free(t);
}

Elemento* busca(TabSim* t, char* chave) {
    int indice = espalhamento(chave, t->tamanho);
    Ligacao* ligacao = t->lista[indice];

    Ligacao* temp = ligacao;

    while(ligacao) {
        if (strcmp(temp->chave, chave) == 0) {
            return temp->valor;
        }
        temp = temp->proximo;
    }

    return NULL;
}

int espalhamento(char* chave, int tamanhoTabela) {
    if (chave == NULL) {
        return 0;
    }

    int codigoAscii = (int)chave[0];

    return codigoAscii % tamanhoTabela;
}

int retira(TabSim* t, char* chave) {
    int indice = espalhamento(chave, t->tamanho);
    Ligacao* ligacao = t->lista[indice];

    while(ligacao) {
        if (strcmp(ligacao->chave, chave) == 0) {
            ligacao = NULL;
            return 0;
        }

        ligacao = ligacao->proximo;
    }

    return 1;
}

int insere(TabSim* t, char* chave, Elemento* valor) {
    int indice = espalhamento(chave, t->tamanho);
    Ligacao* ligacao = t->lista[indice];
    Ligacao* temp = ligacao;

    // Verifica se a chave já está contida
    while(temp) {
        if (strcmp(temp->chave, chave) == 0) {
            return 1;
        }

        temp = temp->proximo;
    }

    Ligacao* novaLigacao = (Ligacao*)malloc(sizeof(Ligacao));
    novaLigacao->chave = chave;
    novaLigacao->valor = valor;
    novaLigacao->proximo = ligacao;
    t->lista[indice] = novaLigacao;
    return 0;
}