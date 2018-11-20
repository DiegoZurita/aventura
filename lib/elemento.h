#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdbool.h>
#include "objeto.h"
#include "lugar.h"
#include "lista_ligada.h"

// Inspirado na resposta https://stackoverflow.com/a/3988056

typedef struct elemento Elemento;

struct elemento {
    char nome[20];

    char longa[300];

    char curta[100];

    bool ativo;

    bool visivel;

    bool conhecido;

    struct lista* conteudo;

    char artigo[10];
 
    int (**acoes)(Elemento* e1, Elemento* e2);

    void (*animacao)();

    union {
        // Inspirado na resposta https://stackoverflow.com/a/888431
        struct lugar* saidas;
        Objeto* objeto;
    } detalhe;

    bool ehLugar;
};
#endif