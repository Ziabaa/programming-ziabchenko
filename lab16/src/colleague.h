#ifndef __COLLEAGUE_H__
#define __COLLEAGUE_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

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

/**
 * Контактна інформація про співробітника
 */
struct InformationOfColleague{
	char surname[50]; /**<Фамілія*/
	char name_colleague[20]; /**<Ім'я*/
	char email[50]; /**<імейл*/
};

/**
 *Співробітник та його наповнення
 */
struct Colleague{
	bool insurance; /**<Страховка*/
	char name_company[30]; /**<Назва компанії*/
	float work_experience; /**<Стаж праці*/
	struct InformationOfColleague contact_information; /**<контактна інформаця*/
	enum Characters employ_characteristic; /**<деяка характеристика*/
};

void printCharacteristicColleague(enum Characters character);

void printColleague(struct Colleague * colleague);

void writeColleagueToFile(FILE* file, struct Colleague * colleague);

struct Colleague* parseColleague(char * line);
#endif