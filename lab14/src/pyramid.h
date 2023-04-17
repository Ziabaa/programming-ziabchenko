#ifndef __PYRAMID_H__
#define __PYRAMID_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
/**
 * Записує потрібну строку до файлу
 * @param file_name  розташування файлу
 * @param text текст який потрібно записати у файл
 * @param mode режим додавання чи записування
 */
void write_to_file(char * file_name, char * text, char * mode);

/**
 * Читає потрібну інформацію із файлу
 * @param file_name розташування файлу
 * @param height висота піраміди
 * @param width ширина піраміди
 */

void read_from_file (char * file_name, int * x, int * y);
/**
 * Малює піраміду в консоль та записує її до файлу
 * @param file_name розташування файлу
 * @param height висота піраміди
 * @param width ширина піраміди
 */

void print_pyramid(char * file_name, int width, int height);


#endif