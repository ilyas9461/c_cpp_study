/* Structures: fonksiyonlara yapının adresi ile geçirilmesi.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds *money); /* argument is a pointer */

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};

	printf("Stan has a total of $%.2f.\n", sum(&stan));

	getchar();
	return 0;
}

double sum(const struct funds * money)
{
	return(money->bankfund + money->savefund);
}



