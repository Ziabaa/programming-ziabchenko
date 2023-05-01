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
void printCharacteristicColleague(enum Characters character);
/**
 * Контактна інформація про співробітника
 */
struct InformationOfColleague{
	char surname[30]; /**<Фамілія*/
	char name_colleague[20]; /**<Ім'я*/
	char email[30]; /**<імейл*/
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

/**
 * Виводить до консолі структуру робітника
 * @param workers Самі робітники
 */
void printColleague(struct Colleague * colleague);
/**
 * записує до файлу структуру робітників
 * @param file відкритий файл
 * @param colleague співробітник
 */
void writeColleagueToFile(FILE* file, struct Colleague * colleague);
/**
 * зчитує одного робітника з лінії
 * @param line лінія файлу з якого зчитати співробітника
 * @return проситаного робітника
 */
struct Colleague* parseColleague(char * line);
#endif