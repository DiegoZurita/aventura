#include "elemento.h"

//Definições das estruturas
typedef struct elo {
    struct elo* next;
    Elemento* val;
} Elo;

typedef struct {
    Elo* cabec;
} Lista;

Lista* criaListaLigada();

void destroiListaLigada(Lista lista);

Lista insereListaLigada(Lista lista, Elemento* valor);

Elemento* buscaListaLigada(Lista lista, char* valor);

Elemento* retiraListaLigada(Lista lista, Elemento* valor);