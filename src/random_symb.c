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
			a = rand() % (27);
			symb = 'a' + a - 1;
		}
		if(gen_type == 2) {
			srand ( time(NULL) );
			a = rand() % (32);
			symb = 'а' + a - 1;
		}
		if(gen_type == 3) {
			srand ( time(NULL) );
			if((rand() % (2)) == 1) {
				srand ( time(NULL) );
				a = rand() % (27);
				symb = 'a' + a - 1;
			}
			else {
				srand ( time(NULL) );
				a = rand() % (32);
				symb = 'а' + a - 1;
			}
		}
	}
	else {
		if(gen_type == 1) {
			srand ( time(NULL) );
			a = rand() % (27);
			symb = 'A' + a - 1;
		}
		if(gen_type == 2) {
			srand ( time(NULL) );
			a = rand() % (32);
			symb = 'А' + a - 1;
		}
		if(gen_type == 3) {
			srand ( time(NULL) );
			if((rand() % (2)) == 1) {
				srand ( time(NULL) );
				a = rand() % (27);
				symb = 'A' + a - 1;
			}
			else {
				srand ( time(NULL) );
				a = rand() % (32);
				symb = 'А' + a - 1;
			}
		}
	}
	return symb;
}