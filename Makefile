build:
	gcc -Wall -g lib/elemento.h lib/lugar.h lib/objeto.h lib/lista_ligada.h \
	lib/lista_ligada.c lib/tabela_espalhamento.h \
	lib/tabela_espalhamento.c main.c -o main

test:
	gcc -Wall -g lib/elemento.h lib/lugar.h lib/objeto.h lib/lista_ligada.h \
	lib/lista_ligada.c lib/tabela_espalhamento.h \
	lib/tabela_espalhamento.c teste.c -o teste

clean:
	rm -f *.out
	rm -f *.h.gch
	rm -f lib/*.out
	rm -f lib/*.h.gch
	rm -f main
	rm -f teste