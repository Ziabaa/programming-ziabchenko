#ifndef __WORKER_H__
#define __WORKER_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

#include "colleague.h"

struct Workers{
	struct Colleague** colleagues;
	size_t size;
};
/**
 * додає одиного співробітника
 * @param workers куди записуємо
 * @param pos в яку позицію потрібно записати
 * @param colleague співробітник якого записуємо
 */
void addElement(struct Workers * workers, size_t pos, struct Colleague * colleague);
/**
 * видаляє одного співробіника
 * @param workers звідки видаляємо
 * @param pos позиція
 */
void delElement(struct Workers * workers, size_t pos);


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
void writeWorkersToFile(char * filename, struct Workers * workers);

/**
 *виводить до консолі співробітників
 * @param workers робітники
 */
void printWorkers(struct Workers * workers);

/**
 * сортує робітників за певним полем
 * @param workers робітники
 * @param fieldName поле для сортування
 * @param isAscending по зростанню чи спаданню
 */
void sortColleague(struct Workers * workers, char * fieldName);

#endif