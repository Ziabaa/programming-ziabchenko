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
		fprintf(stderr, "Can`t open file: %s", strerror(errno));
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
		fprintf(stderr, "Can`t open file: %s", strerror(errno));
		exit(1);
	}

	for (size_t i = 0; i < workers->size; i++){
		writeColleagueToFile(file, workers->colleagues[i]);
	}
	fclose(file);
}


int cmp_insur(const void *insur1, const void *insur2)
{
	const struct Colleague *ti1 = insur1;
	const struct Colleague *ti2 = insur2;
	if (ti1->insurance == 0 && ti2->insurance == 0){
		return 0;
	}else if (ti1->insurance == 1 && ti2->insurance == 1){
		return 0;
	}else return 1;
}

int cmp_names(const void *name1, const void *name2)
{
	const struct Colleague *tn1 = (const struct Colleague *)name1;
	const struct Colleague *tn2 = (const struct Colleague *)name2;
	return -strcmp(tn1->name_company, tn2->name_company);
}

int cmp_work(const void *work1, const void *work2)
{
	const struct Colleague *tw1 = (struct Colleague *)work1;
	const struct Colleague *tw2 = (struct Colleague *)work2;
	if(tw2->work_experience > tw1->work_experience) return 1;
	if(tw2->work_experience < tw1->work_experience) return -1;
	return 0;
}

void sortColleague(struct Workers * workers, char * fieldName, bool isAscending){
	if (strcmp(fieldName, "insurance") == 0 && isAscending == 1){
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_insur);
	}else if (strcmp(fieldName, "name_company") == 0 && isAscending ==1){
		qsort(workers->colleagues,workers->size,
		      sizeof workers->colleagues[0], cmp_names);
	}else if (strcmp(fieldName, "work_experience") == 0 && isAscending ==1) {
		qsort(workers->colleagues, workers->size,
		      sizeof (workers->colleagues[0]), cmp_work);
	}
}


void printWorkers(struct Workers * workers){
	for (size_t i = 0; i < workers->size; i++){
		printf("Worker №%zu:\n", i);
		printColleague(workers->colleagues[i]);
	}
}
