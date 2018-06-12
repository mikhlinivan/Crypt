#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

char vernam (char *string, int gen_type)
{
	char crypt_string; //сивол куда будет идти шифрование на промежуточном этапе
	int i; //счетчик для цикла
	if((*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'Z')
	|| (*string >= 'а' && *string <= 'я')||(*string >= 'А' && *string <= 'Я')) {
		crypt_string = *string ^ rand_symb_gen(gen_type);
	}
return crypt_string;
}
	