#include <stdio.h>
#include "Viginer.h"

char viginer_in(char string, char f, short lang)
{
    char new_ssq; //переменная для шифрования

    //условия для шифрования

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z') ||
        (string >= 'а' && string <= 'я') || (string >= 'А' && string <= 'Я')) {
        new_ssq = string + f;
        
        //исключение возможности выхода за пределы используемого алфавита
        
        if ((new_ssq > 'Z' && new_ssq < 'a') || (new_ssq > 'z' && new_ssq < 'А') ||
            (new_ssq > 'я') {
            if (lang == 1) {
                new_ssq = new_ssq - 26;
            } else {
                new_ssq = new_ssq - 33;
            }
        }
    }
    return new_ssq;
}