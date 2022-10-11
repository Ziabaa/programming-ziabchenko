int main()
{
#define PI 3.14f
	float radius = 3.0f;
	float height = 8.0f;
	float volume_cylinder = PI * radius * radius * height;
	//
	float time = 5.0f;
	float acceleration = 3.0f;
	float speed_0 = 2.0f;
	float lenght = speed_0 * time + ((acceleration * time * time) / 2.0f);
	//
	float area_circle = PI * radius * radius;
	float volume_circle = (4 * PI * radius * radius) / 3.0f;
	//
#define DUIM 2.54f
	float duims = 5.0f;
	float cantimetre = 16.0f;
	float cm_to_duims = (float)cantimetre / DUIM;
	float duims_to_cm = (float)duims * DUIM;
	//
	float sidle_square = 5.0f;
	float area_square = sidle_square * sidle_square;
	float volume_square = 4 * sidle_square;
	//
#define RADIAN 180.0f
	float radians = 545;
	float angle_degree = (float)radians / RADIAN;
	//
	float celsius_value = 46.0f;
	float fahrenheit_value = 212.0f;
	float cels_to_fahr = celsius_value * 1.8f + 32;
	float fahr_to_cels = (fahrenheit_value - 32) / 1.8f;
	//
	float volume_cube = height * height * height;
	float surface_area_cube = 6 * (height * height);
	//
	float step = 4;
	float first_number = 12;
	float n_number = 45;
	float value_n = first_number + step * (n_number - 1);
	//
	int tree_digit = 395;
	int two_digit = tree_digit / 10;
	int second_number = two_digit % 10;
	//
	int four_digit = 3827;
	int first_numb = four_digit / 1000;
	int second_numb = (four_digit / 100) % 10;
	int third_numb = (four_digit % 100) / 10;
	int fourth_numb = four_digit % 10;
	//
#define EURO 43
#define USD 42
#define ZLT 8
	int hrivni = 23864;
	float euro = hrivni / (float)EURO;
	float usd = hrivni / (float)USD;
	float zloty = hrivni / (float)ZLT;
	//
	int resistances_1 = 34;
	int resistances_2 = 23;
	int resistances_3 = 41;
	float general_resistance = (resistances_1 * resistances_2 * resistances_3) / (float)(resistances_1 + resistances_2 + resistances_3);
	return 0;
}
