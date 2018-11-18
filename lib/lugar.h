#ifndef LUGAR_H
#define LUGAR_H

#include "elemento.h"

// Inspirado na resposta https://stackoverflow.com/a/888431
typedef struct lugar {
    struct elemento* norte;
    struct elemento* sul;
    struct elemento* leste;
    struct elemento* oeste;
} Lugar;

#endif