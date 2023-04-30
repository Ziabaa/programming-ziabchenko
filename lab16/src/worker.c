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

int cmp_names(const void *name1, const void *name2)
{
	const struct Colleague *a = name1, *b = name2;
	printf("----------->%s\n", a->name_company);
	printf("----------->%s\n\n", b->name_company);
	return -strcmp(a->name_company, b->name_company);
}

void sortColleague(struct Workers * workers, char * fieldName, bool isAscending){
	if (strcmp(fieldName, "name_company") == 0 && isAscending == 1){
		qsort(*(workers->colleagues), workers->size,
		      sizeof(struct Colleague), cmp_names);
	}
}


void printWorkers(struct Workers * workers){
	for (size_t i = 0; i < workers->size; i++){
		printf("Worker №%zu:\n", i);
		printColleague(workers->colleagues[i]);
	}
}
