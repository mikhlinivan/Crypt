#include <stdio.h>
#include "Viginer.h"
#include "locale.h"

char viginer_out(char string, char f)
{
    setlocale(LC_ALL, "Rus");
    char new_ssq; //переменная для дешифрования

    //условия для шифрования

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z') ||
        (string >= 'а' && string <= 'я') || (string >= 'А' && string <= 'Я')) {

        if (f >= 'A' && f <= 'z') {
            new_ssq = string - (f - 'a' + 1);
        } else if (f >= 'A' && f <= 'Z') {
            new_ssq = string - (f - 'A' + 1);
        } else if (f >= 'а' && f <= 'я') {
            new_ssq = string - (f - 'а' + 1);
        } else if (f >='А' && f <= 'Я') {
            new_ssq = string - (f - 'А' + 1);
        }

        //исключение возможности выхода за пределы используемого алфавита

        while ((new_ssq > 'Z' && new_ssq < 'a') || (new_ssq > 'z' && new_ssq < 'А') ||
            (new_ssq < 'A')) {

                if (string >= 'A' && string <='Z' && new_ssq < 'A') {
                    new_ssq = new_ssq + 26;
                } else if (string >= 'a' && string <= 'z' && new_sqq < 'a') {
                    new_ssq = new_ssq + 26;
                } else if (string >= 'а' && string <='я' && new_ssq  < 'а') {
                    new_ssq = new_ssq + 32;
                } else if (string >= 'А' && string <= 'Я' && new_ssq < 'А') {
                    new_ssq = new_ssq + 32;
                }
        }
        return new_ssq;
    }
    return string;
}
