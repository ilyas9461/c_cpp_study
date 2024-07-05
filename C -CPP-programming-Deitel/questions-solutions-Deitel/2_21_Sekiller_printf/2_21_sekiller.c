//girilen 3 sayı ile işlemler enb enk
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int sayi1,sayi2,sayi3;
char girdi[10];
int main(void)
{

	printf("*********\n");

	int toplama=sayi1+sayi2+sayi3;
	int  c=sayi1-sayi2-sayi3;
	int  carpma=sayi1*sayi2*sayi3;
	int  bolme=sayi1/sayi2/sayi3;

	if(sayi1<sayi3&&sayi1<sayi2){
		if (sayi2<sayi3)
		{
			printf("\n 1%d,2%d,&3%d ", sayi1,sayi2);
		}
		else{
			printf("\n 1%d,2%d,3%d ", sayi1,sayi3,sayi2);
		}
		}
		else if(sayi2<sayi1&&sayi2>sayi3&&sayi1<sayi3){
           if(sayi3>sayi1){
		printf("\n 1%d,2%d,3%d ", sayi2,sayi1,sayi3);
		   }
		else
		{
			printf("\n 1%d,2%d,3%d ", sayi2,sayi3,sayi1);
		}
		
		}
	else{
		if(sayi1<sayi2){
			printf("\n 1%d,2%d,3%d ", sayi3,sayi1,sayi2);
		}
		else
		{
			printf("\n 1%d,2%d,3%d ", sayi3,sayi2,sayi1);
		}
		
	}
	
	printf("\n toplama;%d,cıkarma%d ,carpma;%d,bolme;%d", toplama, c, carpma, bolme);
	getch();                                      //enter tuşu basılana kadar algılar
	return 0;
}

