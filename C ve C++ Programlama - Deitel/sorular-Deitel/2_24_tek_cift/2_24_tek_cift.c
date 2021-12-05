// girilen 3 sayı ile işlemler enb enk
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
	printf("1 sayi girin");
	scanf("%d", &sayi1);
	if (sayi1 % 2 == 0)
	{
		printf("\n cift sayi");
	}
	else
	{
		printf("\n tek sayi");
	}
	getch(); // enter tuşu basılana kadar algılar
	return 0;
}
