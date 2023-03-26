#include "libmatrix.h"
int take_a_square_matrix(int columns, int rows)
{
	int size = 0;
	if (columns >= rows) {
		size = rows;
	} else if (rows > columns) {
		size = columns;
	}
	return size;
}

void sort_array(int *array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(array + i) > *(array + j)) {
				int temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			}
		}
	}
}

void take_the_main_diagonal_and_sort(int const *matrix, int columns, int rows, int *res_array)
{
	int size = take_a_square_matrix(columns, rows);
	for (int i = 0; i < size; i++) {
		*(res_array + i) = matrix[i * size + i];
	}
	sort_array(&res_array[0], size);
}
