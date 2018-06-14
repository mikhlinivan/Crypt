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
	}
	else {
		if(gen_type == 1) {
			srand ( time(NULL) );
			a = rand() % (26);
			symb = 'A' + a;
		}
	}
	return symb;
}