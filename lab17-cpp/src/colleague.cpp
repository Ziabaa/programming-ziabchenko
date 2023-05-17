#include "colleague.h"

bool Colleague::getInsurance() const
{ return this->insurance; }

float Colleague::getWorkExperience() const {
	return this->work_experience;
}
char* Colleague::getNameCompany() const {
	return (char *)this->name_company;
}
char* Colleague::getSurname() const {
	return (char *)this->contact_information.surname;
}
char* Colleague::getNameColleague() const {
	return (char *)this->contact_information.name_colleague;
}
char* Colleague::getEmail() const {
	return (char *)this->contact_information.email;
}
int Colleague::getEmployCharacteristic() const{
	return this->employ_characteristic;
}


void Colleague::printMe()const
{
	if (this->insurance == 1){
		printf("Have insurance: Yes\n");
	}else if (this->insurance == 0){
		printf("Have insurance: No\n");
	}
	printf(""""
	       "Name company: %s\n"
	       "Work experience: %0.2f years\n"
	       "Contact information:\n"
	       "\tName: %s\n\tSurname: %s\n\tEmail: %s\n"
	       "Characteristic of the employee: "
	       """", this->name_company, this->work_experience,
	       this->contact_information.name_colleague,
	       this->contact_information.surname,
	       this->contact_information.email);
	printCharacteristicColleague(this->employ_characteristic);
	printf("\n");
}

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



void Colleague::writeMe(FILE *file) const{
	fprintf(file, "%d,%s,%f,%s,%s,%s,%d\n", this->insurance, this->name_company,
		this->work_experience, this->contact_information.name_colleague,
		this->contact_information.surname, this->contact_information.email,
		this->employ_characteristic);
}



Colleague* parseColleague(char * line){

	char name_company[30];
	InformationOfColleague info;

	char * token = strtok(line, ",");
	bool insurance = strtol(token, nullptr, 10);
	token= strtok(0, ",");
	strcpy(name_company, token);
	token= strtok(0, ",");
	float work_experience = strtof(token, nullptr);
	token= strtok(0, ",");
	strcpy(info.name_colleague, token);
	token= strtok(0, ",");
	strcpy(info.surname, token);
	token= strtok(0, ",");
	strcpy(info.email, token);
	token= strtok(0, ",");
	Characters employ_characteristic = (Characters)strtof(token, nullptr);
	Colleague * colleague = new Colleague(insurance, name_company, work_experience, info, employ_characteristic);

	return colleague;
}