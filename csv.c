/* csv.c
 * Arquivo que contem as funcoes de manipulacao do CSV.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"


void write_csv(int prec, int low, int top, double step, int algo, char sep, bool cum){
    FILE * arq;
    int i, j;
    double k;

    if ((arq = fopen("tabela.csv", "w")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo tabela.csv\n");
        exit(1);
    }

    fprintf(arq, "z");

    for(i = 0; i < 10; i++) {
        fprintf(arq, "%c%d", sep, i);
    }

    for(k = low; k + 0.01f < top; k += step) {
        fprintf(arq, "\n%.1f", k);
        for(j = 0; j < 10; j++) {
            fprintf(arq, "%c%.*f", sep, prec, algo == 1 ? z_value_erfc(k + j/100.0, cum) : z_value_simpson_13(k + j/100.0, cum));
        }
    }

    fclose(arq);
}

