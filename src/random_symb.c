#include "stdio.h"
#include "stdlib.h"
#include "vernam_crypt.h"
#include "locale.h"

char randsymbgen (int gen_type) 
{
	setlocale(LC_ALL, "Rus");
	srand ( time(NULL) );
	int a,b;
	char symb;
	b = rand() % 2;
	if(b == 0) {
		if(gen_type == 1) {
			srand ( time(NULL) );
			a = rand() % (26);
			symb = 'a' + a;
		}
		if(gen_type == 2) {
			srand ( time(NULL) );
			a = rand() % (31);
			symb = 'а' + a;
		}
		if(gen_type == 3) {
			srand ( time(NULL) );
			if((rand() % (2)) == 1) {
				srand ( time(NULL) );
				a = rand() % (26);
				symb = 'a' + a;
			}
			else {
				srand ( time(NULL) );
				a = rand() % (31);
				symb = 'а' + a;
			}
		}
	}
	else {
		if(gen_type == 1) {
			srand ( time(NULL) );
			a = rand() % (26);
			symb = 'A' + a;
		}
		if(gen_type == 2) {
			srand ( time(NULL) );
			a = rand() % (31);
			symb = 'А' + a;
		}
		if(gen_type == 3) {
			srand ( time(NULL) );
			if((rand() % (2)) == 1) {
				srand ( time(NULL) );
				a = rand() % (26);
				symb = 'A' + a;
			}
			else {
				srand ( time(NULL) );
				a = rand() % (31);
				symb = 'А' + a;
			}
		}
	}
	return symb;
}