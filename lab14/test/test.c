#include "../src/pyramid.h"
#include <check.h>


START_TEST(test_print_pyramid)
{
	int height = 5, width = 9;
	print_pyramid("assets/output.txt", width, height);
	FILE * file_point = fopen("assets/output.txt", "r");
	char str[20];
	char ex_str[5][11]= {"    *\n", "   ***\n", "  *****\n", " *******\n", "*********\n"};
	for (int i = 0; i < height; i++){
		fgets(str,50,file_point);
		ck_assert_str_eq(ex_str[i], str);
	}

	fclose(file_point);
}
END_TEST


int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab14");

    tcase_add_test(tc_core, test_print_pyramid);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}