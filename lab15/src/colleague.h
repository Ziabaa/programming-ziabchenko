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

struct Workers{
	struct Colleague** colleagues;
	size_t size;
};

/**
 * Шукає кількість робітників певної кампанії без страхування
 * @param workers Самі робітники
 * @param company кампанія в якай шукаємо
 * @return кількість родбіників юез страховки
 */
size_t findCountColleagueInCompany_WithoutInsurance(struct Workers * workers, char * company);

/**
 * читає робітників з файлу та виделяє пам'ять пд них
 * @param filename назва файлу
 * @return всіх прочитаних робітників
 */
struct Workers * readColleagueFromFile(char * filename);

/**
 * Записує робітників до файлу
 * @param filename назва файлу
 * @param workers Самі робітники
 */
void writeColleagueToFile(char * filename, struct Workers * workers);

/**
 * Виводить до консолі структуру робітників
 * @param workers Самі робітники
 */
void printColleague(struct Workers * workers);

 /**
 *
 * @param workers Самі робітники
 * @param fieldName
 */
void sortColleague(struct Workers * workers, char * fieldName);


#endif