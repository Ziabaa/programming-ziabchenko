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

int sum_dooble_number_of_array(const int array[], int size)
{
	int suma = 0;
	for (int i = 0; i < size; i++) {
		if ((array[i] >= 10) || (array[i] < -9)) {
			suma += array[i];
		}
	}
	return suma;
}
