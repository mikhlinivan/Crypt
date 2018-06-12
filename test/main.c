#define CTEST_MAIN

#include <ctest.h>
#include "Viginer.h"
#include "caesar.h"
#include "vernam_crypt.h"
#include <locale.h>

CTEST (viginer, uncrypt)
{
    setlocale(LC_ALL, "russian_russia.1251");
    char string = 'а';
    char f = 'б';
    short lang = 1;
    char result = viginer_in(string, f, lang);
    char expected = 'в';
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "rus");
    int test_result = ctest_main(argc, argv);
    return test_result;
}