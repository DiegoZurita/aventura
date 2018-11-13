#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdbool.h>
#include "objeto.h"
#include "lugar.h"

// Inspirado na resposta https://stackoverflow.com/a/3988056
struct elemento;

typedef struct Elemento Elemento;

struct Elemento {
    char nome[20];

    char longa[300];

    char curta[30];

    bool ativo;

    bool visivel;

    bool conhecido;

    Elemento** conteudo;

    int (**acoes)(Elemento* e1, Elemento* e2);

    void (*animacao)();

    union {
        // Inspirado na resposta https://stackoverflow.com/a/888431
        struct lugar* lugar;
        Objeto* objeto;
    } detalhe;

};
#endif