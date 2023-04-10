#include "matrix.h"
#include <check.h>


START_TEST(test_cipher_caesar)
{
	char * input_str = "Input, \n  te\txt";
	char * res_str = malloc(sizeof(char) * (strlen(input_str) + 1));
	char expected_str[3][16] = {"Lqsxw,    wh aw", "Mrtyx,    xi bx", "Nsuzy,    yj cy"};
	for (int i = 0; i < 3; i++){
		int x = 3 + i;
		cipher_caesar(input_str, res_str, x);
		ck_assert_str_eq(res_str, expected_str[i]);
	}

	free(res_str);
}
END_TEST


int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab13");

    tcase_add_test(tc_core, test_cipher_caesar);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}