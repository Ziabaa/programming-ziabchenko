#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>

/**
 * множить 2 матриці
 * @param matrix1 перша вхідна матриця
 * @param matrix2 друга вхідна матриця
 * @param res_matrix вихідна матриця
 * @param col кількість колонок першої матриці
 * @param row кількість рядків другої матриці
 * @param general спільна кількість рядків першої та колонок другої
 */
void mult_matrix(double **matrix1, double **matrix2, double **res_matrix, unsigned int col, unsigned int row, unsigned int general);

/**
 * виводить матрицю в консоль
 * @param matrix вхідна матриця
 * @param size_x кількість колонок
 * @param size_y кількість рядків
 */
void print_matrix(double **matrix, unsigned int size_x, unsigned int size_y);

/**
 * вивільнює пам'ять матриці
 * @param matrix вхідна матриця
 * @param col кількість колонок
 */
void free_matrix(double **matrix, unsigned int col);
/**
 *
 * @param matrix вхідна матриця
 * @param col кількість колонок
 * @param row кількість рядків
 */
void get_matrix(double **matrix, unsigned int col, unsigned int row);

#endif