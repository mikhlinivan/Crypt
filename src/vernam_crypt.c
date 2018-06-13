#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"


char vernam (char string, char key)
{
	setlocale(LC_ALL, "Rus");
	char crypt_string;//сивол куда будет идти шифрование на промежуточном этапе
	int i; //счетчик для цикла
	crypt_string = string;
	if((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z')
	|| (string >= 'а' && string <= 'я')||(string >= 'А' && string <= 'Я')) {
		crypt_string = string ^ key;
	}
	return crypt_string;
}