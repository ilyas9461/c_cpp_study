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
#include <conio.h>

char ad[50] = { 0 };
char soyad[50] = { 0 };
char *u_sifre;
char g_sifre[20];

unsigned long long carpim_ad = 1ll;
unsigned long long carpim_soyad = 1ll;
unsigned long long carpim_ort = 0;

/**/
char menu(void);
unsigned long long carpOrtAl(char* ad, char* soyad);
unsigned long long carpOrtAl(char* ad, char* soyad);
char* sifreUret(char* ad, char* soyad);
void sifreUretIslem(void);
void sistemeGirisIslem(void);
/**/
int main()
{
    char id = 0;

    do {
        id = menu();
        
        if (id == '1') {
            sifreUretIslem();
        }

        if (id == '2') {
            sistemeGirisIslem();
        }

    } while (id=='1' || id=='2');
  

    return 0;

}
/* FONKSIYONLAR */
char menu(void) {
    char sec = 0;
    system("cls");

    printf("\n\t***  ISLEMLER  ***\n\n");
    printf("\t1-Sifre Uret\n");
    printf("\t2-Sisteme GIRIS\n");

    printf("\n\tIslem SECINIZ : ");

    sec = _getch();
    return sec;
}

unsigned long long carpOrtAl(char* ad, char* soyad) {

    unsigned long long carp = 1;
    unsigned long long ort = 0;
    int a_uz = strlen(ad);
    int s_uz = strlen(soyad);

    for (size_t i = 0; i < a_uz; i++)
    {
        carp *= (int)ad[i];
    }

    for (size_t i = 0; i < s_uz; i++)
    {
        carp *= (int)soyad[i];
    }

    ort = carp / (a_uz + s_uz);

    return ort;
}

char *sifreUret( char *ad, char *soyad) {

    char temp[50];
    int toplam = 0;
    static char sifre[20] = { 0 }; /* */

    unsigned long long ortalama = carpOrtAl(ad, soyad);

    sprintf(temp, "%llu", ortalama);

    for (size_t i = 0; i < strlen(temp); i++)
    {
        toplam += (int)temp[i];
    }

    memset(temp, '\0', sizeof(temp)); //clear temp 

    sprintf(temp, "%u", toplam);

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

    return sifre;

}

void sifreUretIslem(void) {

    system("cls");
    printf("   *** Yeni SIFRE Olustur   ***\n\n");
    printf("\tad-soyad: ");
    scanf("%s %s", ad, soyad);

    u_sifre = sifreUret(ad, soyad);
    printf("\n\tUretilen SIFRE : %s\n", u_sifre);

    printf("\nBir TUSA BASINIZ...");
    _getch();
}

void sistemeGirisIslem(void) {

    system("cls");
    printf("   ***   SISTEME GIRIS   ***\n\n");

    printf("\tad-soyad: ");
    scanf("%s %s", ad, soyad);
    printf("\tSifre : ");
    scanf("%s", g_sifre);

    u_sifre = sifreUret(ad, soyad);
    if (strcmp(g_sifre, u_sifre) == 0) {
        printf("\n   ***   SISTEME GIRIS BASARILI   ***\n\n");
    }else printf("\n   !!! GIRIS BASARISIZ ???\n\n");

    printf("\nBir TUSA BASINIZ...");
    _getch();
}
