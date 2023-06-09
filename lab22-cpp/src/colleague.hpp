#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

enum Characters { confident, stress_resistant, purposeful, organised };
enum Level_programmer { junior, middle, senior };
enum Language_programmer { Java, C, Python };
enum Language_translator { english, ukrainian, spanish };
/**
 * Виводить характеристику співробітника
 * @param character сама характеристика
 */
string characteristicColleague(enum Characters character)
{
	std::stringstream rawValue;
	switch (character) {
	case confident:
		rawValue << "confident" << endl;
		return rawValue.str();
	case stress_resistant:
		rawValue << "stress-resistant" << endl;
		return rawValue.str();
	case purposeful:
		rawValue << "purposeful" << endl;
		return rawValue.str();
	case organised:
		rawValue << "organised" << endl;
		return rawValue.str();
	}
}
/**
 * Контактна інформація про співробітника
 */
struct InformationOfColleague {
	string surname; /**<Фамілія*/
	string name_colleague; /**<Ім'я*/
	string email; /**<імейл*/
};

/**
 *Співробітник та його наповнення
 */
class Colleague {
    public:
	bool insurance; /**<Страховка*/
	string name_company; /**<Назва компанії*/
	float work_experience; /**<Стаж праці*/
	struct InformationOfColleague contact_information; /**<контактна інформаця*/
	enum Characters employ_characteristic; /**<деяка характеристика*/

	Colleague()
		: insurance(false), name_company("N/A"), work_experience(0.f), contact_information{ "N/A", "N/A", "N/A" },
		  employ_characteristic(confident)
	{
	}
	Colleague(float work_experience)
		: insurance(false), name_company("N/A"), work_experience(work_experience), contact_information{ "N/A", "N/A", "N/A" },
		  employ_characteristic(confident)
	{
	}
	Colleague(bool insurance, string name_company)
		: insurance(insurance), name_company(name_company), work_experience(0.f), contact_information{ "N/A", "N/A", "N/A" },
		  employ_characteristic(confident)
	{
	}
	Colleague(const Colleague &other)
		: insurance(other.insurance), name_company(other.name_company), work_experience(other.work_experience),
		  contact_information(other.contact_information), employ_characteristic(other.employ_characteristic)
	{
	}
	Colleague(bool insurance, string name_company, float work_experience, InformationOfColleague contact_information,
		  enum Characters employ_characteristic)
		: insurance(insurance), name_company(name_company), work_experience(work_experience), contact_information(contact_information),
		  employ_characteristic(employ_characteristic)
	{
	}
	~Colleague() = default;

		void printMe()
	{
		cout << this->insurance << "," << this->name_company << "," << this->work_experience << ",";
		cout << this->contact_information.name_colleague << "," << this->contact_information.surname << ",";
		cout << this->contact_information.email << "," << this->employ_characteristic << endl;
	}

};

class Programmer : public Colleague {
    public:
	enum Level_programmer levelProgrammer;
	enum Language_programmer languageProgrammer;

	Programmer() : levelProgrammer(junior), languageProgrammer(C)
	{
	}
	Programmer(string name, float work_exp, enum Level_programmer level) : languageProgrammer(C)
	{
		this->name_company = name;
		this->work_experience = work_exp;
		this->levelProgrammer = level;
	}
	void printMe()
	{
		cout << this->insurance << "," << this->name_company << "," << this->work_experience << ",";
		cout << this->contact_information.name_colleague << "," << this->contact_information.surname << ",";
		cout << this->contact_information.email << "," << this->employ_characteristic << ", ";
		cout << this->languageProgrammer << ", " << this->levelProgrammer << endl;
	}
};

class Translator : public Colleague {
    public:
	enum Language_translator languageTranslator;
	bool sinc_translator;

	Translator() : languageTranslator(ukrainian), sinc_translator(0)
	{
	}
	Translator(string name, float work_exp, bool sinc) : languageTranslator(ukrainian)
	{
		this->name_company = name;
		this->work_experience = work_exp;
		this->sinc_translator = sinc;
	}


	void printMe()
	{
		cout << this->insurance << "," << this->name_company << "," << this->work_experience << ",";
		cout << this->contact_information.name_colleague << "," << this->contact_information.surname << ",";
		cout << this->contact_information.email << "," << this->employ_characteristic << ", ";
		cout << this->sinc_translator << ", " << this->languageTranslator << endl;
	}
};

#endif