#include "matrix.h"

void cipher_caesar(char * str, char * res_str, int value){
	int size = (int)strlen(str);
	for (int i = 0; i < size + 1; i++){
		int x = *(str + i);
		if (x == 32 || x == '\n' || x == '\t'){
			*(res_str + i) = (char)(32);
		}else if (x >= 65 && x <= 90 - value){
			*(res_str + i) = (char)(x + value);
		}else if (x >= 97 && x <= 122 - value) {
			*(res_str + i) = (char)(x + value);
		}else if (islower(x) && x + value > 122){
			*(res_str + i) = (char)(x - 26 + value);
		}else if (isupper(x) && x + value > 90) {
			*(res_str + i) = (char)(x - 26 + value);
		}else {
			*(res_str + i) = (char)(x);
		}
	}
}