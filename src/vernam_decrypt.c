#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"


char vernam_decrypt(char string, char key) {
	setlocale(LC_ALL, "Rus");
	char decrypted;
	if((string ^ key >= 'a' && string^ key <= 'z') || (string ^ key >= 'A' && string ^ key <= 'Z')) {
		decrypted = string ^ key;
	}
	else {
		decrypted = string;
	}
	return decrypted;
}