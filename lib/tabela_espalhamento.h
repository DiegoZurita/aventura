#include "elemento.h"

// Estrutura de dados
typedef struct ligacao{
    char* chave;
    void* valor;
    struct ligacao* proximo;
} Ligacao;

typedef struct {
    int tamanho;
    Ligacao** lista;
} TabSim;

// Funções que manipulam a tabela de símbolos
TabSim* cria(int tam);

void destroi(TabSim* t);

int insere(TabSim* t, char* chave, Elemento* valor);

Elemento* busca(TabSim* t, char* chave);

int retira(TabSim* t, char* chave);

// Funções relacionadas ao algoritmo de hash
int espalhamento(char* chave, int tamanhoTabela);