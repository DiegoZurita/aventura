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
    strcpy(salaInicio->nome, "Local da negociação Tenda do rei Agamemnon");
    strcpy(salaInicio->longa, "Agamemnon deve aceitar a oferta em ouro ou desafiar a fúria do deus Apolo?");
    strcpy(salaInicio->curta, "Qual das opções??");
    salaInicio->visivel = true;
    salaInicio->conhecido = false;
    salaInicio->ehLugar = false;
    salaInicio->ativo = true;
    salaInicio->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    salaInicio->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    salaInicio->detalhe.saidas->direcoes[0] = NULL;
    salaInicio->detalhe.saidas->direcoes[1] = NULL;
    salaInicio->detalhe.saidas->direcoes[2] = NULL;
    salaInicio->detalhe.saidas->direcoes[3] = NULL;

    //Criando primeira sala
    Elemento* sala1 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala1->nome, "Assembleia dos líderes do exército grego.");
    strcpy(sala1->longa, "Agamemnon deve ceder à pressão de Aquiles e devolver Criseida ou deve recusar a proposta de Aquiles?");
    strcpy(sala1->curta, "Cede ou recusa?");
    sala1->visivel = true;
    sala1->conhecido = false;
    sala1->ehLugar = false;
    sala1->ativo = true;
    sala1->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala1->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    sala1->detalhe.saidas->direcoes[0] = NULL;
    sala1->detalhe.saidas->direcoes[1] = NULL;
    sala1->detalhe.saidas->direcoes[2] = NULL;
    sala1->detalhe.saidas->direcoes[3] = NULL;

    //Criando segunda sala
    Elemento* sala2 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala2->nome, "Campo de batalha.");
    strcpy(sala2->longa, "Agamemnon deve ceder aos apelos dos conselheiros ou enfrentar os troianos sem Aquiles?");
    strcpy(sala2->curta, "Cede ou enfrenta?");
    sala2->visivel = true;
    sala2->conhecido = false;
    sala2->ehLugar = false;
    sala2->ativo = true;
    sala2->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala2->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    sala2->detalhe.saidas->direcoes[0] = NULL;
    sala2->detalhe.saidas->direcoes[1] = NULL;
    sala2->detalhe.saidas->direcoes[2] = NULL;
    sala2->detalhe.saidas->direcoes[3] = NULL;

    //Criando primeira sala
    Elemento* sala3 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala3->nome, "Pŕoximo ao acampamento dos trácios.");
    strcpy(sala3->longa, "Agamemnon deve ignorar os apelos de seus guerreiros e enviá-los à batalha ou deve ouvir as dúvidas de seus guerreiros e não enfrentar os trácios?");
    strcpy(sala3->curta, "Ignora os apelos ou ouve as dúvidas?");
    sala3->visivel = true;
    sala3->conhecido = false;
    sala3->ehLugar = false;
    sala3->ativo = true;
    sala3->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala3->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    sala3->detalhe.saidas->direcoes[0] = NULL;
    sala3->detalhe.saidas->direcoes[1] = NULL;
    sala3->detalhe.saidas->direcoes[2] = NULL;
    sala3->detalhe.saidas->direcoes[3] = NULL;

    void animacaoSala3() {
        printf("~~~ Ventania ~~~~\n");
    }

    sala3->animacao = animacaoSala3;

    //Criando sala 4
    Elemento* sala4 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala4->nome, "Tenda de Aquiles.");
    strcpy(sala4->longa, "Agamemnon deve ignorar o clamor de Zeus ou deve forçar Aquiles à obedecê-lo?");
    strcpy(sala4->curta, "Ignorar ou forçar?");
    sala4->visivel = true;
    sala4->conhecido = false;
    sala4->ehLugar = false;
    sala4->ativo = true;
    sala4->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala4->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    sala4->detalhe.saidas->direcoes[0] = NULL;
    sala4->detalhe.saidas->direcoes[1] = NULL;
    sala4->detalhe.saidas->direcoes[2] = NULL;
    sala4->detalhe.saidas->direcoes[3] = NULL;

    void animacaoSala4() 
    {
        printf("**** Calor ****\n");
    }

    sala4->animacao = animacaoSala4;    

    //Criando sala 5
    Elemento* sala5 = (Elemento*) malloc(sizeof(Elemento));
    strcpy(sala5->nome, "Palácio de Troia.");
    strcpy(sala5->longa, "Agamemnon deve aceitar a negociação de Helena ou deve recusar a negociação de Helena?");
    strcpy(sala5->curta, "Aceitar ou recusar?");
    sala5->visivel = true;
    sala5->conhecido = false;
    sala5->ehLugar = false;
    sala5->ativo = true;
    sala5->detalhe.saidas = (Lugar*)malloc(sizeof(Lugar));
    sala5->detalhe.saidas->direcoes = (Elemento**) malloc(4 * sizeof(Elemento));
    sala5->detalhe.saidas->direcoes[0] = NULL;
    sala5->detalhe.saidas->direcoes[1] = NULL;
    sala5->detalhe.saidas->direcoes[2] = NULL;
    sala5->detalhe.saidas->direcoes[3] = NULL;


    //Criando lista de salas e objetos animados
    Lista* listaDeElementosAnimados = criaListaLigada();
    insereListaLigada(listaDeElementosAnimados, sala4);
    insereListaLigada(listaDeElementosAnimados, sala3);

    //Conectando salas
    salaInicio->detalhe.saidas->direcoes[0] = sala1;
    sala1->detalhe.saidas->direcoes[0] = sala2;
    sala2->detalhe.saidas->direcoes[0] = sala3;
    sala3->detalhe.saidas->direcoes[0] = sala4;
    sala4->detalhe.saidas->direcoes[0] = sala5;

    //Rodando "engine" do jogo
    printf("Após uma disputa entre as deusas gregas Atena, Hera e Afrodite, a deusa Afrodite fez com que Helena, rainha de Esparta, ficasse apaixonada pelo príncipe troiano Paris, que, por sua vez, levou Helena para a cidade de Tróia. O marido de Helena, o rei espartano Menelaus, inconformado, enviou seu irmão, Agamemnon, rei de Micenas, para Troia. O objetivo da expedição de Agamemnon e seu exército era o resgate de Helena e a destruição de Troia. Troia foi cercada por dez anos...\nNo período final da Guerra de Troia, Agamemnon mantém cativa Criseida, filha de Crises, sacerdote de Apolo. Crises oferece ouro e riquezas ao rei Agamemnon em troca de Criseida. Além disso, Crises garante que, caso a oferta seja recusada, diversas pragas recairão sobre o exército grego.\n\n\n");

    printf("Olá %s, você esta em: ", aventureiro->nome);

    Elemento* salaAtual = salaInicio;
    int iteracoes = 0;

    while (salaAtual != NULL) {
        exibeDescricaoApropriada(salaAtual);

        if (iteracoes % 2 == 1) {   
            salaAtual = salaAtual->detalhe.saidas->direcoes[0];
        }
        else {
            salaAtual->conhecido = true;
        }

        executaAnimacoes(listaDeElementosAnimados);
        // printf("----- fim da iteracao %d ------\n", iteracoes);
        printf("\n\n");
        iteracoes++;
    }

    printf("Acabou o jogo!\n");
}