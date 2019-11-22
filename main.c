/* main.c
 * Interface e arquivo principal do projeto Tabela Normal de PEII.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stats.h"


void wait_and_clear(int n) {
	int i ;
    printf("Pressione qualquer tecla para continuar... ");
	for(i = 0; i < n; i++){
		getchar();
	}
    system("cls || clear");
}


int main() {
    int low=0, top=0, prec=0;
    double step=0.1;

	printf("Tabela Normal\n\n");
	printf("Esse programa gera uma nova tabela normal no mesmo diretorio onde o arquivo executavel esta localizado. ");
	printf("A tabela sera armazenada no formato CSV.\n\n");
	printf("OBS: O valor entre colchetes [x] e o valor recomendado para aquela opcao.\n\n");

	wait_and_clear(1);

	while(true) {
		printf("Insira a precisao (numero de casas apos a virgula) desejada [10]: ");
		scanf(" %d", &prec);

		if(prec < 0) {
			printf("\nERRO: Apenas valores >= 0 sao suportados\n\n");
			wait_and_clear(2);
			continue;
		} else if (prec > 10) {
			printf("\nAVISO: Apenas valores <= 10 foram testados e validados, prossiga com cautela.\n");
		}
		printf("\n");
		wait_and_clear(2);

		break;
	}

	while(true) {
        printf("Insira o valor inteiro minimo a ser calculado [0]: ");
		scanf(" %d", &low);

		if(low < 0) {
			printf("\nERRO: Apenas valores >= 0 sao suportados\n\n");
			wait_and_clear(2);
			continue;
		} else if (low > 6) {
			printf("\nAVISO: Apenas valores <= 6 foram testados e validados, prossiga com cautela.\n");
		}
		printf("\n");
		wait_and_clear(2);

		break;
	}

	while(true) {
        printf("Insira o valor inteiro maximo a ser calculado [6]: ");
		scanf(" %d", &top);

		if(top < low) {
			printf("\nERRO: O valor inteiro maximo nao pode ser menor que o valor inteiro minimo\n\n");
			wait_and_clear(2);
			continue;
		} else if (top > 6) {
			printf("\nAVISO: Apenas valores <= 6 foram testados e validados, prossiga com cautela.\n");
		}
		printf("\n");
		wait_and_clear(2);

		break;
	}

	write_csv(prec, low, top, step);

    return 0;
}

