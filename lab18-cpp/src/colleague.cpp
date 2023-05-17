#include "colleague.h"

bool Colleague::getInsurance() const
{ return this->insurance; }
float Colleague::getWorkExperience() const {
	return this->work_experience;
}
const string& Colleague::getNameCompany() const {
	return this->name_company;
}
const string& Colleague::getSurname() const {
	return this->contact_information.surname;
}
const string& Colleague::getNameColleague() const {
	return this->contact_information.name_colleague;
}
const string& Colleague::getEmail() const {
	return this->contact_information.email;
}
int Colleague::getEmployCharacteristic() const{
	return this->employ_characteristic;
}

string Colleague::toString(){
	std::stringstream rawValue;
	if (this->insurance == 1){
		rawValue << "Have insurance: Yes" << endl;
	}else if (this->insurance == 0){
		rawValue << "Have insurance: No" << endl;
	}
	rawValue << "Name company: " << this->name_company << endl << "Work experience: " << this->work_experience << " years" << endl;
	rawValue << "Contact information:" << endl;
	rawValue << "\tName: " << this->contact_information.name_colleague << endl;
	rawValue << "\tSurname: " << this->contact_information.surname << endl;
	rawValue << "\tEmail: " << this->contact_information.email << endl << "Employ Characteristic: " << characteristicColleague(employ_characteristic) << endl;

	return rawValue.str();
}

string characteristicColleague(enum Characters character){
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

void Colleague::writeMe(ofstream& file) const{
	file << this->insurance << "," << this->name_company << "," << this->work_experience << ",";
	file << this->contact_information.name_colleague << "," << this->contact_information.surname << ",";
	file << this->contact_information.email << "," << this->employ_characteristic<< endl;
}

string getNextToken(string& line, string& delimiter){
	size_t pos = line.find(delimiter);
	string result = line.substr(0, pos);
	line.erase(0,pos + delimiter.length());
	return result;
}

Colleague* parseColleague(const string& inputLine){
	string del = ",";
	string line = inputLine;
	string name_company;
	InformationOfColleague info;

	string token = getNextToken(line, del);
	bool insurance = strtol(token.c_str(), nullptr, 10);
	token= getNextToken(line, del);
	name_company = token;
	token= getNextToken(line, del);;
	float work_experience = strtof(token.c_str(), nullptr);
	token= getNextToken(line, del);
	info.name_colleague = token;
	token= getNextToken(line, del);
	info.surname = token;
	token= getNextToken(line, del);
	info.email = token;
	token= getNextToken(line, del);

	Characters employ_characteristic = (Characters)strtof(token.c_str(), nullptr);
	Colleague * colleague = new Colleague(insurance, name_company, work_experience, info, employ_characteristic);

	return colleague;
}