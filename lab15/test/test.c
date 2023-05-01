#include "../src/colleague.h"
#include <check.h>


START_TEST(test_readColleagueFromFile)
{
	struct Workers * workers = malloc(sizeof (struct Workers));
	workers->colleagues = malloc(1 * sizeof(struct Colleague*));
	workers->colleagues[0] = malloc(1 * sizeof(struct Colleague));

	workers->colleagues[0]->insurance = 1;
	strcpy(workers->colleagues[0]->name_company, "Google");
	workers->colleagues[0]->work_experience = 2.3f;
	strcpy(workers->colleagues[0]->contact_information.name_colleague, "Ivan");
	strcpy(workers->colleagues[0]->contact_information.surname, "Teplyi");
	strcpy(workers->colleagues[0]->contact_information.email, "dev-good@lal.com");
	workers->colleagues[0]->employ_characteristic = 0;
	struct Workers * read_worker = readColleagueFromFile("test/input_test.txt");
	ck_assert_int_eq(workers->colleagues[0]->insurance,read_worker->colleagues[0]->insurance);
	ck_assert_str_eq(workers->colleagues[0]->name_company,read_worker->colleagues[0]->name_company);
	ck_assert_float_eq_tol(workers->colleagues[0]->work_experience,read_worker->colleagues[0]->work_experience, 0.1);
	ck_assert_str_eq(workers->colleagues[0]->contact_information.name_colleague,
			 read_worker->colleagues[0]->contact_information.name_colleague);
	ck_assert_str_eq(workers->colleagues[0]->contact_information.surname,
			 read_worker->colleagues[0]->contact_information.surname);
	ck_assert_str_eq(workers->colleagues[0]->contact_information.email,
			 read_worker->colleagues[0]->contact_information.email);
	ck_assert_int_eq(workers->colleagues[0]->employ_characteristic,read_worker->colleagues[0]->employ_characteristic);
	free(read_worker->colleagues);
	free(read_worker);
	free(workers->colleagues[0]);
	free(workers->colleagues);
	free(workers);
}
END_TEST

START_TEST(test_findCountColleagueInCompany_WithoutInsurance)
{
	struct Workers * workers = malloc(sizeof (struct Workers));
	workers->colleagues = malloc(4 * sizeof(struct Colleague*));
	workers->colleagues[0] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[1] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[2] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[3] = malloc(1 * sizeof(struct Colleague));
	workers->size = 4;

	workers->colleagues[0]->insurance = 0;
	workers->colleagues[1]->insurance = 0;
	workers->colleagues[2]->insurance = 0;
	workers->colleagues[3]->insurance = 1;
	strcpy(workers->colleagues[0]->name_company, "Microsoft");
	strcpy(workers->colleagues[1]->name_company, "Google");
	strcpy(workers->colleagues[2]->name_company, "Google");
	strcpy(workers->colleagues[3]->name_company, "Google");

	size_t count =  findCountColleagueInCompany_WithoutInsurance(workers, "Google");
	size_t expected_x = 2;
	ck_assert_int_eq(count, expected_x);
	for (int i = 0; i < 4; ++i) {
		free(workers->colleagues[i]);
	}
	free(workers->colleagues);
	free(workers);
}
END_TEST

START_TEST(test_writeColleagueToFile)
{
	FILE * file = fopen("test/output_test.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Can`t open file: %s", strerror(errno));
		exit(1);
	}

	struct Workers * workers = malloc(sizeof (struct Workers));
	workers->colleagues = malloc(1 * sizeof(struct Colleague*));
	workers->colleagues[0] = malloc(1 * sizeof(struct Colleague));
	workers->size = 1;

	workers->colleagues[0]->insurance = 1;
	strcpy(workers->colleagues[0]->name_company, "Google");
	workers->colleagues[0]->work_experience = 2.3f;
	strcpy(workers->colleagues[0]->contact_information.name_colleague, "Ivan");
	strcpy(workers->colleagues[0]->contact_information.surname, "Teplyi");
	strcpy(workers->colleagues[0]->contact_information.email, "dev-good@lal.com");
	workers->colleagues[0]->employ_characteristic = 0;

	writeColleagueToFile("test/output_test.txt", workers);

	size_t line_len = 100;
	char *line = malloc(line_len * sizeof (char));
	getline(&line, &line_len, file);

	char * expected_line = "1,Google,2.300000,Ivan,Teplyi,dev-good@lal.com,0\n";
	ck_assert_str_eq(expected_line, line);

	free(line);
	free(workers->colleagues[0]);
	free(workers->colleagues);
	free(workers);
	fclose(file);
}
END_TEST

START_TEST(test_sortColleague)
{
#define N 4
	struct Workers * workers = malloc(sizeof (struct Workers));
	workers->colleagues = malloc(4 * sizeof(struct Colleague*));
	workers->colleagues[0] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[1] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[2] = malloc(1 * sizeof(struct Colleague));
	workers->colleagues[3] = malloc(1 * sizeof(struct Colleague));
	workers->size = 4;

	workers->colleagues[0]->work_experience = 4.5f;
	workers->colleagues[1]->work_experience = 3.7f;
	workers->colleagues[2]->work_experience = 7.3f;
	workers->colleagues[3]->work_experience = 0.5f;

	sortColleague(workers, "work_experience");
	float expected_values[N] = {0.5f, 3.7f, 4.5f, 7.3f};

	for (int i = 0; i < N; ++i) {
		ck_assert_float_eq_tol(expected_values[i], workers->colleagues[i]->work_experience, 0.1);
	}

	for (int i = 0; i < N; ++i) {
		free(workers->colleagues[i]);
	}
	free(workers->colleagues);
	free(workers);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("programing-ziabchenko");
    TCase *tc_core = tcase_create("lab15");

    tcase_add_test(tc_core, test_readColleagueFromFile);
    tcase_add_test(tc_core, test_findCountColleagueInCompany_WithoutInsurance);
    tcase_add_test(tc_core, test_writeColleagueToFile);
    tcase_add_test(tc_core, test_sortColleague);

    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}