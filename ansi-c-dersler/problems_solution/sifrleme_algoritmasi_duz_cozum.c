/*
   lys_2020
   26/06/2020 
   VS-2019

   �ifreleme algoritmas�:

   Bir �ifreleme algoritmas�nda ki�inin ad-soyad�ndaki harflerin say�sal kar��l�klar� birbirleriyle 
   �arp�larak sonucun ortalamas� al�nm��t�r. Ortalama almak i�in �arp�m sonucu toplam harf say�s�na 
   b�l�nm��t�r.  Elde edilen say�n�n rakamlar�n�n ascii  kod kar��l�klar� toplanm�� ve toplam�n 
   sonucunda elde edilen say�n�n �n�ne ki�inin isminin ve soyisminin ilk harfleri aralar�na alt �izgi 
   konularak getirilmi� ve �ifre olarak belirlenmi�tir. Sisteme giri� �ifreleri sorgulan�rken �ifreler 
   bir veri taban�nda kaydedilmek yerine ad-soyad tan elde edilen de�ere g�re sorgulanmaktad�r.

   Buna g�re;
      a- Ki�inin ad-soyad bilgisine g�re �ifre de�erlerini elde edebilece�iniz,
      b- �ifre ekran�ndan ad-soyad ve elde edilen �ifre bilgisi girildi�inde  sisteme giri�

  yap�labilecek, bir program yaz�n�z.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    char ad[50] = { 0 };
    char soyad[50] = { 0 };

    unsigned long long carpim_ad = 1ll;
    unsigned long long carpim_soyad = 1ll;
    unsigned long long carpim_ort = 0;

    /*1- Kullan�c�dan giri� al*/
   	

    /*2- Ad-Soayad ta bulunan harflerin say�lar�n kar��l�klar�n� �arp.*/
    int len_ad = strlen(ad);
    int len_soyad = strlen(soyad);

    for (size_t i = 0; i < len_ad; i++)
    {
        carpim_ad *= (short)(ad[i]);
    }

    for (size_t i = 0; i < len_soyad; i++)
    {
        carpim_soyad *= (short)(soyad[i]);
    }

    /*3- �arp�m�n ortalamas�n� hesapla */
    unsigned long long toplam = len_ad+len_soyad;       //carpim_ad + carpim_soyad; 
    unsigned long long carpim = carpim_ad * carpim_soyad;

    carpim_ort = (carpim) / (toplam);

    /*4- �arp�m�n ortalamas�nda bulunan rakamlar�n saysal kar��l�klar�n� topla.*/
    char temp[100];
    int sayilar_toplam = 0;

    sprintf(temp, "%llu", carpim_ort);

    for (int i = 0; i < strlen(temp); i++)
    {
        sayilar_toplam += (int)temp[i];
    }

    memset(temp, '\0', sizeof(temp)); //clear temp 

    /*5- �ifreyi olu�tur.*/

    char sifre[20] = { 0 };

    sprintf(temp, "%u", sayilar_toplam);

    sifre[0] = ad[0];
    sifre[1] = '_';
    sifre[2] = soyad[0];
    sifre[3] = '_';

    for (size_t i = 0; i < strlen(temp); i++)
    {
        sifre[4 + i] = temp[i];
    }
    int sifre_son = 4 + (int)strlen(temp);
    sifre[sifre_son] = '\0';

    printf("\nUretilen SIFRE : %s\n", sifre);

    /* Kullan�nc�n�n siteme giri� yapmas�n� sa�la*/
    printf("\n*** SISTEME GIRIS YAPINIZ ***\n");
    // dizilerin i�eriklerini sil(resetle)
    for (size_t i = 0; i < sizeof(ad); i++)
        ad[i] = '\0';
    for (size_t i = 0; i < sizeof(soyad); i++)
        soyad[i] = '\0';
    for (size_t i = 0; i < sizeof(sifre); i++)
        sifre[i] = '\0';
    for (size_t i = 0; i < sizeof(temp); i++)
        temp[i] = '\0';

    len_ad = len_soyad = toplam=sayilar_toplam=0;

    carpim = carpim_ad = carpim_soyad = carpim_ort = 1;


     /*1- Kullan�c�dan giri� al*/
    char sistem_sifre[20];

    printf("\nad-soyad: ");
    scanf("%s %s", ad, soyad);
    printf("\nSistem Sifre :");
    scanf("%s", sistem_sifre);

    /*2- Ad-Soayad ta bulunan harflerin say�lar�n kar��l�klar�n� �arp.*/
    len_ad = strlen(ad);
    len_soyad = strlen(soyad);

    for (size_t i = 0; i < len_ad; i++)
    {
        carpim_ad *= (short)(ad[i]);
    }

    for (size_t i = 0; i < len_soyad; i++)
    {
        carpim_soyad *= (short)(soyad[i]);
    }

    /*3- �arp�m�n ortalamas�n� hesapla */
    toplam = len_ad + len_soyad;       //carpim_ad + carpim_soyad; 
    carpim = carpim_ad * carpim_soyad;

    carpim_ort = (carpim) / (toplam);

    /*4- �arp�m�n ortalamas�nda bulunan rakamlar�n saysal kar��l�klar�n� topla.*/

    sayilar_toplam = 0;

    sprintf(temp, "%llu", carpim_ort);

    for (int i = 0; i < strlen(temp); i++)
    {
        sayilar_toplam += (int)temp[i];
    }

    memset(temp, '\0', sizeof(temp)); //clear temp

    /*5- �ifreyi olu�tur.*/

    sprintf(temp, "%u", sayilar_toplam);

    sifre[0] = ad[0];
    sifre[1] = '_';
    sifre[2] = soyad[0];
    sifre[3] = '_';

    for (size_t i = 0; i < strlen(temp); i++)
    {
        sifre[4 + i] = temp[i];
    }
    sifre_son = 4 + (int)strlen(temp);
    sifre[sifre_son] = '\0';

    /*6- �ifreleri kar��la�t�r.*/
    if (strcmp(sifre, sistem_sifre) == 0) {
        printf("\nSisteme Giris BASARILI ...\n");
    }else
        printf("\nGiris !!! BASARISIZ ???\n");


    return 0;

}