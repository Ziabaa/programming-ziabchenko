#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
/**
 * Функція виконує шифрування: 'Шифром Цезаря'
 * @param str вхідна строка
 * @param res_str зашифрована строка
 * @param value на яку кількість потрібно зробити сдвиг
 */
void cipher_caesar(char * str, char * res_str, int value);

#endif