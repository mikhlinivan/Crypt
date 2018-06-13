#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

char vernam_decrypt(char string, char key) {
	char decrypted;
	if(string ^ key >= 'a' && string^ key <= 'z') || (string ^ key >= 'A' && string ^ key <= 'Z')
	|| (string ^ key >= 'а' && string ^ key <= 'я')||(string >= 'А' ^ key && string ^ key <= 'Я')) {
		decrypted = string ^ key;
	}
	else {
		decrypted = string;
	}
	return decrypted;
}