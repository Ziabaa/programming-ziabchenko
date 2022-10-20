//Визначити, чи є ціле 6-значне число "щасливим" квитком ("щасливий квиток" – квиток, в якому сума першої половини чисел номера дорівнює сумі другої половини.
int main()
{
	int number = 234027; //дане 6-значне число
	int first_number = number / 100000; //перше число
	int second_number = (number / 10000) % 10; //друге число
	int third_number = (number / 1000) % 10; //третьє число
	int fourth_number = (number / 100) % 10; //четверте число
	int fifth_number = (number / 10) % 10; //п'яте число
	int sixth_number = number % 10; //шосте число
	int sum_first_tree_number = first_number + second_number + third_number; //сума перших трьох чисел
	int sum_second_tree_number = fourth_number + fifth_number + sixth_number; //сума других трьох чисел
	int result = 0; //0->false    1->true

	if (sum_first_tree_number == sum_second_tree_number) { //сума перших, повинна дорівнювати сумі друих
		result = 1; //якщо виконується, тотрезультат 1
	}

	return 0;
}
