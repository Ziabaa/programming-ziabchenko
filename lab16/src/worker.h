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

void addElement(struct Workers * workers, size_t pos, struct Colleague * colleague);

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
 *
 * @param workers Самі робітники
 */
void printWorkers(struct Workers * workers);

/**
 *
 * @param workers Самі робітники
 * @param fieldName
 * @param isAscending
 */
void sortColleague(struct Workers * workers, char * fieldName, bool isAscending);

#endif