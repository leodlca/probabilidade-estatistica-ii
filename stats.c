/* stats.c
 * Arquivo que contem as funcoes que geram a tabela normal.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include <math.h>
#include <stdbool.h>


long double gaussian_fun(double x) {
    return exp(-pow(x/sqrt(2),2))/sqrt(2*M_PI);
}


long double z_value_erfc(double val, bool cum) {
    long double z = 0.5 * erfc(-val * M_SQRT1_2) - 0.5;
    return cum ? z : z + 0.5;
}


long double z_value_simpson_13(double val, bool cum) {
    long double x=0, y=val;
    long iterations=1500, i=0;

    long double h = (y-x)/iterations;
    long double sum = 0;

    sum += gaussian_fun(x) + gaussian_fun(y);

    for(i=1; i<=(iterations/2); i++) {
        sum += gaussian_fun(x+h*(2*i-1))*4;
    }

    for(i=1; i<=(iterations/2-1); i++) {
        sum += gaussian_fun(x+h*(i*2))*2;
    }

    sum = sum*((y-x)/(3*iterations));

    return cum ? sum : sum + 0.5;
}

