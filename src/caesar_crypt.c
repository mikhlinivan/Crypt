#include <stdio.h>
#include "caesar.h"
#include <locale.h>

char caesar_in(char string, int key) {
    char new_ssq;

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z')) {
		new_ssq = string + key;

                if (string >= 'A' && string <='Z' && new_ssq > 'Z') {
                    new_ssq = new_ssq - 26;
		    }
		else if (string >= 'a' && string <= 'z' && new_ssq > 'z') {
                    new_ssq = new_ssq - 26;
                    }
            return new_ssq;
    }
    return string;
}
