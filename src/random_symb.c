#include "stdio.h"
#include "vernam_crypt.h"
#include "locale.h"
setlocale(LC_ALL, "Rus");

char rand_symb_gen (int gen_type) 
{
	int a,b;
	char symb;
	b = rand % (1);
	if(b == 0) {
		if(gen_type == 1) {
			a = rand() % (26);
			symb = 'a' + a;
		}
		if(gen_type == 2) {
			a = rand() % (31);
			symb = 'а' + a;
		}
		if(gen_type == 3) {
			if((rand() % (1)) == 1) {
				a = rand() % (26);
				symb = 'a' + a;
			}
			else {
				a = rand % (31);
				symb = 'а' + a;
			}
		}
	}
	else {
		if(gen_type == 1) {
			a = rand() % (26);
			symb = 'A' + a;
		}
		if(gen_type == 2) {
			a = rand() % (31);
			symb = 'А' + a;
		}
		if(gen_type == 3) {
			if((rand() % (1)) == 1) {
				a = rand() % (26);
				symb = 'A' + a;
			}
			else {
				a = rand % (31);
				symb = 'А' + a;
			}
		}
	}
	return symb;
}