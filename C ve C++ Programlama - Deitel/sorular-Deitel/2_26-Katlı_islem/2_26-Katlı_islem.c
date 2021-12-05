
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sayi1, sayi2;

int main(void)
{

	printf("3 sayi girin");
	scanf("%d %d", &sayi1, &sayi2);
	if (sayi1 % sayi2 == 0)
	{
		printf("\n katıdır:+");
	}
	else
	{
		printf("\n katı degil:-");
	}

	getch(); // enter tuşu basılana kadar algılar
	return 0;
}
