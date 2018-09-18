#include "elemento.h"

//Definições das estruturas
typedef struct elo {
    struct elo* next;
    Elemento* val;
} Elo;

typedef struct {
    Elo* cabec;
} Lista;
