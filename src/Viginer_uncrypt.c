#include <stdio.h>
#include "Viginer.h"
#include "locale.h"

char viginer_out(char string, char f)
{
    setlocale(LC_ALL, "Rus");
    char new_ssq; //переменная для дешифрования

    //условия для шифрования

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z')) {

        if (f >= 'A' && f <= 'z') {
            new_ssq = string - (f - 'a' + 1);
        } else if (f >= 'A' && f <= 'Z') {
            new_ssq = string - (f - 'A' + 1);
        }

        //исключение возможности выхода за пределы используемого алфавита

        while ((new_ssq > 'Z' && new_ssq < 'a') || (new_ssq < 'A')) {

                if (string >= 'A' && string <='Z' && new_ssq < 'A') {
                    new_ssq = new_ssq + 26;
                } else if (string >= 'a' && string <= 'z' && new_ssq < 'a') {
                    new_ssq = new_ssq + 26;
                }
        }
        return new_ssq;
    }
    return string;
}
