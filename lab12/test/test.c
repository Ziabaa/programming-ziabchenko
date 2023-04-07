#include "matrix.h"
#include <check.h>
#include <stdlib.h>


START_TEST(test_mult_matrix)
{
    unsigned int col_1, row_1, col_2, row_2;
    col_1 = 3;
    row_1 = 3;
    col_2 = 3;
    row_2 = 2;
    double **first_matrix = malloc(col_1 * sizeof(double *));
    double **second_matrix = malloc(col_2 * sizeof(double *));
    for (unsigned int i = 0; i < col_1; i++) {
	    *(first_matrix + i) = malloc(row_1 * sizeof(double));
    }
    for (unsigned int i = 0; i < col_2; i++) {
	    *(second_matrix + i) = malloc(row_2 * sizeof(double));
    }
    double count1 = 1;
    for (unsigned int i = 0; i < col_1; i++) {
	    for (unsigned int j = 0; j < row_1; j++){
		    *(*(first_matrix + i) + j) = count1 + 0.25;
		    count1++;
	    }
    }
    double count2 = 1;
    for (unsigned int i = 0; i < col_2; i++) {
	    for (unsigned int j = 0; j < row_2; j++){
		    *(*(second_matrix + i) + j) = count2;
		    count2++;
	    }
    }
    print_matrix(&first_matrix[0], col_1, row_1);
    print_matrix(&second_matrix[0], col_2, row_2);

    double **res_matrix = malloc(col_1 * sizeof(double *));
    for (unsigned int i = 0; i < col_1; i++) {
	    *(res_matrix + i) = malloc(row_2 * sizeof(double));
    }

    double expected_values[3][2] = {{24.25, 31}, {51.25, 67}, {78.25, 103}};

    mult_matrix(first_matrix, second_matrix, res_matrix, col_1, row_2, 3);
    print_matrix(res_matrix, col_1, row_2);

    for (unsigned int i = 0; i < col_1; i++) {
        for (unsigned int j = 0; j < row_2; j++) {
		    ck_assert_float_eq_tol(expected_values[i][j], *(*(res_matrix + i) + j), 0.01);
	  }
    }
    free_matrix(first_matrix, 3);
    free_matrix(second_matrix, 3);
    free_matrix(res_matrix, 3);
}
END_TEST


int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab12");

    tcase_add_test(tc_core, test_mult_matrix);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}