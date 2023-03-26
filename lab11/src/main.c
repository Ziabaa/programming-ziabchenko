#include "libmatrix.h"

int main()
{
#define SIZE 3
	int matrix[SIZE][SIZE] = { { 5, 5, 4 }, { 2, 1, 5 }, { 6, 3, -2 } };
	int *res_array = (int *)malloc(3 * sizeof(int));
	take_the_main_diagonal_and_sort(&matrix[0][0], 3, 3, &res_array[0]);
	free(res_array);
	return 0;
}
