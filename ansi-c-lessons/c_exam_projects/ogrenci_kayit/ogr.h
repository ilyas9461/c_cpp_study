
#ifndef OGR_H_
#define OGR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define konsolTemizle() system("CLS")	//Konsolu temizlemek için oluþturulmuþ makro.


#define KUCUK_TEN_BUYUGE true
#define BUYUK_TEN_KUCUGE false


struct OgrenciNotlari {

	char isim[50];
	char soy_isim[50];
	char dersadi[20];//+1 null karakter
	float not1;
	float not2;		//boþluk ve null karkter dahil
	float not3;
	float ortalama;
};

typedef struct OgrenciNotlari ogrenciTip;


int dosyaSatirSysGetir(const char* dosya_adi);
void YeniOgrenciEkle();
int menuOlustur(void);
void ilkDosayaOlustur(const char* dosya_yol);
void Listele();

void struct_swap(ogrenciTip* a, ogrenciTip* b);
ogrenciTip* dosya_oku(const char* dosya_yol, int* satir_al);

void strBuyukHarfCevir(char* s);
void strKucukHarfCevir(char* s);
void struct_sirala(ogrenciTip* ogrenciler, int sayi, bool sirala_yon, int sirala_alan);
char* s_gets(char* st, int n);
void birTusaBas();
void ogrenciAra();
void ogrenciSil();
void Duzenle();



#endif