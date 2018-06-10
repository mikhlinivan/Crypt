#include <stdio.h>
#include <Viginer.h>

char viginer_in(char *string, char f, short lang)
{
    char new_ssq; //переменная для шифрования

    //условия для шифрования

    if((*string >= 'a' && *string <= 'z') || (*string >= 'A' && *string <= 'A') ||
    (*string >= 'а' && *string <= 'я') || (*string >= 'А' && *string <= 'Я')) {
        new_ssq = *string + f;
        
        //исключение возможности выхода за пределы используемого алфавита
        
        if((*string >= 'Z' && *string <= 'a') || (*string >= 'z' && *string <= 'А') ||
        (*string >= 'я') {
            if(lang == 1) {
                new_ssq = new_ssq - 26;
            } else {
                new_ssq = new_ssq - 33;
            }
        }
    }
    return new_ssq;
}