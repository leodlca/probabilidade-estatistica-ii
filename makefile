gerar_tabela: main.o csv.o stats.o
	gcc -o gerar_tabela main.o csv.o stats.o  -lm

csv.o: csv.c csv.h
	gcc -c csv.c

stats.o: stats.c stats.h
	gcc -c stats.c
        
main.o: main.c
	gcc -c main.c
