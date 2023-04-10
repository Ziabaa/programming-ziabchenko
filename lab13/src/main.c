#include "matrix.h"


int main(){
	char input_string[1000];
	printf("Enter the text which does not exceed 1000 symbol: ");
	fgets(input_string, 1000, stdin);
	printf("%s\n", input_string);
	printf("Enter the value how much to move: ");
	int value;
	scanf("%d", &value);
	char * res = malloc(sizeof(char) * (strlen(input_string) + 1));
	cipher_caesar(input_string, res, value);
	printf("Result of ciphering: %s\n", res);
	free(res);
	return 0;
}