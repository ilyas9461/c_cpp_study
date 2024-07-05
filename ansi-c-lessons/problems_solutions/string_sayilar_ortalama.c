
/* 
    Bir string i�ersinde belli bir karakter ile ayr�lm�� say�lar�n
    string i�ersinden ayr��t�r�larak ortalmasa�n�n al�nmas�.
    String split i�lemi.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>

#define dizi_aleman_sayisi 10
#define yeniSatir() printf("\n")

char* rasgete_str_sayi(int boyut) {

    int i=0, sayi;
    static char r_str_sayi[10*dizi_aleman_sayisi];
    char gecici[5];
    int* r_sayi = (int*)malloc(boyut * sizeof(int));

    srand(time(NULL));

    printf("Random sayilar\t: ");
    for (size_t i = 0; i < boyut; i++)
    {
        sayi = rand() % 100;
        r_sayi[i] = sayi;

        printf("%d ", sayi);
        sprintf(gecici, "%u,", r_sayi[i]);
        strcat(r_str_sayi, gecici);
    }
    yeniSatir();
    //en sondaki virg�k� kald�rmak i�in
    int str_uz = strlen(r_str_sayi);
    r_str_sayi[str_uz - 1] = '\0';

    printf("String Sayilar\t: %s \n", r_str_sayi);
    return r_str_sayi;
}

/*FONK :int str_bol(char* str_ifade,char bol_kar, int bol_yer) 
    A��klama    : Belli bir karakter ile ayr�lm�� string ifadeden istenilen sayma s�ras�ndaki 
                  ifadeyi ay�rarak string d�n�� de�eri olarak d�nd�r�r.
   1. Parametre : char* str_ifade;
                  String olarak belli bir karakterle ayr�lm�� ifadeleri i�erir.
                  �rn. "10,15,78,45,55,65,89,58,89,57"
   2. Parametre : char bol_kar;
                  String i�ersinde say�lar� birbirinden ay�ran karakter
   3. Parametre : int bol_yer;
                  String i�ersinden ay�klanacal/b�l�necek ifadenin ba�tan itibaren ka��nc� ifade oldu�u.
                  �rn. 5. say� yani "55" say�s�.
   D�n�� de�eri : Ay�klanan string ifade.
   
  NOT: String toplam ifadenin sonunda virg�l olsun yada olmas�n yinede fonksiyon en sonuncu ay�klanacak ifadeyi elde edebilir.

*/
                                                    //yer->  1  2  3  4  5  6  7  8  9  10 .�nc� str yi ifade eder.
char *str_bol(char* str_ifade,char bol_kar, int bol_yer) // "10,15,78,45,55,65,89,58,89,57"
                                                
{
    int bol_kar_yer[10] = { 0 };
    int bol_kar_say = 0;

    size_t son_ind=0;
    size_t bas_ind=0;

    static char bol_str[10] = {'\0' };
    int sayi_indeks = 0;

    int str_ifade_uz = strlen(str_ifade);

    for (size_t i = 0; i < str_ifade_uz; i++)
    {
        if (str_ifade[i] == bol_kar) {
            bol_kar_yer[bol_kar_say++] = i;
        }
    }

    if (bol_yer == 1) 
    {
        son_ind = bol_kar_yer[bol_yer - 1];
        bas_ind =0 ;
    }

    if(bol_yer>1) 
    {
        son_ind = bol_kar_yer[bol_yer - 1];
        bas_ind = bol_kar_yer[bol_yer - 2]+1;
    }

    if (bol_yer - bol_kar_say == 1) 
    {
        son_ind = str_ifade_uz;
        bas_ind = bol_kar_yer[bol_kar_say - 1] + 1;
    }

    for (size_t i = bas_ind; i < son_ind; i++)
    {
        bol_str[sayi_indeks++] = str_ifade[i];
    }

   // int ret_sayi = atol(bol_str);
   // return ret_sayi;
    return bol_str;
}


int *sayilar_dizi(char* str_sayilar) {

    int static sayilar[dizi_aleman_sayisi] = { 0 };

    printf("Tam Sayilar\t: ");
    for (size_t i = 1; i < dizi_aleman_sayisi + 1; i++)
    {
        sayilar[i - 1] = atol(str_bol(str_sayilar, ',', i));
        printf("%u ", sayilar[i - 1]);
    }
    yeniSatir();
    return sayilar;
}

float ortalama(int* sayilar, int sayilar_sayisi) {

    int toplam = 0;
    for (size_t i = 0; i < sayilar_sayisi; i++)
    {
        toplam += sayilar[i];
    }

    float ort = (float)toplam / (float)sayilar_sayisi;
    return ort;
}


int main()
{
    char* rnd_str_sayilar = rasgete_str_sayi(dizi_aleman_sayisi);
 
    int *tam_sayilar= sayilar_dizi(rnd_str_sayilar);

    float ort = ortalama(tam_sayilar,dizi_aleman_sayisi);

    printf("\nortalama: %3.1f \n", ort);
    
    return 0;
}