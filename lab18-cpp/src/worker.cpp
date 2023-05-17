#include "worker.h"


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

size_t Workers::findCountColleagueInCompany_WithoutInsurance(string company) const{
	size_t count = 0;
	for (size_t i = 0; i < this->size; i++){
		if (this->colleagues[i]->getInsurance() == false &&
		    this->colleagues[i]->getNameCompany() == company){
			count++;
		}
	}
	return count;

}

Workers * readColleagueFromFile(string filename){
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Can`t open file: " << filename << " for read, " << errno << endl;
		exit(1);
	}
	Workers * workers = new Workers();

	while(!file.eof()){
		string line;
		std::getline(file, line);
		if (line.empty()){
			continue ;
		}
		const Colleague * colleague = parseColleague(line);
		workers->addElement(0, colleague);
		delete colleague;
	}
	file.close();
	return workers;
}

void Workers::writeToFile(string filename) const
{
	ofstream file(filename, std::ios_base::app);
	if (!file.is_open()) {
		cerr << "Can`t open file: " << filename << " for write, " << strerror(errno) << endl;
		exit(1);
	}
	for (size_t i = 0; i < this->size; i++){
		this->colleagues[i]->writeMe(file);

	}
	file.close();
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
	return -a->getNameCompany().compare(b->getNameCompany());
}

int cmp_workExperience(const void *name1, const void *name2)
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
	return -a->getNameColleague().compare(b->getNameColleague());
}

int cmp_surnameColleague(const void *name1, const void *name2)
{
	const Colleague * a = *((const Colleague **)name1);
	const Colleague * b = *((const Colleague **)name2);
	return -a->getSurname().compare(b->getSurname());
}

int cmp_email(const void *name1, const void *name2)
{
	const Colleague * a = *((const Colleague **)name1);
	const Colleague * b = *((const Colleague **)name2);
	return -a->getEmail().compare(b->getEmail());
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

void Workers::sort(string fieldName){
	if (fieldName.compare("insurance") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_insurance);
	}else if (fieldName.compare("name_company") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameCompany);
	}else if (fieldName.compare("work_experience") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_workExperience);
	}else if (fieldName.compare("name_colleague") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameColleague);
	}else if (fieldName.compare("surname_colleague") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_nameCompany);
	}else if (fieldName.compare("email") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_email);
	}else if (fieldName.compare("employ_characteristic") == 0){
		qsort(this->colleagues, this->size,
		      sizeof (this->colleagues[0]), cmp_employ_characteristic);
	}
}

void Workers::print() const{
	for (size_t i = 0; i < size; ++i) {
		cout << this->colleagues[i]->toString();
	}
}
