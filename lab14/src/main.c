#include "pyramid.h"

int main(){
	int height, width;
	read_from_file("assets/input.txt", &height, &width);
	print_pyramid("assets/output.txt", width, height);
	return 0;

}