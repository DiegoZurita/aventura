#include <stdio.h>
#include "symrec.h"

int yyparse();
symrec* init_table();

int main()
{
  /* Monta o mundo */
  sym_table = init_table(sym_table);

  /* Descrição inicial */
  printf("Após uma disputa entre as deusas gregas Atena, Hera e Afrodite, a deusa Afrodite fez com que Helena, rainha de Esparta, ficasse apaixonada pelo príncipe troiano Paris, que, por sua vez, levou Helena para a cidade de Tróia. O marido de Helena, o rei espartano Menelaus, inconformado, enviou seu irmão, Agamemnon, rei de Micenas, para Troia. O objetivo da expedição de Agamemnon e seu exército era o resgate de Helena e a destruição de Troia. Troia foi cercada por dez anos...\n No período final da Guerra de Troia, Agamemnon mantém cativa Criseida, filha de Crises, sacerdote de Apolo. Crises oferece ouro e riquezas ao rei Agamemnon em troca de Criseida. Além disso, Crises garante que, caso a oferta seja recusada, diversas pragas recairão sobre o exército grego..\n\n Você está na Teda do Rei.\n");

  /* Que comece o jogo */
  while (yyparse());
  return 0; 
}






