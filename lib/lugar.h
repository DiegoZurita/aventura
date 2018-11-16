#ifndef LUGAR_H
#define LUGAR_H

#include "elemento.h"

// Inspirado na resposta https://stackoverflow.com/a/888431
struct lugar;

typedef struct lugar {
    struct elemento** saidas;
} Lugar;

#endif