#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include "elemento.h"

//Definições das estruturas
typedef struct elo {
    struct elo* next;
    struct elemento* val;
} Elo;

typedef struct lista {
    Elo* cabec;
} Lista;

Lista* criaListaLigada();

void destroiListaLigada(Lista* lista);

Lista* insereListaLigada(Lista* lista, struct elemento* valor);

struct elemento* buscaListaLigada(Lista* lista, char* valor);

struct elemento* retiraListaLigada(Lista* lista, struct elemento* valor);
#endif