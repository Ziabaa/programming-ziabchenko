#include "worker.h"

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cerrno>

size_t Workers::getSize() const{
	return this->size;
}
Colleague ** Workers::getColleague() const{
	return this->colleagues;
}
void Workers::addElement(size_t pos, const Colleague *colleague){
	pos--;
	Colleague** new_colleague = new Colleague *[this->size + 1];

	if (pos > this->size) pos = this->size;

	memcpy(new_colleague, this->colleagues, pos * sizeof(Colleague*));
	new_colleague[pos] = new Colleague(*colleague);
	memcpy(new_colleague + pos + 1, this->colleagues + pos, (this->size - pos) * sizeof(Colleague*));

	if (this->size > 0){
		delete[] this->colleagues;
	}

	this->colleagues = new_colleague;
	this->size++;
}

void Workers::delElement(size_t pos){
	if (this->size == 0) return;

	Colleague** new_colleague = new Colleague *[this->size - 1];
	if (pos >= this->size) pos = this->size - 1;
	delete this->colleagues[pos];
	memcpy(new_colleague, this->colleagues, pos * sizeof( Colleague*));
	memcpy(new_colleague + pos, this->colleagues + pos + 1, (this->size - pos - 1) * sizeof(Colleague*));
	delete[] this->colleagues;
	this->colleagues = new_colleague;
	this->size--;
}

size_t Workers::findCountColleagueInCompany_WithoutInsurance(const char * company) const{
	size_t count = 0;
	for (size_t i = 0; i < this->size; i++){
		if (this->colleagues[i]->getInsurance() == false &&
		    strcmp(this->colleagues[i]->getNameCompany(), company) == 0){
			count++;
		}

	}
	return count;

}


Workers * readColleagueFromFile(const char * filename){
	FILE * file = fopen(filename, "r");
	if (file == nullptr) {
		fprintf(stderr, "Can`t open file: %s\n", strerror(errno));
		exit(1);
	}
	Workers * workers = new Workers();

	while(!feof(file)){
		size_t line_len = 100;
		char *line = new char[line_len];
		getline(&line, &line_len, file);
		if (strlen(line) == 0 || strlen(line) == 1){
			continue ;
		}
		const Colleague * colleague = parseColleague(line);
		workers->addElement(0, colleague);
		delete[] line;
	}
	fclose(file);
	return workers;
}

void Workers::writeToFile(char *filename) const
{
	FILE * file = fopen(filename, "w");
	if (file == nullptr) {
		fprintf(stderr, "Can`t open file: %s\n", strerror(errno));
		exit(1);
	}

	for (size_t i = 0; i < this->size; i++){
		this->colleagues[i]->writeMe(file);

	}
	fclose(file);

}


int cmp_insurance(const void *ins1, const void *ins2)
{
	const Colleague *a = *((const Colleague **)ins1);
	const Colleague *b = *((const Colleague **)ins2);
	if (a->getInsurance() < b->getInsurance())
		return -1;
	if (a->getInsurance() > b->getInsurance())
		return 1;
	return 0;
}

int cmp_nameCompany(const void *name1, const void *name2)
{
	const Colleague *a = *((const Colleague **)name1);
	const Colleague *b = *((const Colleague **)name2);
	return -strcmp(a->getNameCompany(), b->getNameCompany());
}

int cmp_workExpirience(const void *name1, const void *name2)
{
	const Colleague *a = *((const Colleague **)name1);
	const Colleague *b = *((const Colleague **)name2);
	if (a->getWorkExperience() < b->getWorkExperience())
		return -1;
	if (a->getWorkExperience() > b->getWorkExperience())
		return 1;
	return 0;
}

int cmp_nameColleague(const void *name1, const void *name2)
{
	const Colleague * a = *((const Colleague **)name1);
	const Colleague * b = *((const Colleague **)name2);
	return -strcmp(a->getNameColleague(), b->getNameColleague());
}

int cmp_surnameColleague(const void *name1, const void *name2)
{
	const Colleague * a = *((const Colleague **)name1);
	const Colleague * b = *((const Colleague **)name2);
	return -strcmp(a->getSurname(), b->getSurname());
}

int cmp_email(const void *name1, const void *name2)
{
	const Colleague * a = *((const Colleague **)name1);
	const Colleague * b = *((const Colleague **)name2);
	return -strcmp(a->getEmail(), b->getEmail());
}

int cmp_employ_characteristic(const void *name1, const void *name2)
{
	const Colleague *a = *((const Colleague **)name1);
	const Colleague *b = *((const Colleague **)name2);
	if (a->getEmployCharacteristic() < b->getEmployCharacteristic())
		return -1;
	if (a->getEmployCharacteristic() > b->getEmployCharacteristic())
		return 1;
	return 0;
}
void Workers::sort(const char * fieldName){
	if (strcmp(fieldName, "insurance") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_insurance);
	}else if (strcmp(fieldName, "name_company") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameCompany);
	}else if (strcmp(fieldName, "work_experience") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_workExpirience);
	}else if (strcmp(fieldName, "name_colleague") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameColleague);
	}else if (strcmp(fieldName, "surname_colleague") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameCompany);
	}else if (strcmp(fieldName, "email") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_email);
	}else if (strcmp(fieldName, "employ_characteristic") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_employ_characteristic);
	}
}


void Workers::print() const{
	for (size_t i = 0; i < size; ++i) {
		this->colleagues[i]->printMe();
	}
}
