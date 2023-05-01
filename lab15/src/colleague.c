#include "colleague.h"

void printCharacteristicColleague(enum Characters character){
	switch (character) {
	case confident:
		printf("confident\n");
		break ;
	case stress_resistant:
		printf("stress_resistant\n");
		break ;
	case purposeful:
		printf("purposeful\n");
		break ;
	case organised:
		printf("organised\n");
		break ;
	}
}

size_t findCountColleagueInCompany_WithoutInsurance(struct Workers * workers, char * company){
	size_t count = 0;
	for (size_t i = 0; i < workers->size; i++){
		if (workers->colleagues[i]->insurance == false &&
			strncmp(workers->colleagues[i]->name_company, company, 5) == 0){
			count++;
		}

	}
	return count;

}


struct Workers * readColleagueFromFile(char * filename){
	FILE * file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Can`t open file: %s", strerror(errno));
		exit(1);
	}
	struct Workers * workers = malloc(sizeof(struct Workers));
	workers->colleagues = malloc(10 * sizeof(struct Colleague*));
	workers->size = 0;
	while(!feof(file)){
		size_t line_len = 100;
		char *line = malloc(line_len * sizeof (char));
		getline(&line, &line_len, file);
		if (strlen(line) < 2){
			free(line);
			continue;
		}

		struct Colleague * colleague = malloc(sizeof(struct Colleague));
		workers->colleagues[workers->size++] = colleague;

		char * token = strtok(line, ",");
		colleague->insurance = strtol(token, NULL, 10);
		token= strtok(0, ",");
		strcpy(colleague->name_company, token);
		token= strtok(0, ",");
		colleague->work_experience = strtof(token, NULL);
		token= strtok(0, ",");
		strcpy(colleague->contact_information.name_colleague, token);
		token= strtok(0, ",");
		strcpy(colleague->contact_information.surname, token);
		token= strtok(0, ",");
		strcpy(colleague->contact_information.email, token);
		token= strtok(0, ",");
		colleague->employ_characteristic = strtof(token, NULL);
		free(line);
	}

	fclose(file);
	return workers;
}


void writeColleagueToFile(char * filename, struct Workers * workers){
	FILE * file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "Can`t open file: %s", strerror(errno));
		exit(1);
	}

	for (size_t i = 0; i < workers->size; i++){
		struct Colleague * colleague = workers->colleagues[i];
		fprintf(file, "%d,%s,%f,%s,%s,%s,%d\n", colleague->insurance, colleague->name_company,
			colleague->work_experience, colleague->contact_information.name_colleague,
			colleague->contact_information.surname, colleague->contact_information.email,
			colleague->employ_characteristic);
	}
	fclose(file);
}

void printColleague(struct Workers * workers){
	for (size_t i = 0; i < workers->size; i++){
		printf("Worker №%zu:\n", i);
		if (workers->colleagues[i]->insurance == true){
			printf("Have insurance: Yes\n");
		}else if (workers->colleagues[i]->insurance == false){
			printf("Have insurance: No\n");
		}
		printf(""""
		       "Name company: %s\n"
		       "Work experience: %0.2f years\n"
		       "Contact information:\n"
		       "\tName: %s\n\tSurname: %s\n\tEmail: %s\n"
		       "Characteristic of the employee: "
		       """", workers->colleagues[i]->name_company, workers->colleagues[i]->work_experience,
		       workers->colleagues[i]->contact_information.name_colleague,
		       workers->colleagues[i]->contact_information.surname,
		       workers->colleagues[i]->contact_information.email);
		printCharacteristicColleague(workers->colleagues[i]->employ_characteristic);
		printf("\n");
	}
}

int cmp_insurance(const void *ins1, const void *ins2)
{
	const struct Colleague *a = *((const void **)ins1);
	const struct Colleague *b = *((const void **)ins2);
	if (a->insurance < b->insurance)
		return -1;
	if (a->insurance > b->insurance)
		return 1;
	return 0;
}

int cmp_nameCompany(const void *name1, const void *name2)
{
	const struct Colleague * a = *((const void **)name1);
	const struct Colleague * b = *((const void **)name2);
	return -strcmp(a->name_company, b->name_company);
}

int cmp_workExpirience(const void *name1, const void *name2)
{
	const struct Colleague *a = *((const void **)name1);
	const struct Colleague *b = *((const void **)name2);
	if (a->work_experience < b->work_experience)
		return -1;
	if (a->work_experience > b->work_experience)
		return 1;
	return 0;
}

int cmp_nameColleague(const void *name1, const void *name2)
{
	const struct Colleague * a = *((const void **)name1);
	const struct Colleague * b = *((const void **)name2);
	return -strcmp(a->contact_information.name_colleague, b->contact_information.name_colleague);
}

int cmp_surnameColleague(const void *name1, const void *name2)
{
	const struct Colleague * a = *((const void **)name1);
	const struct Colleague * b = *((const void **)name2);
	return -strcmp(a->contact_information.name_colleague, b->contact_information.name_colleague);
}

int cmp_email(const void *name1, const void *name2)
{
	const struct Colleague * a = *((const void **)name1);
	const struct Colleague * b = *((const void **)name2);
	return -strcmp(a->contact_information.email, b->contact_information.email);
}

int cmp_employ_characteristic(const void *name1, const void *name2)
{
	const struct Colleague *a = *((const void **)name1);
	const struct Colleague *b = *((const void **)name2);
	if (a->employ_characteristic < b->employ_characteristic)
		return -1;
	if (a->employ_characteristic > b->employ_characteristic)
		return 1;
	return 0;
}

void sortColleague(struct Workers * workers, char * fieldName){
	if (strcmp(fieldName, "insurance") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_insurance);
	}else if (strcmp(fieldName, "name_company") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_nameCompany);
	}else if (strcmp(fieldName, "work_experience") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_workExpirience);
	}else if (strcmp(fieldName, "name_colleague") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_nameColleague);
	}else if (strcmp(fieldName, "surname_colleague") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_nameCompany);
	}else if (strcmp(fieldName, "email") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_email);
	}else if (strcmp(fieldName, "employ_characteristic") == 0){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_employ_characteristic);
	}
}