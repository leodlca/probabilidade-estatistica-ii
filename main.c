/* main.c
 * Interface e arquivo principal do projeto Cobertura Vacinal de PEII.
 *
 * Leonardo Amorim e Luis Durante
 * 27/11/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void wait_and_clear(int n) {
	int i ;
    printf("Pressione qualquer tecla para continuar... ");
	for(i = 0; i < n; i++){
		getchar();
	}
    system("cls || clear");
}


int main() {
    int n = 0;

	printf("Tabela Normal\n\n");
	printf("Esse programa gera uma nova tabela normal no mesmo diretorio onde o arquivo executavel esta localizado. ");
	printf("A tabela sera armazenada no formato CSV, e ela leva aproximadamente 5 minutos para ser gerada, variando ");
	printf("conforme a configuracao do computador.\n\n");
	
	wait_and_clear(1);

	while(true) {
		printf("Insira a precisao (numero de casas apos a virgula) desejada: ");
		scanf(" %d", &n);

		if(n < 0) {
			printf("ERRO: Apenas valores >= 0 sao suportados");
			wait_and_clear(2);
		} else {
			if (n > 10){
				printf("AVISO: Apenas valores <= 10 foram testados e validados, prossiga com cautela.");
				wait_and_clear(2);
			}
			break;
		}
	}

	

    return 0;
}
