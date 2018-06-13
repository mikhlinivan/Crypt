#include <stdio.h>
#include <stdlib.h>
#include "vernam_crypt.h"
#include "Viginer.h"
#include "caesar.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE *out_text, *decipher_text, *key_i, *text;
	text = fopen("users_text.txt", "r");
	out_text = fopen("crypted.txt", "w");
	decipher_text = fopen("decrypt.txt", "w");
	int type, gen_type, step_for_caesar, act_type, i, h, l;
	char current_symbol, crypted_symbol, key;
	char *key_m;
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
				key_i = fopen("key.txt", "w");
				gen_type_point:
				printf("\n выберите тип генерации случайных символов для ключа из приведенных ниже \n");
				printf("1. только английские символы \n 2. только русские символы \n 3. английские и русские символы \n");
				scanf("%d", &gen_type);
				if(gen_type > 0 && gen_type < 4) {
					current_symbol = fgets(text);
					while (current_symbol != EOF) {
						key = randsymbgen(gen_type);
						crypted_symbol = vernam(current_symbol, key);
						if(crypted_symbol == current_symbol) {
							key = '\0';
						}
						fprintf (key_i,"%c", key);//запись ключа в файл
						fprintf(out_text, "%c", crypted_symbol);//запись в файл
						current_symbol = fgetc(text);
					}
				}
				else {
					goto gen_type_point;
				}
				fclose(key_i);
				break;
			case 2:
				key_i = fopen("key.txt", "w");
				printf("Введите длину массива: ");
				scanf("%d", &l);
				key_m = (char*)malloc((l + 1) * sizeof(char)); //создание массива под ключ
				for(h = 0; h < l; h++) {
					key_m[h] = randsymbgen(gen_type); //генрация ключа
				}
				h = 0;
				current_symbol = fgets(text);
				while (current_symbol != EOF) {
					if(h > l) {
						h = h - l;
					}
					crypted_symbol = viginer_in(current_symbol, key_m[h]);
					h++;
					fprintf(out_text, "%c", crypted_symbol);
					current_symbol = fgets(text);
				}
				break;
			case 3:
				key_i = fopen("key.txt", "w");
				printf("введите шаг для шифра цезаря \n");
				scanf("%d", &step_for_caesar);
				fprintf(key_i, "%d", step_for_caesar);
				current_symbol = fgetc(text);
				while (current_symbol != EOF) {
					crypted_symbol = caesar_in(current_symbol, step_for_caesar); //то на что кирилл заменит encrypt
					fprintf(out_text, "%c", crypted_symbol);
					current_symbol = fgetc(text);
				}
				fclose(key_i);
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
				key_i = fopen("key.txt.", "r");
				key = fgets(key_i);
				current_symbol = fgets(text);
				while(current_symbol != EOF) {
					crypted_symbol = vernam_decrypt(current_symbol, key);
					fprintf(decipher_text, "%c", crypted_symbol);//запись в файл
					current_symbol = fgets(text);
					key = fgets(key_i);
				}
				fclose(key_i);
				break;
			case 2:
				key_i = fopen("key.txt.", "r");
				key_m = (char*)malloc((l + 1) * sizeof(char)); //создание массива под ключ
				for(h = 0; h < l; h++) {
					key_m[h] = fgetc(key_i);//чтение ключа
				}
				h = 0;
				current_symbol = fgets(text);
				while (current_symbol != EOF) {
					if(h > l) {
						h = h - l;
					}
					crypted_symbol = viginer_out(current_symbol, key_m[h]);
					h++;
					fprintf(decipher_text, "%c", crypted_symbol);//запись в файл
					current_symbol = fgets(text);
				}
				break;
			case 3:
				key_i = fopen("key.txt.", "r");
				fscanf(key_i, "%d", &step_for_caesar);
				current_symbol = fgets(text);
				while(current_symbol != EOF) {
					crypted_symbol = caesar_out(current_symbol, step_for_caesar); //то на что кирилл заменит decipher
					fprintf(decipher_text, "%c", crypted_symbol);//запись в файл
					current_symbol = fgets(text);//смещение символа по файлу
				}
				fclose(key_i);
				break;
			case default:
				goto decrypt_type_point;
		}
	}
	else {
		goto act_pick;
	}
	fclose(text);
	fclose(out_text);
	fclose(decipher_text);
	return 0;
}
