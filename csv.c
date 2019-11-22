/* csv.c
 * Arquivo que contem as funcoes de manipulacao do CSV.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void write_csv(int prec, int low, int top, double step){
    FILE * arq;
    int i, j;
    double k;

    if ((arq = fopen("tabela.csv", "w")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo tabela.csv\n");
        exit(1);
    }

    fprintf(arq, "z");

    for(i = low; i < 10; i++) {
        fprintf(arq, ";%d", i);
    }

    for(k = 0; k + 0.01f < top; k += step) {
        fprintf(arq, "\n%.1f", k);
        for(j = 0; j < 10; j++) {
            fprintf(arq, ";%.*f", prec, z_value(k + j/100.0));
        }

    }

    fclose(arq);
}
