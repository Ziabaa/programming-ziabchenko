#include "colleague.h"

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

void printColleague(struct Colleague * colleague){
	if (colleague->insurance == true){
		printf("Have insurance: Yes\n");
	}else if (colleague->insurance == false){
		printf("Have insurance: No\n");
	}
	printf(""""
	       "Name company: %s\n"
	       "Work experience: %0.2f years\n"
	       "Contact information:\n"
	       "\tName: %s\n\tSurname: %s\n\tEmail: %s\n"
	       "Characteristic of the employee: "
	       """", colleague->name_company, colleague->work_experience,
	       colleague->contact_information.name_colleague,
	       colleague->contact_information.surname,
	       colleague->contact_information.email);
	printCharacteristicColleague(colleague->employ_characteristic);
	printf("\n");
}

void writeColleagueToFile(FILE* file, struct Colleague * colleague){
	fprintf(file, "%d,%s,%f,%s,%s,%s,%d\n", colleague->insurance, colleague->name_company,
		colleague->work_experience, colleague->contact_information.name_colleague,
		colleague->contact_information.surname, colleague->contact_information.email,
		colleague->employ_characteristic);
}

struct Colleague* parseColleague(char * line){
	struct Colleague * colleague = malloc(sizeof(struct Colleague));

	char * token = strtok(line, ",");
	colleague->insurance = strtol(token, NULL, 10);
	token= strtok(0, ",");
	strcpy(colleague->name_company, token);
	token= strtok(0, ",");
	colleague->work_experience = strtof(token, NULL);
	token= strtok(0, ",");
	strcpy(colleague->contact_information.name_colleague, token);
	token= strtok(0, ",");
	strcpy(colleague->contact_information.surname, token);
	token= strtok(0, ",");
	strcpy(colleague->contact_information.email, token);
	token= strtok(0, ",");
	colleague->employ_characteristic = strtof(token, NULL);

	return colleague;
}