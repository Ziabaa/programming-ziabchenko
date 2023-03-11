#include "lib.h"

int main()
{
#define ROZM 5
	int my_array[ROZM] = { 34, 12, 24, 7, 4 };
	int sum = sum_dooble_number_of_array(my_array, ROZM);
	int bancnotes = how_many_bancnotes_will_be_needed(34);
	return 0;
}
