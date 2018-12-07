#include <stdbool.h>

/* Parte específica de Objeto */
typedef struct {
  short int ativo;
  short int visivel;
} Objeto;


/* Parte específica de lugar */
typedef struct lugar {
  struct elemento *Saidas[6];		/* N,S,L,O,C,B */
} Lugar;

typedef struct elemento Elemento;

struct elemento {
    char nome[20];

    char longa[300];

    char curta[100];

    symrec *cont;
    
    int tipo;

    union {
      Objeto obj;
      Lugar lug;
    } Det;

    bool ativo;

    bool visivel;

    bool conhecido;

    bool ehLugar;

    struct lista* conteudo;

    char artigo[10];
 
    int (**acoes)(Elemento* e1, Elemento* e2);

    void (*animacao)();
};

/* Ponteiro para função */
typedef void (*Fptr)(Elemento *, Elemento *);

/* Examinar é usada em mais de um lugar. As outras funções não precisam
   de protótipos aqui, mas poderiam ser colocados
*/
void Examinar(Elemento *, Elemento *);


extern Elemento* Posic;			/* Posição atual */

extern symrec *inventario;		/* O que está com o aventureiro */
