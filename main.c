#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/lugar.h"
#include "lib/elemento.h"
#include "lib/lista_ligada.h"


void executaAnimacoes(Lista* listaDeElementosAnimados) {
    Elo* curElementoAnimado = listaDeElementosAnimados->cabec;

    while (curElementoAnimado != NULL) {
        curElementoAnimado->val->animacao();
        curElementoAnimado = curElementoAnimado->next;
    }
}

void exibeDescricaoApropriada(Elemento* salaAtual) {
    if (salaAtual->conhecido) {
        printf("%s\n", salaAtual->curta);
    }
    else {
        printf("%s\n", salaAtual->longa);
    }
}

int main() {
    // Criando aventureiro
    Elemento* aventureiro = (Elemento*)malloc(sizeof(Elemento*)); // O aventureiro é um elemento especial.
    strcpy(aventureiro->nome, "Rei Agamemnon");

    //Criando sala inicial
    Elemento* salaInicio = (Elemento*) malloc(sizeof(Elemento));
    strcpy(salaInicio->nome, "Sala inicio");
    strcpy(salaInicio->longa, "Local da negociação Tenda do rei Agamemnon como descrição longa");
    strcpy(salaInicio->curta, "Local da negociação tenda Agamemnon como descrição curta");
    salaInicio->visivel = true;
    salaInicio->conhecido = false;
    salaInicio->ehLugar = false;
    salaInicio->ativo = true;
    salaInicio->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    salaInicio->detalhe.saidas->norte = NULL;
    salaInicio->detalhe.saidas->sul = NULL;
    salaInicio->detalhe.saidas->leste = NULL;
    salaInicio->detalhe.saidas->oeste = NULL;

    //Criando primeira sala
    Elemento* sala1 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala1->nome, "Sala 1");
    strcpy(sala1->longa, "Assembleia dos líderes do exército grego longa.");
    strcpy(sala1->curta, "Assembleia dos líderes do exército grego curta.");
    sala1->visivel = true;
    sala1->conhecido = false;
    sala1->ehLugar = false;
    sala1->ativo = true;
    sala1->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala1->detalhe.saidas->norte = NULL;
    sala1->detalhe.saidas->sul = NULL;
    sala1->detalhe.saidas->leste = NULL;
    sala1->detalhe.saidas->oeste = NULL;

    //Criando segunda sala
    Elemento* sala2 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala2->nome, "Sala 2");
    strcpy(sala2->longa, "Campo de batalha longa.");
    strcpy(sala2->curta, "Campo de batalha curta.");
    sala2->visivel = true;
    sala2->conhecido = false;
    sala2->ehLugar = false;
    sala2->ativo = true;
    sala2->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala2->detalhe.saidas->norte = NULL;
    sala2->detalhe.saidas->sul = NULL;
    sala2->detalhe.saidas->leste = NULL;
    sala2->detalhe.saidas->oeste = NULL;

    //Criando primeira sala
    Elemento* sala3 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala3->nome, "Sala 3");
    strcpy(sala3->longa, "Pŕoximo ao acampamento dos trácios longa.");
    strcpy(sala3->curta, "Pŕoximo ao acampamento dos trácios curta.");
    sala3->visivel = true;
    sala3->conhecido = false;
    sala3->ehLugar = false;
    sala3->ativo = true;
    sala3->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala3->detalhe.saidas->norte = NULL;
    sala3->detalhe.saidas->sul = NULL;
    sala3->detalhe.saidas->leste = NULL;
    sala3->detalhe.saidas->oeste = NULL;

    void animacaoSala3() {
        printf("Animação sala 3\n");
    }

    sala3->animacao = animacaoSala3;

    //Criando primeira sala
    Elemento* sala4 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala4->nome, "Sala 4");
    strcpy(sala4->longa, "Palácio de Troia longa.");
    strcpy(sala4->curta, "Palácio de Troia curta.");
    sala4->visivel = true;
    sala4->conhecido = false;
    sala4->ehLugar = false;
    sala4->ativo = true;
    sala4->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala4->detalhe.saidas->norte = NULL;
    sala4->detalhe.saidas->sul = NULL;
    sala4->detalhe.saidas->leste = NULL;
    sala4->detalhe.saidas->oeste = NULL;

    void animacaoSala4() 
    {
        printf("Animação sala 4\n");
    }

    sala4->animacao = animacaoSala4;    

    //Criando lista de salas e objetos animados
    Lista* listaDeElementosAnimados = criaListaLigada();
    insereListaLigada(listaDeElementosAnimados, sala4);
    insereListaLigada(listaDeElementosAnimados, sala3);

    //Conectando salas
    salaInicio->detalhe.saidas->norte = sala1;
    sala1->detalhe.saidas->norte = sala2;
    sala2->detalhe.saidas->norte = sala3;
    sala3->detalhe.saidas->norte = sala4;

    //Rodando "engine" do jogo
    printf("Breve introdução da historia\n");

    Elemento* salaAtual = salaInicio;
    int iteracoes = 0;

    while (salaAtual != NULL) {
        exibeDescricaoApropriada(salaAtual);

        if (iteracoes % 2 == 1) {   
            salaAtual = salaAtual->detalhe.saidas->norte;
        }
        else {
            salaAtual->conhecido = true;
        }

        executaAnimacoes(listaDeElementosAnimados);
        printf("----- fim da iteracao %d ------\n", iteracoes);
        iteracoes++;
    }

    printf("Acabou o jogo!\n");
}