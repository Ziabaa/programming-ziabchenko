#include "pyramid.h"

void write_to_file(char * file_name, char * text, char * mode){
	if (strcmp(mode, "r") == 0){
		fprintf(stderr,"Function 'write_to_file' is not for reading the file\n");
		exit(1);
	}
	FILE * file_point = fopen(file_name, mode);
	if (NULL == file_point) {
		printf("File can`t be opened, %s\n", strerror(errno));
		exit(1);
	}
	fprintf(file_point, "%s", text);
	fclose(file_point);
}

void read_from_file (char * file_name, int * x, int * y){
	FILE * ex_file = fopen(file_name, "r");
	if (NULL == ex_file) {
		printf("File can`t be opened, %s\n", strerror(errno));
		exit(1);
	}
	fscanf(ex_file, "%d %d", x, y);
	fclose(ex_file);
}
void print_pyramid(char * file_name, int width, int height){
	write_to_file(file_name, "", "w");
	if (width != (height * 2) - 1){
		fprintf(stderr, "Not correct size\n");
		exit(1);
	}
	int space;
	int star = 1;
	space = width - height + 1;
	printf("\n");
	while(space > 0 ){
		for(int y = space - 1; y != 0; y--){
			printf(" ");
			write_to_file(file_name, " ", "a");
		}
		for(int k = star; k != 0; k--){
			printf("*");
			write_to_file(file_name, "*", "a");
		}
		printf("\n");
		write_to_file(file_name, "\n", "a");

		star += 2;
		space--;
	}
}