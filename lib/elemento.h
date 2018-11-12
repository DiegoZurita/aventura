#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdbool.h>
#include "objeto.h"
#include "lugar.h"

typedef struct {
    char* nome;

    char* longa;

    char* curta;

    bool ativo;

    bool visivel;

    bool conhecido;

    Objeto* conteudo;

    void (**acoes)();

    void (*animacao)();

    union {
        Lugar* lugar;
        Objeto* objeto;
    } detalhe;

} Elemento;
#endif