// girilen 3 sayı ile işlemler enb enk
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sayi1, sayi2;
char girdi[10];
int main(void)
{

	printf("bir sayi girin");
	scanf("%d %d", &sayi1, &sayi1);
	if (sayi1 < sayi2)
	{
		printf("\n%d", sayi1);
	}
	if (sayi2 < sayi1)
	{
		printf("\n%d", sayi2);
	}
	if (sayi2 == sayi1)
	{
		printf("\nesit");
	}

	getch(); // enter tuşu basılana kadar algılar
	return 0;
}
