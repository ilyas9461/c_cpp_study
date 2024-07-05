// girilen 3 sayı ile işlemler enb enk
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float o = 0.0;
int sayi1;
int girdi[10];
int toplam = 0;
int main(void)
{
	printf("sayilar sayi girin : ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &girdi[i]);

		printf("\n%d ", girdi[i]);
		if (girdi[i] == 9999)
		{

			for (int s = 0; s < i; s++)
			{
				toplam += girdi[s];
			}
			o = (float)toplam / (i);
			break;
		}
	}

	printf("\n ortalama;%f", o);

	getch(); // enter tuşu basılana kadar algılar
	return 0;
}
