#include "stdio.h"
#include "vernam_crypt.h"
#include "Viginer.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

int main()
{
	FILE *out_text, *decipher_text, *key_i;
	key_i = fopen("key.txt.", "a");
	out_text = fopen("crypted.txt", "w");
	decipher_text = fopen("decrypt.txt", "w");
	int type, gen_type, step_for_caesar, act_type, i;
	char current_symbol, crypted_symbol, key;
	act_pick:
	printf("выберите что будете делать с текстом из предложенных ниже вариантов \n");
	printf("1.шифровать \n 2.дешифровать \n");
	scanf("%d", &act_type);
	if(act_type == 1) {
		crypt_type_point:
		printf("\n выберите тип шифрования из приведенных ниже\n");
		printf("1. vernam \n 2. vigenere \n 3. caesar\n");
		scanf("%d", &type);
		switch (type) {
			case 1:
				gen_type_point:
				printf("\n выберите тип генерации случайных символов для ключа из приведенных ниже \n");
				printf("1. только английские символы \n 2. только русские символы \n 3. английские и русские символы \n");
				scanf("%d", &gen_type);
				if(gen_type > 0 && gen_type < 4) {
					while (current_symbol != EOF) {
						key = rand_symb_gen(gen_type);
						crypted_symbol = vernam(&current_symbol, key);
						fprintf (key_i,"%c", key);
						fprintf(out_text, "%c", crypted_symbol);//запись в файл
						//смещение символа по изначальному файлу
					}
				}
				else {
					goto gen_type_point;
				}
				break;
			case 2:
				while (current_symbol != EOF) {
					crypted_symbol = viginer_in(current_symbol, crypt_key, language);
					fprintf(out_text, "%c", crypted_symbol);
					//смещение символа по изначальному файлу
				}
				break;
			case 3:
				while (current_symbol != EOF) {
					crypted_symbol = //то на что кирилл заменит encrypt
					fprintf(out_text, "%c", crypted_symbol);
					//смещение символа по изначальному файлу
				}
				break;
			case default:
				goto crypt_type_point;
		}
	}
	else if(act_type == 2) {
		decrypt_type_point:
		printf("\n выбереите изначальный тип шифрования\n");
		printf("1. vernam \n 2. vigenere \n 3. caesar\n");
		scanf("%d", &type);
		switch (type) {
			case 1:
				while(current_symbol != EOF) {
					
					current_symbol = vernam_decrypt(&current_symbol, key);
					fprintf(decipher_text, "%c", current_symbol);//запись в файл
					//смещение символа по файлу
				}
				break;
			case 2:
				while(current_symbol != EOF) {
					current_symbol = viginer_out();
					fprintf(decipher_text, "%c", current_symbol);//запись в файл
					//смещение символа по файлу
				}
				break;
			case 3:
				while(current_symbol != EOF) {
					current_symbol = //то на что кирилл заменит decipher
					fprintf(decipher_text, "%c", current_symbol);//запись в файл
					//смещение символа по файлу
				}
				break;
			case default:
				goto decrypt_type_point;
		}
	}
	else {
		goto act_pick;
	}
	return 0;
}