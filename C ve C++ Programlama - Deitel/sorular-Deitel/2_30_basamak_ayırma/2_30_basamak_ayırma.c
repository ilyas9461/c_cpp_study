
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sayi1, sayi2, sayi3;
char girdi[10];

int main(void)
{

	printf("beş basamaklı sayı girin");
	scanf("%d", &sayi1);

	int bas1 = sayi1 % 10000 % 1000 % 100 % 10;
	int bas2 = sayi1 % 10000 % 1000 % 100 - bas1;
	int bas3 = sayi1 % 10000 % 1000 - bas2 - bas1;
	int bas4 = sayi1 % 10000 - bas3 - bas2 - bas1;

	printf("\n bas1;%d,bas2:%d ,bas3;%d,bas4;%d", bas1, bas2, bas3, bas4);
	getch(); // enter tuşu basılana kadar algılar
	return 0;
}
