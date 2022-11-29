/**
 * @file main.c description lab08 
 * 1.Якою мінімальною кількістю купюр можна набрати потрібну суму S за умови, що в наявності є купюри номіналом 1, 2, 5 та 10 грн.?
 * 2.У масиві цілих чисел, визначити суму двозначних чисел.
 * @author Ivan Ziabchenko
 */

/** розмір масиву (кількість стовпців) */
#define ROZM 5

/**
 * скільки мінімально протрібно купюр для певної суми 
 * @param number дана сума S
 * @return Кількість купюр
 */
int how_many_bancnotes_will_be_needed(int number);

/**
 * визначає суму двозначних чисел у масиві
 * @param array даний масив для розрахунку 
 * @param size розмір масиву
 * @return Сума двозначних цифр масиву
 */
int sum_dooble_number_of_array(int array[], int size);

/**
 * Точка входу в програму. Демонстрація рішення 
 * @return Код помилки (0)
*/
int main() 
{ 
	int my_array[ROZM] = { 34, 12, 24, 7, 4 };
	int sum = sum_dooble_number_of_array(my_array, ROZM);
	unsigned int bancnotes = how_many_bancnotes_will_be_needed(34); 
	return 0;
}

int how_many_bancnotes_will_be_needed(int number)
{
	int quantity = 0; 
	int sum = 0; 
	while (sum < number) { 
		if (sum + 10 <= number) {
			sum += 10;
			quantity++;
		} else if (sum + 5 <= number) {
			sum += 5;
			quantity++;
		} else if (sum + 2 <= number) {
			sum += 2;
			quantity++;
		} else if (sum + 1 <= number) {
			sum += 1;
			quantity++;
		}
	}
	return quantity;
}
int sum_dooble_number_of_array(int array[], int size) 
{
	int suma = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] >= 10) {
			suma += array[i]; 
		}
	}
	return suma;
}
