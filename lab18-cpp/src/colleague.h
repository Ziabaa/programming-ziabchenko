#ifndef COLLEAGUE_H
#define COLLEAGUE_H


#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::string;

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
string characteristicColleague(enum Characters character);
/**
 * Контактна інформація про співробітника
 */
struct InformationOfColleague{
	string surname; /**<Фамілія*/
	string name_colleague; /**<Ім'я*/
	string email; /**<імейл*/
};

/**
 *Співробітник та його наповнення
 */


class Colleague{
	bool insurance; /**<Страховка*/
	string name_company; /**<Назва компанії*/
	float work_experience; /**<Стаж праці*/
	struct InformationOfColleague contact_information; /**<контактна інформаця*/
	enum Characters employ_characteristic; /**<деяка характеристика*/
    public:

	Colleague() : insurance(false), name_company("N/A"), work_experience(0.f), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {

	}
	Colleague(float work_experience) : insurance(false), name_company("N/A"), work_experience(work_experience), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {

	}
	Colleague(bool insurance, string name_company) : insurance(insurance),name_company(name_company), work_experience(0.f), contact_information{"N/A", "N/A", "N/A"}, employ_characteristic(confident) {

	}
	Colleague(const Colleague& other) : insurance(other.insurance), name_company(other.name_company), work_experience(other.work_experience), contact_information(other.contact_information), employ_characteristic(other.employ_characteristic){

	}
	Colleague(bool insurance, string name_company, float work_experience,
		  InformationOfColleague contact_information,
		  enum Characters employ_characteristic) : insurance(insurance), name_company(name_company),
		  work_experience(work_experience), contact_information(contact_information),
		  employ_characteristic(employ_characteristic) {

	}
	~Colleague() = default;


	bool getInsurance() const;
	const string& getNameCompany()const;
	float getWorkExperience() const;
	const string& getSurname() const;
	const string& getNameColleague() const;
	const string& getEmail() const;
	int getEmployCharacteristic() const;

	void writeMe(ofstream& file) const;

	string toString();


};

Colleague* parseColleague(const string& line);
string getNextToken(string& line, string& delimiter);

#endif