#include "lista_ligada.h"


Lista cria() 
{
    Elo* cabeca = (Elo*) malloc(sizeof(Elo));
    cabeca->next = NULL;
    cabeca->val = NULL;

    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->cabec = cabeca;

    return lista;
};

void destroi(Lista lista)
{
    Elo* corrente = lista.cabec;

    while (corrente->next != NULL) {
        Elo* temp = corrente->next;
        free(corrente);
        corrente = temp;
    }
};

Lista insere(Lista lista, Elemento* el)
{
    Elo* corrente = lista.cabec;

    while (corrente->next != NULL)
    {
        corrente = corrente->next;
    }

    corrente->next = el;

    return lista;
};

Elemento* busca(Lista lista, char* valor)
{
    Elo* corrente = lista.cabec;   
    Elemento* encontrado = NULL;

    while (corrente->val != NULL && strcmp(corrente->val->n, valor) != 0) {

        if (corrente->next == NULL)
        {
            break;
        }
        else {
            corrente = corrente->next;
        }
    }

    if (corrente->val != NULL && strcmp(corrente->val->n, valor) == 0)
    {
        encontrado = corrente->val;
    }

    return encontrado;
};

Elemento* retira(Lista lista, Elemento* el) {

    Elo* corrente = lista.cabec;   
    Elo* anterior = NULL;

    while (strcmp(corrente->val->n, valor) != 0) {
        anterior = corrente;
        corrente = corrente->next;
    }

    anterior->next = corrente->next;

    return corrente;
};