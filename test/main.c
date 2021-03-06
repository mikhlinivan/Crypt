#define CTEST_MAIN

#include <ctest.h>
#include "Viginer.h"
#include "caesar.h"
#include "vernam_crypt.h"
#include <locale.h>
//Viginer in
CTEST (viginer, crypt)
{
    char string = 'a';
    char f = 'b';
    char result = viginer_in(string, f);
    char expected = 'c';
    ASSERT_EQUAL(expected, result);
}

CTEST (viginer, fail_crypt)
{
    char string = ',';
    char f = 'c';
    char result = viginer_in(string, f);
    char expected = ',';
    ASSERT_EQUAL(expected, result);
}

//Viginer out
CTEST (viginer, decrypt)
{
    char string = 'd';
    char f = 'c';
    char result = viginer_out(string, f);
    char expected = 'a';
    ASSERT_EQUAL(expected, result);
}

CTEST (viginer, fail_decrypt)
{
    char string = ' ';
    char f = 'c';
    char result = viginer_out(string, f);
    char expected = ' ';
    ASSERT_EQUAL(expected, result);
}

//vernam in
CTEST (vernam, crypt)
{
    char string;
    string = 'F';
    char f = 'b';
    char result = vernam(string, f);
    char expected = '$';
    ASSERT_EQUAL(expected, result);
}

CTEST (vernam, fail_crypt)
{
    char string;
    string = ' ';
    char f = '\0';
    char result = vernam(string, f);
    char expected = ' ';
    ASSERT_EQUAL(expected, result);
}

//vernam out

CTEST (vernam, decrypt)
{
    char string;
    string = '$';
    char f = 'b';
    char result = vernam_decrypt(string, f);
    char expected = 'F';
    ASSERT_EQUAL(expected, result);
}

CTEST (vernam, fail_decrypt)
{
    char string;
    string = ' ';
    char f = '\0';
    char result = vernam_decrypt(string, f);
    char expected = ' ';
    ASSERT_EQUAL(expected, result);
}

//caesar in

CTEST (caesar, crypt)
{
    char string;
    string = 'a';
    int f = 5;
    char result = caesar_in(string, f);
    char expected = 'f';
    ASSERT_EQUAL(expected, result);
}

CTEST (caesar, fail_crypt)
{
    char string = '.';
    int f = 5;
    char result = caesar_in(string, f);
    char expected = '.';
    ASSERT_EQUAL(expected, result);
}
//caesar out

CTEST (caesar, decrypt)
{
    char string;
    string = 'f';
    int f = 5;
    char result = caesar_out(string, f);
    char expected = 'a';
    ASSERT_EQUAL(expected, result);
}

CTEST (caesar, fail_decrypt)
{
    char string = ' ';
    int f = 5;
    char result = caesar_out(string, f);
    char expected = ' ';
    ASSERT_EQUAL(expected, result);
}


int main(int argc, const char** argv)
{
    setlocale(LC_ALL, "rus");
    int test_result = ctest_main(argc, argv);
    return test_result;
}