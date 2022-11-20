//Знайти за яку мінімальну кількість купюр можна витратити суму цифр
int how_many_bancnotes_will_be_needed(int number); //попередньо оголосили існнування функції
//У масиві цілих чисел знайти суму двоцифрових чисел
int sum_dooble_number_of_array(int array[], int size); //попередньо оголосили існнування функції
int main() //головна функція
{
#define ROZM 5 //кількість чисел у масиві
	int my_array[ROZM] = { 34, 12, 24, 7, 4 }; //даний масив
	int sum = sum_dooble_number_of_array(my_array, ROZM); //виконання функції: знаходження суми двоцифрових чисел
	unsigned int bancnotes = how_many_bancnotes_will_be_needed(34); //мінімальна кількість купюр у сумі цифр
	return 0;
}

int how_many_bancnotes_will_be_needed(int number) //точка входу у функцію, при заданому числі
{
	int quantity = 0; //кількість купюр
	int sum = 0; //загальна сума
	int nominal_money1 = 10; //перший номінал
	int nominal_money2 = 5; //другий номінал
	int nominal_money3 = 2; //третій номінал
	int nominal_money4 = 1; //четвертий номінал
	while (sum < number) { //виконується доки сума менша за вхідне число
		if (sum + nominal_money1 <= number) {
			sum += nominal_money1;
			quantity++;
		} else if (sum + nominal_money2 <= number) {
			sum += nominal_money2;
			quantity++;
		} else if (sum + nominal_money3 <= number) {
			sum += nominal_money3;
			quantity++;
		} else if (sum + nominal_money4 <= number) {
			sum += nominal_money4;
			quantity++;
		}
	}
	return quantity; //повернути у функцію число банкнот
}
int sum_dooble_number_of_array(int array[], int size) //точка входу до функції, що знаходить суму двоцифрових чисел у масиві
{
	int suma = 0;
	for (int i = 0; i < size; i++) { //виконується доки поточне число не більше за останнє
		if (array[i] >= 10) { //якщо дане число більше або дорівнює 10
			suma += array[i]; //то до суми додаємо поточне число
		}
	}
	return suma; //повернути суму двоцифрових чисел масива
}
