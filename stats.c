/* stats.c
 * Arquivo que contem as funcoes que geram a tabela normal.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


#include <math.h>


long double z_value(double val) {
    return 0.5 * erfc(-val * M_SQRT1_2) - 0.5;
}

