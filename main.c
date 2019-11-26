/* main.c
 * Interface e arquivo principal do projeto Tabela Normal de PEII.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "csv.h"


void wait_and_clear(int n) {
	int i ;
    printf("Pressione qualquer tecla para continuar... ");
	for(i = 0; i < n; i++){
		getchar();
	}
    system("cls || clear");
}


int main() {
    int low=0, top=0, prec=0, algo=0, cum=0, sep_opt=0;
    char sep=';';
    double step=0.1;

	printf("Tabela Normal\n\n");
	printf("Esse programa gera uma nova tabela normal no mesmo diretorio onde o arquivo executavel esta localizado.\n");
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

	while(true) {
        printf("1 - ERCF\n");
        printf("2 - Simpson 1/3 (pode demorar alguns segundos)\n\n");
        printf("Insira o algoritmo de solucao desejado [1]: ");
		scanf(" %d", &algo);

		if(algo <= 0 || algo >= 3) {
			printf("\nERRO: Opcao invalida selecionada\n\n");
			wait_and_clear(2);
			continue;
		}
		printf("\n");
		wait_and_clear(2);

		break;
	}

	while(true) {
        printf("1 - 0.0 a 0.5\n");
        printf("2 - 0.5 a 1.0\n\n");
        printf("Insira o tipo de tabela desejado [1]: ");
        scanf(" %d", &cum);

        if(cum <= 0 || cum >= 3) {
			printf("\nERRO: Opcao invalida selecionada\n\n");
			wait_and_clear(2);
			continue;
		}
		printf("\n");
		wait_and_clear(2);

		break;
	}

	while(true) {
        printf("1 - ;\n");
        printf("2 - ,\n\n");
        printf("Insira o caractere separador desejado [1]: ");
        scanf(" %d", &sep_opt);

		if(sep_opt == 1){
            sep = ';';
		} else if (sep_opt == 2){
            sep = ',';
		} else {
            printf("\nERRO: Opcao invalida selecionada\n\n");
			wait_and_clear(2);
			continue;
        }
		printf("\n");
		wait_and_clear(2);

		break;
	}

	write_csv(prec, low, top, step, algo, sep, cum == 1);

	printf("Tabela gerada com sucesso! Procure pelo arquivo `tabela.csv` na raiz do projeto ");
	printf("ou no diretorio /bin/Debug.\n\n");

	wait_and_clear(1);

    return 0;
}

