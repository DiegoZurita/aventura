build:
	gcc -Wall lib/elemento.h lib/lista_ligada.h lib/lista_ligada.c lib/tabela_espalhamento.h lib/tabela_espalhamento.c main.c

clean:
	rm -f *.out
	rm -f *.h.gch
	rm -f lib/*.out
	rm -f lib/*.h.gch
