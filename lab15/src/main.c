#include "colleague.h"

int main()
{
	struct Workers * workers = malloc(sizeof (struct Workers));
	workers->colleagues = malloc(3 * sizeof(struct Colleague*));
	for (size_t i = 0; i < 3; i++){
		workers->colleagues[i] = malloc(1 * sizeof(struct Colleague));
	}
	workers->size = 3;

	workers->colleagues[0]->insurance = 1;
	workers->colleagues[1]->insurance = 0;
	workers->colleagues[2]->insurance = 1;

	strcpy(workers->colleagues[0]->name_company, "Google");
	strcpy(workers->colleagues[1]->name_company, "NIX");
	strcpy(workers->colleagues[2]->name_company, "Microsoft");

	workers->colleagues[0]->work_experience = 2.3f;
	workers->colleagues[1]->work_experience = 6.0f;
	workers->colleagues[2]->work_experience = 0.3f;

	strcpy(workers->colleagues[0]->contact_information.name_colleague, "Ivan");
	strcpy(workers->colleagues[0]->contact_information.surname, "Teplyi");
	strcpy(workers->colleagues[0]->contact_information.email, "dev-good@lal.com");
	strcpy(workers->colleagues[1]->contact_information.name_colleague, "leo");
	strcpy(workers->colleagues[1]->contact_information.surname, "Pender");
	strcpy(workers->colleagues[1]->contact_information.email, "lesly-gerd@lal.com");
	strcpy(workers->colleagues[2]->contact_information.name_colleague, "Dany");
	strcpy(workers->colleagues[2]->contact_information.surname, "Abraham");
	strcpy(workers->colleagues[2]->contact_information.email, "abraham1998@lal.com");

	workers->colleagues[0]->employ_characteristic = 2;
	workers->colleagues[1]->employ_characteristic = 1;
	workers->colleagues[2]->employ_characteristic = 0;

	writeColleagueToFile("assets/output.txt", workers);
	printColleague(workers);
	printf("\n\nВідсортовані робітники\n");


	sortColleague(workers, "email");
	printColleague(workers);

	struct Workers * new_workers_from_file = readColleagueFromFile("assets/input.txt");
	printColleague(new_workers_from_file);

	size_t count = findCountColleagueInCompany_WithoutInsurance(new_workers_from_file, "Google");
	printf("Count colleagues in company %s: %zu\n", "Google", count);

	for (size_t i = 0; i < 3; i++){
		free(workers->colleagues[i]);
	}
	for (size_t i = 0; i < new_workers_from_file->size; i++){
		free(new_workers_from_file->colleagues[i]);
	}
	free(new_workers_from_file);
	free(workers->colleagues);
	free(workers);
	return 0;
}