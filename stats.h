/* stats.h
 * Arquivo que contem as funcoes que geram a tabela normal.
 *
 * Leonardo Amorim e Guilherme Rabelo
 * 27/11/2019
 */


 #include <stdbool.h>


#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED


long double z_value_erfc(double, bool);


long double z_value_simpson_13(double, bool);


long double gaussian_fun(double);


#endif // STATS_H_INCLUDED

