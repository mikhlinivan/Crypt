#include <stdio.h>
#include "caesar.h"
#include <locale.h>

char caesar_out(char string, int key) {
    setlocale(LC_ALL, "Rus");
    char new_ssq;

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z') ||
        (string >= 'а' && string <= 'я') || (string >= 'А' && string <= 'Я')) {
                New_ssq = string - key;

                if (string >= 'A' && string <='Z' && new_ssq > 'Z') {
                    new_ssq = new_ssq + 26;
                    }
                else if (string >= 'a' && string <= 'z' && new_ssq > 'z') {
                    new_ssq = new_ssq + 26;
                    }
                else if (string >= 'а' && string <='я' && new_ssq  > 'я') {
                    new_ssq = new_ssq + 32;
                    }
                else if (string >= 'А' && string <= 'Я' && new_ssq > 'Я') {
                    new_ssq = new_ssq + 32;
                    }
            return new_ssq;
    }

    return string;
}

