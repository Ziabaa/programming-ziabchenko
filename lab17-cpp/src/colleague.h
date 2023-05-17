#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cerrno>

/**
 *
 */
enum Characters{
	confident, stress_resistant, purposeful, organised
};
/**
 * Виводить характеристику співробітника
 * @param character сама характеристика
 */
void printCharacteristicColleague(enum Characters character);
/**
 * Контактна інформація про співробітника
 */
struct InformationOfColleague{
	char surname[30]; /**<Фамілія*/
	char name_colleague[30]; /**<Ім'я*/
	char email[30]; /**<імейл*/
};

/**
 *Співробітник та його наповнення
 */


class Colleague{
	bool insurance; /**<Страховка*/
	char name_company[30]; /**<Назва компанії*/
	float work_experience; /**<Стаж праці*/
	struct InformationOfColleague contact_information; /**<контактна інформаця*/
	enum Characters employ_characteristic; /**<деяка характеристика*/
    public:

	Colleague() : insurance(false), name_company("N/A"), work_experience(0.f), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {

	}
	Colleague(float work_experience) : insurance(false), name_company("N/A"), work_experience(work_experience), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {

	}
	Colleague(bool insurance, const char *name_company) : insurance(insurance), work_experience(0.f), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {
		strcpy(this->name_company, name_company);
	}
	Colleague(const Colleague& other) : insurance(other.insurance), work_experience(other.work_experience), employ_characteristic(other.employ_characteristic){
		strcpy(name_company, other.name_company);
		strcpy(contact_information.surname, other.contact_information.surname);
		strcpy(contact_information.name_colleague, other.contact_information.name_colleague);
		strcpy(contact_information.email, other.contact_information.email);

	}
	Colleague(bool insurance, const char *name_company, float work_experience,
		  InformationOfColleague contact_information,
		  enum Characters employ_characteristic) : insurance(insurance),
		  work_experience(work_experience),
		  employ_characteristic(employ_characteristic) {
		strcpy(this->name_company, name_company);
		strcpy(this->contact_information.surname, contact_information.surname);
		strcpy(this->contact_information.name_colleague, contact_information.name_colleague);
		strcpy(this->contact_information.email, contact_information.email);

	}
	~Colleague(){

	}
	bool getInsurance() const;
	char * getNameCompany()const;
	float getWorkExperience() const;
	char * getSurname() const;
	char * getNameColleague() const;
	char * getEmail() const;
	int getEmployCharacteristic() const;
	void printMe() const;
	void writeMe(FILE* file) const;


};

Colleague* parseColleague(char * line);

#endif