#include "matrix.h"

#include <stdio.h>

void mult_matrix(double **matrix1, double **matrix2, double **res_matrix, unsigned int col, unsigned int row, unsigned int general)
{
	for (int i = 0; i < (int)col; i++) {
		for (int j = 0; j < (int)row; j++) {
			for (int k = 0; k < (int)general; k++) {
				*(*(res_matrix + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
			}
		}
	}
}

void free_matrix(double **matrix, unsigned int col)
{
	for (unsigned int i = 0; i < col; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void get_matrix(double **matrix, unsigned int col, unsigned int row)
{
	for (int i = 0; i < (int)col; i++) {
		for (int j = 0; j < (int)row; j++) {
			printf("введіть [%u] [%u] елемент матриці: ", i, j);
			scanf("%lf", *(matrix + i) + j);
		}
	}
}

void print_matrix(double **matrix, unsigned int size_x, unsigned int size_y)
{
	printf("\n");
	for (unsigned int i = 0; i < size_x; i++) {
		if (i == 0 || i == size_x - 1) {
			printf("[");
		} else {
			printf("|");
		}
		for (unsigned int j = 0; j < size_y; j++) {
			printf("%6.2f\t", matrix[i][j]);
		}
		if (i == 0 || i == size_x - 1) {
			printf("]\n");
		} else {
			printf("|\n");
		}
	}
}