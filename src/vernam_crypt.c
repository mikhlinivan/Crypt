#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

char vernam (char *string, int gen_type)
{
	FILE *key;
	key = fopen("key.txt.", "a");
	char crypt_string, curr_key; //сивол куда будет идти шифрование на промежуточном этапе
	int i; //счетчик для цикла
	if((*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'Z')
	|| (*string >= 'а' && *string <= 'я')||(*string >= 'А' && *string <= 'Я')) {
		curr_key = rand_symb_gen(gen_type);
		crypt_string = *string ^ curr_key;
		fprintf (key,"%c", curr_key);
	}
	fclose(key);
	return crypt_string;
}
	