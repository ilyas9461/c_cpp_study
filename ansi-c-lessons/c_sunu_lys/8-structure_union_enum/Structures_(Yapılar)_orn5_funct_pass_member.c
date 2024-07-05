/* Structures: fonksiyonlara yapı üyelerinin değer
   yoluyla geçirilmesi...*/

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

double sum(double, double);

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	printf("Stan has a total of $%.2f.\n",
		sum(stan.bankfund, stan.savefund));

	return 0;
}

/* adds two double numbers */
double sum(double x, double y)
{
	return(x + y);
}


