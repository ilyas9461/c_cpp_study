//girilen 3 sayı ile işlemler enb enk
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float p=3.14159,sayi1;
char girdi[10];
int main(void)
{
   printf("yaricap girin sayı girin");
   scanf("%f", &sayi1);
   float cap=2*sayi1;
   float alan=(sayi1*sayi1)*p;
   float c=2*p*sayi1;
	
   printf("\n cap :%f alan :%f  cevre:%f",cap, alan, c);
   getch();                                      //enter tuşu basılana kadar algılar

   return 0;
}

