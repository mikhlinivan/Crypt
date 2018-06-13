#include <stdio.h>
#include "caesar.h"
#include <locale.h>
setlocale(LC_ALL, "Rus");

char caesar_in(char *string, int key) {
    char new_ssq;
    int key;

    if ((*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'Z') ||
	(*string >= 'а' && *string <= 'я') || (*string >= 'А' && *string <= 'Я')) {
		New_ssq = string + key;
	    }
                if (string >= 'A' && string <='Z' && new_ssq > 'Z') {
                    new_ssq = new_ssq - 26;
		    }
		else if (string >= 'a' && string <= 'z' && new_sqq > 'z') {
                    new_ssq = new_ssq - 26;
                    }
		else if (string >= 'а' && string <='я' && new_ssq  > 'я') {
                    new_ssq = new_ssq - 32;
                    }
		else if (string >= 'А' && string <= 'Я' && new_ssq > 'Я') {
                    new_ssq = new_ssq - 32;
                    }
            }
            return new_ssq;
    }

    return string;
}
