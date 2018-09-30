#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista* criaListaLigada() 
{
    Elo* cabeca = (Elo*) malloc(sizeof(Elo*));
    cabeca->next = NULL;
    cabeca->val = NULL;

    Lista* lista = (Lista*) malloc(sizeof(Lista*));
    lista->cabec = cabeca;

    return lista;
};

void destroiListaLigada(Lista* lista)
{
    Elo* corrente = lista->cabec;

    while (corrente->next != NULL) {
        Elo* temp = corrente->next;
        free(corrente);
        corrente = temp;
    }
};

Lista* insereListaLigada(Lista* lista, Elemento* valor)
{
    Elo* corrente = lista->cabec;
    
    if (corrente->val == NULL && corrente->next == NULL) {
        corrente->val = valor;
        return lista;
    }
    
    Elo* novaCorrente = (Elo*) malloc(sizeof(Elo*));

    while (corrente->next != NULL)
    {
        corrente = corrente->next;
    }

    novaCorrente->val = valor;
    novaCorrente->next = NULL;
    corrente->next = novaCorrente;

    return lista;
};

Elemento* buscaListaLigada(Lista* lista, char* valor)
{
    Elo* corrente = lista->cabec;

    while (corrente->val != NULL) {
        if (strcmp(corrente->val->n, valor) == 0)
            return corrente->val;
        
        corrente = corrente->next;
    }

    return NULL;
};

Elemento* retiraListaLigada(Lista* lista, Elemento* valor) {
    
    Elo* corrente = lista->cabec;
    Elo* anterior = NULL;

    while (strcmp(corrente->val->n, valor->n) != 0) {
        anterior = corrente;
        corrente = corrente->next;
    }

    if (anterior != NULL) {
        anterior->next = corrente->next;
    }
    else {
        lista->cabec = corrente->next;
    }

    return corrente->val;
};