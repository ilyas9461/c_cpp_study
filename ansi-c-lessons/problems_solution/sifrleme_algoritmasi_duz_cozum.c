/*
   lys_2020
   26/06/2020 
   VS-2019

   Þifreleme algoritmasý:

   Bir þifreleme algoritmasýnda kiþinin ad-soyadýndaki harflerin sayýsal karþýlýklarý birbirleriyle 
   çarpýlarak sonucun ortalamasý alýnmýþtýr. Ortalama almak için çarpým sonucu toplam harf sayýsýna 
   bölünmüþtür.  Elde edilen sayýnýn rakamlarýnýn ascii  kod karþýlýklarý toplanmýþ ve toplamýn 
   sonucunda elde edilen sayýnýn önüne kiþinin isminin ve soyisminin ilk harfleri aralarýna alt çizgi 
   konularak getirilmiþ ve þifre olarak belirlenmiþtir. Sisteme giriþ þifreleri sorgulanýrken þifreler 
   bir veri tabanýnda kaydedilmek yerine ad-soyad tan elde edilen deðere göre sorgulanmaktadýr.

   Buna göre;
      a- Kiþinin ad-soyad bilgisine göre þifre deðerlerini elde edebileceðiniz,
      b- Þifre ekranýndan ad-soyad ve elde edilen þifre bilgisi girildiðinde  sisteme giriþ

  yapýlabilecek, bir program yazýnýz.
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

    /*1- Kullanýcýdan giriþ al*/
   	

    /*2- Ad-Soayad ta bulunan harflerin sayýlarýn karþýlýklarýný çarp.*/
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

    /*3- çarpýmýn ortalamasýný hesapla */
    unsigned long long toplam = len_ad+len_soyad;       //carpim_ad + carpim_soyad; 
    unsigned long long carpim = carpim_ad * carpim_soyad;

    carpim_ort = (carpim) / (toplam);

    /*4- Çarpýmýn ortalamasýnda bulunan rakamlarýn saysal karþýlýklarýný topla.*/
    char temp[100];
    int sayilar_toplam = 0;

    sprintf(temp, "%llu", carpim_ort);

    for (int i = 0; i < strlen(temp); i++)
    {
        sayilar_toplam += (int)temp[i];
    }

    memset(temp, '\0', sizeof(temp)); //clear temp 

    /*5- Þifreyi oluþtur.*/

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

    /* Kullanýncýnýn siteme giriþ yapmasýný saðla*/
    printf("\n*** SISTEME GIRIS YAPINIZ ***\n");
    // dizilerin içeriklerini sil(resetle)
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


     /*1- Kullanýcýdan giriþ al*/
    char sistem_sifre[20];

    printf("\nad-soyad: ");
    scanf("%s %s", ad, soyad);
    printf("\nSistem Sifre :");
    scanf("%s", sistem_sifre);

    /*2- Ad-Soayad ta bulunan harflerin sayýlarýn karþýlýklarýný çarp.*/
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

    /*3- çarpýmýn ortalamasýný hesapla */
    toplam = len_ad + len_soyad;       //carpim_ad + carpim_soyad; 
    carpim = carpim_ad * carpim_soyad;

    carpim_ort = (carpim) / (toplam);

    /*4- Çarpýmýn ortalamasýnda bulunan rakamlarýn saysal karþýlýklarýný topla.*/

    sayilar_toplam = 0;

    sprintf(temp, "%llu", carpim_ort);

    for (int i = 0; i < strlen(temp); i++)
    {
        sayilar_toplam += (int)temp[i];
    }

    memset(temp, '\0', sizeof(temp)); //clear temp

    /*5- Þifreyi oluþtur.*/

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

    /*6- Þifreleri karþýlaþtýr.*/
    if (strcmp(sifre, sistem_sifre) == 0) {
        printf("\nSisteme Giris BASARILI ...\n");
    }else
        printf("\nGiris !!! BASARISIZ ???\n");


    return 0;

}