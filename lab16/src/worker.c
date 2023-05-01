#include "worker.h"

void addElement(struct Workers * workers, size_t pos, struct Colleague * colleague){
	pos--;
	struct Colleague** new_colleague = malloc((workers->size + 1) * sizeof (struct Colleague*));

	if (pos > workers->size) pos = workers->size;

	memcpy(new_colleague, workers->colleagues, pos * sizeof(struct Colleague*));
	new_colleague[pos] = colleague;
	memcpy(new_colleague + pos + 1, workers->colleagues + pos, (workers->size - pos) * sizeof(struct Colleague*));

	if (workers->size > 0){
		free(workers->colleagues);
	}

	workers->colleagues = new_colleague;
	workers->size++;
}

void delElement(struct Workers * workers, size_t pos){
	if (workers->size == 0) return;

	struct Colleague** new_colleague = malloc((workers->size + 1) * sizeof (struct Colleague*));
	if (pos >= workers->size) pos = workers->size - 1;
	free(workers->colleagues[pos]);
	memcpy(new_colleague, workers->colleagues, pos * sizeof(struct Colleague*));
	memcpy(new_colleague + pos, workers->colleagues + pos + 1, (workers->size - pos - 1) * sizeof(struct Colleague*));
	free(workers->colleagues);
	workers->colleagues = new_colleague;
	workers->size--;
}

size_t findCountColleagueInCompany_WithoutInsurance(struct Workers * workers, char * company){
	size_t count = 0;
	for (size_t i = 0; i < workers->size; i++){
		if (workers->colleagues[i]->insurance == false &&
		    strcmp(workers->colleagues[i]->name_company, company) == 0){
			count++;
		}

	}
	return count;

}


struct Workers * readColleagueFromFile(char * filename){
	FILE * file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Can`t open file: %s\n", strerror(errno));
		exit(1);
	}
	struct Workers * workers = malloc(sizeof(struct Workers));
	workers->colleagues = NULL;
	workers->size = 0l;

	while(!feof(file)){
		size_t line_len = 100;
		char *line = malloc(line_len * sizeof (char));
		getline(&line, &line_len, file);
		if (strlen(line) == 0 || strlen(line) == 1){
			continue ;
		}
		struct Colleague * colleague = parseColleague(line);
		addElement(workers, 0, colleague);
		free(line);
	}
	fclose(file);
	return workers;
}

void writeWorkersToFile(char * filename, struct Workers * workers){
	FILE * file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "Can`t open file: %s\n", strerror(errno));
		exit(1);
	}

	for (size_t i = 0; i < workers->size; i++){
		writeColleagueToFile(file, workers->colleagues[i]);
	}
	fclose(file);
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


void printWorkers(struct Workers * workers){
	for (size_t i = 0; i < workers->size; i++){
		printf("Worker №%zu:\n", i);
		printColleague(workers->colleagues[i]);
	}
}
