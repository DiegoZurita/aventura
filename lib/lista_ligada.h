#include "elemento.h"

//Definições das estruturas
typedef struct elo {
    struct elo* next;
    Elemento* val;
} Elo;

typedef struct {
    Elo* cabec;
} Lista;



//Interface das funções
Lista cria();

void destroi(Lista);

Lista insere(Lista, Elemento*);

Elemento* busca(Lista l, char*);

Elemento* retira(Lista, Elemento*);