#include <stdlib.h>

//сортирує масив чисел
void sort_array(int *array, int size);

//бере спільну кількість стовпців та колонок(квадратна матриця)
int take_a_square_matrix(int columns, int rows);

//робить із двумірної матриці одномірну, яка складається з елементів головної
//діагоналі двумірної матриці, та сортує вихідну матрицю
void take_the_main_diagonal_and_sort(int const *matrix, int columns, int rows, int *res_array);