#include "libmatrix.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_sort_array)
{
    int input_x[13] = { 12, 5, -23, -8, 10, 434, 65, 15, -6, 4, -7, 3, 2,};
    int expected_values[13] = {-23, -8, -7, -6, 2, 3, 4, 5,  10, 12, 15, 65, 434};

    sort_array(&input_x[0], 13);
    for(int j = 0; j < 13; j++){
	    int x = (expected_values[j]);
	    int y = (input_x[j]);
	    ck_assert_int_eq(x, y);

    }
}
END_TEST

START_TEST(test_take_a_square_matrix)
{
    int input_x[4] = {2, 4, 6, 9};
    int input_y[4] = {5,7, 6, 4};
    int expected_values[4] = {2, 4, 6, 4};

    for (int i = 0; i < 4; i++) {
        int actual_value = take_a_square_matrix(input_x[i], input_y[i]);
        ck_assert_int_eq(expected_values[i], actual_value);
    }
}
END_TEST

START_TEST(test_take_the_main_diagonal_and_sort)
{
    int input_x[3][3] ={{3, 4, 7}, {2, 7, 1}, {3, 7, 9}};
    int input_y[3] = {0, 0, 0};
    int input_columns = 3;
    int input_rows = 3;
    int expected_values[3] = {3, 7, 9};

    take_the_main_diagonal_and_sort(&input_x[0][0], input_columns, input_rows, &input_y[0]);
    for(int j = 0; j < 3; j++){
	int x = (expected_values[j]);
	int y = (input_y[j]);
	ck_assert_int_eq(x, y);

    }
}
END_TEST

int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab11");

    tcase_add_test(tc_core, test_sort_array);
    tcase_add_test(tc_core, test_take_a_square_matrix);
    tcase_add_test(tc_core, test_take_the_main_diagonal_and_sort);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}