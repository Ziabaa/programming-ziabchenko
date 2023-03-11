#include "lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_sum_dooble_number)
{
#define ROZM 5
    int input_x[3][ROZM] = { {12, 5, 23, 8, 10},
	                     {15, 4, 3, 5, 24},
                       	     {75, -25, 4, 12, 3}   				
     		      	      };
    int expected_values[ROZM] = {45, 39, 62};

    for (int i = 0; i < 3; i++) {
        int actual_value = sum_dooble_number_of_array(input_x[i], ROZM);
        ck_assert_int_eq(expected_values[i], actual_value);
    }
}
END_TEST

START_TEST(test_how_many_bancnotes_will_be_needed)
{
#define SIZE 3
    int input_x[SIZE] = { 58, 30, 18};                            
    int expected_values[SIZE] = {8, 3, 4};

    for (int i = 0; i < SIZE; i++) {
        int actual_value = how_many_bancnotes_will_be_needed(input_x[i]);
        ck_assert_int_eq(expected_values[i], actual_value);
    }
}
END_TEST

int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab09");

    tcase_add_test(tc_core, test_sum_dooble_number);
    tcase_add_test(tc_core, test_how_many_bancnotes_will_be_needed);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

