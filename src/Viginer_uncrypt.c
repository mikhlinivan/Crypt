#include <stdio.h>
#include <Viginer.h>

char viginer_out(char string, char f, short lang)
{
    char new_ssq; //переменная для дешифрования

    //условия для шифрования

    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z') ||
            (string >= 'а' && string <= 'я') || (string >= 'А' && string <= 'Я')) {
        new_ssq = string - f;
        
        //исключение возможности выхода за пределы используемого алфавита
        
        if ((string >= 'Z' && string <= 'a') || (string >= 'z' && string <= 'А') ||
                (string >= 'я') {
            if(lang == 1) {
                new_ssq = new_ssq + 26;
            } else {
                new_ssq = new_ssq + 33;
            }
        }
    }
    return new_ssq;
}
