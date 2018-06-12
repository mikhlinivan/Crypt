#include <stdio.h>
#include <locale.h>
#include "caesar.h"

#define ENG 26
#define RUS 32

void caesar_crypt(int n)
{
	FILE *fp1, *fp2;
	open(&fp1, "input.txt", "r");
	open(&fp2, "output.txt", "w");
	int flag;
	char c;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag = 0; //обработан ли текущий символ
		if (c >= 'A' && c <= 'z')
		{
			c = c +(n % ENG);
			if (c > 'Z') c = 'A' + (c - 'Z') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c +(n % ENG);
			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'А' && c <= 'Я')
		{
			c = c + (n % RUS);
			if (c > 'Я') c = 'А' + (c - 'Я') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c >='а' && c <= 'я')
		{
			c = c + (n % RUS);
			if (c > 'я') c = 'a' + (c - 'я') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf (fp2, "%c", c);
		c = getc(fp1);
	}
	fclose (fp1);
	fclose (fp2);
}

void caesar_decrypt(int n)
{
	FILE *fp1, *fp2;
	open(&fp1, "input.txt", "r");
	open(&fp2, "output.txt", "w");
	int flag;
	char c;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag =0;
		if (c >= 'A' && c <= 'Z')
        	{
            		c = c - (n % ENG);
            		if (c < 'A') c = 'Z' - ('A' - c) + 1;
            		fprintf (fp2, "%c", c);
            		flag = 1;
        	}
        	if (c >= 'a' && c <= 'z')
        	{
            		c = c - (n % ENG);
            		if (c < 'a') c = 'z' - ('a' - c) + 1;
            		fprintf (fp2, "%c", c);
            		flag = 1;
        	}
        	if (c >= 'А' && c <= 'Я')
        	{
            		c = c - (n % RUS);
            		if (c < 'А') c = 'Я' - ('А' - c) + 1;
            		fprintf (fp2, "%c", c);
            		flag = 1;
        	}
        	if (c >= 'а' && c <= 'я')
        	{
            		c = c - (n % RUS);
            		if (c < 'а') c = 'я' - ('а' - c) + 1;
            		fprintf (fp2, "%c", c);
            		flag = 1;
        	}
        	if (!flag) fprintf (fp2, "%c", c);
        	c = getc(fp1);
    	}
    	close (fp1);
    	close (fp2);
}
