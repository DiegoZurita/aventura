#include <stdio.h>
#include <stdlib.h>
#include "symrec.h"
#include "coisas.h"
#include "avent.tab.h"

/* Variáveis globais */
symrec *sym_table  = (symrec *) 0; /* Tabela de símbolos global */
symrec *inventario = (symrec *) 0; /* material com o aventureiro */
Elemento *Posic    = (Elemento *) 0; /* Posição atual */

/* Objetos  */

Elemento fogo    = {"fogo",   "É uma chama quente e bruxuleante", "uma chama", NULL, OBJ, .Det.obj={1,1}};

Elemento ouro = { "Ouro", "Ouro brilhante", "um ouro dourado", NULL, OBJ, .Det.obj={1,1} };

/* Lugares */

Elemento palacio_troia = {"Palacio Troia", "", "", NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL, NULL}};

Elemento tenda_aquiles = {"Tenda Aquiles", "Heitor é enterrado e a cidade de Troia está em luto. A batalha final aproxima-se. Os gregos conseguem invadir Troia. Agamemnon e Aquiles localizam Helena e Paris. Aquiles deseja duelar Paris, mas Helena intercede e diz que retornará a Menelau, irmão de Agamemnon, se a vida de Paris for poupada.", "Tenda de Aquiles", NULL, LUGAR, .Det.lug.Saidas =  {&palacio_troia, NULL, NULL, NULL, NULL, NULL}};

Elemento acampamento_tracios = {"Acampamento Tracios", "As batalhas continuam. Durante um confronto, o que provoca a fúria de Zeus..", "Acampamento dos trácios", NULL, LUGAR, .Det.lug.Saidas =  {&tenda_aquiles, NULL, NULL, NULL, NULL,NULL}};

Elemento campoDeBatalha = {"Campo de Batalha", "Assembleia dos líderes do exército grego", "Assembleia dos líderes", NULL, LUGAR, .Det.lug.Saidas =  {&acampamento_tracios, NULL, NULL, NULL, NULL, NULL} };

Elemento assembleia = { "Assembleia", "Assembleia dos líderes do exército grego", "Assembleia dos líderes", NULL, LUGAR, .Det.lug.Saidas =  {&campoDeBatalha, NULL, NULL, NULL, NULL, NULL} };

Elemento tendaRei = { "Tenda", "Tenda do rei Agamemnon", "Tenda do Rei", NULL, LUGAR, .Det.lug.Saidas = {&assembleia, NULL, NULL, NULL, NULL, NULL} };


//
// Funções auxiliares
//

/* verifica se um objeto está presente e visível */
/* retorna 1 se no local, 2 se no inventário, 0 se não existir*/
int presente(char *nome) {
  /* inventário? */
  if (getsym(inventario, nome)) return 2;
  if (getsym(Posic->cont, nome)) return 1;
  return 0;
}

/* Implementações dos verbos */

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->Det.obj.ativo
#define Visivel(x) (x)->Det.obj.visivel

/* Transfere um elemento para o inventário */
void Pegar(Elemento *o1, Elemento *o2) {
  if (o1->tipo == LUGAR) {
	puts("Não dá para pegar um lugar!");
	return;
  }

  if (Ativo(o1)) {
	if (Visivel(o1)) {
	  int r = presente(o1->nome);
	  switch (r) {
	  case 2:
		printf("Você já está com %s!\n", o1->nome);
		  return;
	  case 1:
		/* retira do local */
		Posic->cont = popsym(Posic->cont, o1->nome);
		/* insere no inventário */
		inventario = putsym(inventario, o1->nome, OBJ,o1);
		printf("Peguei %s\n", o1->nome);
		return;
	  default:
		printf("Não há %s aqui!\n", o1->nome);
		return;
	  }
	}
	printf("Não consigo ver nenhum %s!\n", o1->nome);
  }
  else
	printf("Não existe %s!!!!\n", o1->nome);
}

/* Transfere do inventário para o local atual */
void Largar(Elemento *o1, Elemento *o2) {
  if (o1->tipo == LUGAR) {
	puts("Largue a mão de ser besta!");
	return;
  }
  if (getsym(inventario, o1->nome)) {
	/* retira do inventario */
	inventario = popsym(inventario, o1->nome);

	/* insere no local */
	Posic->cont = putsym(Posic->cont, o1->nome, OBJ,o1);
	return;
  }
  else {
	/* Em inglês for fun */
	puts("You don't have it");
  }
}

/* Descreve um Elemento em detalhes */
void Examinar(Elemento *o1, Elemento *o2) {
  symrec *ptr;

  /* o default é descrever o local atual */
  if (o1 == NULL || o1 == Posic) {
	puts(Posic->longa);
	puts("Aqui tem:");
	for (ptr = Posic->cont; ptr != (symrec *) 0;
		 ptr = (symrec *)ptr->next) {
	  /* como a lista contém tods os nomes, precisamos filtrar */
	  if (ptr->tipo == OBJ) {
		Elemento *oo = (Elemento *)ptr->value;
		if (Visivel(oo)  && Ativo(oo))
		  printf("\t%s\n", oo->nome);
	  }
	}
	return;
  }
  if (o1->tipo == OBJ)
	if (Ativo(o1) && Visivel(o1))
	  puts(o1->longa);
	else puts("Oi?");
  else
	puts("Não tenho como responder neste momento");
}

/* descrição curta de um elemento, está incompleta */
void Olhar(Elemento *o1, Elemento *o2) {
  if (o1) 
	puts(o1->curta);
  else
	puts(Posic->curta);
}

void Gritar(Elemento *o1, Elemento *o2){
  puts("YEEAAAAAOOOOOWWWGRRUWL");
}

void PegaOuro(Elemento *o1, Elemento *o2) {
  if (presente("ouro")) { 
    puts("Peguei o ouro!");
  }
  Pegar(&ouro, NULL);
}


/* Para inicializar as funções, copiei da calculadora */
struct initfunc {
  char *fname;
  Fptr fnct;
};

/* Lista de verbos */
struct initfunc lfunc[] = {
  {"pegue", Pegar},
  {"cate", Pegar},
  {"largue", Largar },
  {"solte", Largar },
  {"jogue", Largar },
  {"examine", Examinar },
  {"olhe", Olhar },
  {"veja", Olhar },
  {"grite", Gritar },
  {"berre", Gritar },
  {0, 0}
};

/* Para objetos */
struct initobj {
  char *name;
  Elemento *obj;
};

/* Lista de objetos */
struct initobj lobjs[] = {
  {"fogo",  &fogo},
  {"ouro", &ouro},
  { 0, 0 }
};

/* Para lugares */
struct initlug {
  char *name;
  Elemento *lug;
};

/* Lista de lugares */
struct initlug llugs[] = {
  {"tendaRei",       &tendaRei},
  {"assembleia",     &assembleia},
  {"campoDeBatalha", &campoDeBatalha},
  {"acampamento_tracios", &acampamento_tracios},
  {"tenda_aquiles", &tenda_aquiles},
  {"palacio_troia", &palacio_troia},
  { 0, 0}
};

/* Inicializa a tabela de símbolos passada como argumento */
symrec*  init_table(symrec *sym_table)
{
  int i;
  symrec *ptr = sym_table;		/* cabeça da lista */
  /* Lista de verbos */
  for (i = 0; lfunc[i].fname != 0; i++) {
	/* insere */
    ptr = putsym(ptr, lfunc[i].fname, VERBO, lfunc[i].fnct);
	/* completa os dados */
    ptr->value = lfunc[i].fnct;
  }
  /* Lista de objetos */
  for (i = 0; lobjs[i].name != 0; i++) {
	Elemento * oo = lobjs[i].obj;
	/* insere */
    ptr = putsym(ptr, lobjs[i].name, OBJ, oo);
	oo->cont = NULL;
  }

  /* Lista de lugares */
  for (i = 0; llugs[i].name != 0; i++) 
	/* insere */
    ptr = putsym(ptr, llugs[i].name, LUGAR,llugs[i].lug);

  /* Coloca os objetos nos lugares */
  assembleia.cont = putsym(assembleia.cont, "ouro", OBJ, &ouro);
  assembleia.Det.lug.Saidas[1] = &tendaRei;
  campoDeBatalha.Det.lug.Saidas[1] = &assembleia;
  acampamento_tracios.Det.lug.Saidas[1] = &campoDeBatalha;
  tenda_aquiles.Det.lug.Saidas[1] = &acampamento_tracios;
  palacio_troia.Det.lug.Saidas[1] = &tenda_aquiles;

  /* Ajustes finais */
  ouro.cont = putsym(ouro.cont,   "pegue", VERBO, Pegar);

  Posic = &tendaRei;
  /* retorna a nova cabeça da lista */
  return ptr;
}

