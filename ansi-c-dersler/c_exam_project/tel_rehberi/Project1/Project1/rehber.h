/* Reheber Kitsplýðý : .....*/

#ifndef REHBER_H_
#define REHBER_H_

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

#define ADI			0
#define SOYADI		1
#define TEL			2
#define ALAN_KODU	3

#define RAW_DOSYA		4
#define FORMATLI_DOSYA	5

#define RAW_DOSYA "tel.dat"

struct tel_rehberi {

	char isim[50];
	char soy_isim[50];
	char ulke_kodu[5];	//+1 null karakter
	char alan_kodu[5];
	char tel[10];		//boþluk ve null karkter dahil

};

typedef struct tel_rehberi tel_reh_tip;

//int id = 0;
extern int mesaj;

void strBuyukHarfCevir(char* s2);
void birTusaBas();
int dosyaSatirSysGetir(const char* dosya_adi);
void diziArayaKarakterKoy(char* arr, int location, char ch);
char* s_gets(char* st, int n);
void strKucukHarfCevir(char* s);


int menuOlustur(void);

tel_reh_tip* dosya_oku(const char* dosya_yol, int* satir_al);

void struct_swap(tel_reh_tip* a, tel_reh_tip* b);

void struct_sirala(tel_reh_tip* _rehber, int sayi, bool sirala_yon, int sirala_alan);



void ilkDosayaOlustur(const char* dosya_yol);

void rehberiListele(int bicim);

void rehbereKayitEkle(const char* dosya_yol);

void RehberdeAra();
void RehberdenSil();

void RehberDuzenle();
void sil_2_dosya();

#endif
