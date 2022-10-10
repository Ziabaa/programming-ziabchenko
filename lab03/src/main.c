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
	return 0;
}
