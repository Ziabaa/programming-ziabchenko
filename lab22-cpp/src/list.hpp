#ifndef __LIST_H__
#define __LIST_H__
#include "colleague.hpp"
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

void sortProgrammer(string fieldName, vector<Programmer> &enter)
{
	if (fieldName == "insurance") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.insurance < p2.insurance; });
	} else if (fieldName == "name_company") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.name_company < p2.name_company; });
	} else if (fieldName == "work_experience") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.work_experience < p2.work_experience; });
	} else if (fieldName == "name_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Programmer &p1, Programmer &p2) { return p1.contact_information.name_colleague < p2.contact_information.name_colleague; });
	} else if (fieldName == "surname_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Programmer &p1, Programmer &p2) { return p1.contact_information.surname < p2.contact_information.surname; });
	} else if (fieldName == "email") {
		sort(enter.begin(), enter.end(),
		     [](Programmer &p1, Programmer &p2) { return p1.contact_information.email < p2.contact_information.email; });
	} else if (fieldName == "employ_characteristic") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.employ_characteristic < p2.employ_characteristic; });
	} else if (fieldName == "levelProgrammer") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.levelProgrammer < p2.levelProgrammer; });
	} else if (fieldName == "languageProgrammer") {
		sort(enter.begin(), enter.end(), [](Programmer &p1, Programmer &p2) { return p1.languageProgrammer < p2.languageProgrammer; });
	}
}

void sortColleague(string fieldName, vector<Colleague> &enter)
{
	if (fieldName == "insurance") {
		sort(enter.begin(), enter.end(), [](Colleague &p1, Colleague &p2) { return p1.insurance < p2.insurance; });
	} else if (fieldName == "name_company") {
		sort(enter.begin(), enter.end(), [](Colleague &p1, Colleague &p2) { return p1.name_company < p2.name_company; });
	} else if (fieldName == "work_experience") {
		sort(enter.begin(), enter.end(), [](Colleague &p1, Colleague &p2) { return p1.work_experience < p2.work_experience; });
	} else if (fieldName == "name_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Colleague &p1, Colleague &p2) { return p1.contact_information.name_colleague < p2.contact_information.name_colleague; });
	} else if (fieldName == "surname_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Colleague &p1, Colleague &p2) { return p1.contact_information.surname < p2.contact_information.surname; });
	} else if (fieldName == "email") {
		sort(enter.begin(), enter.end(),
		     [](Colleague &p1, Colleague &p2) { return p1.contact_information.email < p2.contact_information.email; });
	} else if (fieldName == "employ_characteristic") {
		sort(enter.begin(), enter.end(), [](Colleague &p1, Colleague &p2) { return p1.employ_characteristic < p2.employ_characteristic; });
	}
}

void sortTranslator(string fieldName, vector<Translator> &enter)
{
	if (fieldName == "insurance") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.insurance < p2.insurance; });
	} else if (fieldName == "name_company") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.name_company < p2.name_company; });
	} else if (fieldName == "work_experience") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.work_experience < p2.work_experience; });
	} else if (fieldName == "name_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Translator &p1, Translator &p2) { return p1.contact_information.name_colleague < p2.contact_information.name_colleague; });
	} else if (fieldName == "surname_colleague") {
		sort(enter.begin(), enter.end(),
		     [](Translator &p1, Translator &p2) { return p1.contact_information.surname < p2.contact_information.surname; });
	} else if (fieldName == "email") {
		sort(enter.begin(), enter.end(),
		     [](Translator &p1, Translator &p2) { return p1.contact_information.email < p2.contact_information.email; });
	} else if (fieldName == "employ_characteristic") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.employ_characteristic < p2.employ_characteristic; });
	} else if (fieldName == "languageTranslator") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.languageTranslator < p2.languageTranslator; });
	} else if (fieldName == "sinc_translator") {
		sort(enter.begin(), enter.end(), [](Translator &p1, Translator &p2) { return p1.sinc_translator < p2.sinc_translator; });
	}
}

template <typename T> vector<T> merge(vector<T> &first, vector<T> &second)
{
	vector<T> mergeVector;
	for (size_t a = 0; a < first.size(); a++) {
		mergeVector.push_back(first[a]);
	}
	for (size_t a = 0; a < second.size(); a++) {
		mergeVector.push_back(second[a]);
	}
	return mergeVector;
}

size_t findCountColleagueInCompany_WithoutInsurance(string company, vector<Colleague> enter)
{
	size_t count = 0;
	for (size_t i = 0; i < enter.size(); i++) {
		if (!enter[i].insurance && enter[i].name_company == company) {
			count++;
		}
	}
	return count;
}

vector<Programmer> findProgrammerInCompany_WithMiddleLev_and_WorkExperMoreThenOneYear(vector<Programmer> &enter)
{
	vector<Programmer> res_programmer;
	for (size_t i = 0; i < enter.size(); i++) {
		if (enter[i].work_experience > 1 && enter[i].levelProgrammer == middle) {
			res_programmer.push_back(enter[i]);
		}
	}
	return res_programmer;
}

vector<Translator> findTranslatorInCompany_WithSincTranslate_and_WorkExperMoreThenFiveYear(vector<Translator> &enter)
{
	vector<Translator> res_translator;
	for (size_t i = 0; i < enter.size(); i++) {
		if (enter[i].work_experience > 5 && enter[i].sinc_translator) {
			res_translator.push_back(enter[i]);
		}
	}
	return res_translator;
}

#endif