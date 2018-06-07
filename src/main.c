#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

int main()
{
	int type, gen_type, step_for_caesar, i;
	char current_symbol, crypted_symbol;
	crypt_type_point:
	printf("выберите тип шифрования из приведенных ниже\n");
	printf("1. vernam \n 2. vigenere \n 3. caesar\n");
	scanf("%d", &type);
	if(type > 0 && type < 4) {
		if(type == 1 || type == 2) {
			gen_type_point:
			printf("выберите тип генерации случайных символов для ключа из приведенных ниже");
			printf("1. только английские символы \n 2. только русские символы \n 3. английские и русские символы \n");
			scanf("%d", &gen_type);
			if(gen_type > 0 && gen_type < 4) {
				while (current_symbol != EOF) {
					if(type == 1) {
						
						
					}
					else {
						
						
					}
					
				}
			}
			else {
				goto gen_type_point;
			}
		}
		else {
			while (current_symbol != EOF) {
				
				
			}
		}
	}
	else {
		goto crypt_type_point;
	}
    return 0;
}