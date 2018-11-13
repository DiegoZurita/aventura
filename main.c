#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lugar.h"
#include "lib/elemento.h"

int main() {
    // Introdução inicial da história.
    printf("Créditos: Rafaella, Diego e Ayran.\n\n");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent "
    "vel aliquam leo, non scelerisque nisi. Nullam hendrerit mauris in facilisis "
    "feugiat. Fusce ut imperdiet lacus. Cras convallis non erat nec tempor. Nam "
    "dignissim et libero sed viverra. Ut efficitur nec tortor vitae posuere. "
    "Mauris quam urna, molestie eu lorem non, ornare venenatis magna. Nulla "
    "aliquam lectus ut nibh pulvinar, at facilisis magna congue. Phasellus "
    "suscipit dictum est aliquam ultricies. Fusce et mi eget ipsum sodales "
    "finibus. Nulla aliquam tempor erat quis gravida. Suspendisse vel lorem "
    "neque. Proin sagittis felis eu nulla viverra tincidunt. Nunc ultricies "
    "rutrum velit, sit amet ultrices odio ultrices sit amet. Proin ultrices "
    "dolor a enim imperdiet pulvinar.\n\n Duis viverra elit eu eros maximus "
    "tempor. Proin sagittis laoreet nisi et varius. Sed condimentum, nunc a "
    "mollis molestie, erat tellus pellentesque risus, a aliquet arcu metus "
    "non mi. Curabitur hendrerit nunc est, eu cursus libero feugiat quis. "
    "Suspendisse ullamcorper molestie nibh a tincidunt. Vivamus sed lectus "
    "magna. Nam sit amet risus velit. Morbi sit amet condimentum dui. Donec "
    "nec risus eros. Phasellus placerat, tortor eget convallis mattis, metus dolor "
    "luctus mauris, id sollicitudin mauris erat ac lorem.\n");

    // Inicialização de variáveis importantes.
    Elemento* aventureiro = (Elemento*)malloc(sizeof(Elemento*)); // O aventureiro é um elemento especial.
    strcpy(aventureiro->nome, "Aventureiro");

    Elemento** salas = (Elemento**)malloc(5 * sizeof(Elemento**));

    // Cria 5 salas com 3 objetos cada ligadas umas nas outras em linha reta.
    for (int i = 0; i < 5; i++) {
        salas[i] = (Elemento*)malloc(sizeof(Elemento*));
        snprintf(salas[i]->nome, sizeof("Sala %d"), "Sala %d", i);

        sprintf(salas[i]->curta, "Curta %d", i);

        sprintf(salas[i]->longa, "Longa %d", i);

        salas[i]->ativo = true;
        salas[i]->visivel = true;

        Lugar* lugar = (Lugar*)malloc(sizeof(Lugar*));

        if (i > 0) {
            lugar->saidas = (struct elemento**)malloc(sizeof(struct elemento**));
            lugar->saidas[0] = (struct elemento*)salas[i-1];

            salas[i]->conhecido =false;
        } else {
            lugar->saidas = NULL;
            salas[i]->conhecido = true;
        }

        salas[i]->detalhe.lugar = lugar;

        Elemento** objetosNaSala = (Elemento**)malloc(3 * sizeof(Elemento**));
        for (int j = 0; j < 3; j++) {
            if (i == 0 && j == 0) {
                objetosNaSala[j] = aventureiro;
            } else {
                Elemento* obj = (Elemento*)malloc(sizeof(Elemento*));
                sprintf(obj->nome, "%d/%d", j, i);
                obj->detalhe.objeto = (Objeto*)malloc(sizeof(Objeto*));
                objetosNaSala[j] = obj;
            }
        }
    }

    char* comando = (char*)malloc(30 * sizeof(char*));

    do {
        scanf("%s", comando);
    } while (strcmp(comando, "sair") != 0);

}