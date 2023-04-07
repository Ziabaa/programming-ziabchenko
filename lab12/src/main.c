#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Автор: Зябченко Іван\nЛабораторна робота №12\nТема: 'Взаємодія з користувачем шляхом механізму введення/виведення'\n");

	printf("\tBведіть кількість стовпців та рядків першої матриці: ");
	unsigned int col_1, row_1, col_2, row_2;
	scanf("%u %u", &col_1, &row_1);

	printf("\tBведіть кількість стовпців та рядків другої матриці: ");
	scanf("%u %u", &col_2, &row_2);

	printf("Ви ввели: стовпців- %u, рядків- %u\n", col_1, row_1);
	printf("Ви ввели: стовпців- %u, рядків- %u\n", col_2, row_2);

	if (row_1 != col_2) {
		fprintf(stderr, "Not correct size matrix\n");
		return 1;
	} else if (row_1 == 0 || row_2 == 0 || col_1 == 0 || col_2 == 0) {
		fprintf(stderr, "Matrix can`t have 0\n");
		return 1;
	}

	double **first_matrix = malloc(col_1 * sizeof(double *));
	double **second_matrix = malloc(col_2 * sizeof(double *));

	for (unsigned int i = 0; i < col_1; i++) {
		*(first_matrix + i) = malloc(row_1 * sizeof(double));
	}
	if (first_matrix == NULL) {
		return 1;
	}

	for (unsigned int i = 0; i < col_2; i++) {
		*(second_matrix + i) = malloc(row_2 * sizeof(double));
	}
	if (second_matrix == NULL) {
		return 1;
	}
	get_matrix(first_matrix, col_1, row_1);
	get_matrix(second_matrix, col_2, row_2);

	print_matrix(&first_matrix[0], col_1, row_1);
	print_matrix(&second_matrix[0], col_2, row_2);

	double **res_matrix = malloc(col_1 * sizeof(double *));
	for (unsigned int i = 0; i < col_1; i++) {
		*(res_matrix + i) = malloc(row_2 * sizeof(double));
	}
	if (res_matrix == NULL) {
		return 1;
	}

	mult_matrix(first_matrix, second_matrix, res_matrix, col_1, row_2, row_1);
	printf("\nРезультат множення матриць:\n");
	print_matrix(&res_matrix[0], col_1, row_2);

	free_matrix(&first_matrix[0], col_1);
	free_matrix(&second_matrix[0], col_2);
	free_matrix(&res_matrix[0], col_1);

	return 0;
}