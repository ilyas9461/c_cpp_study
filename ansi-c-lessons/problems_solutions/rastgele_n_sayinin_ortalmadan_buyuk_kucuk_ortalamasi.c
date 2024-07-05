
/* 
    rastgele üretilmiþ N tane sayýnýn ortalamasýný alýp,
    sayýlar içersinden ortalamdan büyük ve küçük olanlarýn ayrý
    ayrý ortalmalarýný alan program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>

#define dizi_aleman_sayisi 10
#define yeniSatir() printf("\n")


int* rnd_sayilar() {

    static ret_int_sayilar[dizi_aleman_sayisi];
    int rnd_sayi = 0;
    srand(time(NULL));
    printf("Rastgele sayilar: ");
    for (size_t i = 0; i < dizi_aleman_sayisi; i++)
    {
        rnd_sayi= rand() % 100; //0-100arasý sayi üretir.
        ret_int_sayilar[i] = rnd_sayi;
        printf("%u ", ret_int_sayilar[i]);

    }
    printf("\n");

    return  ret_int_sayilar;


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

void buyuk_kucuk_ort(int* sayilar, float sayilar_ort, int eleman_sayisi) {
    int buyuk[dizi_aleman_sayisi] = { 0 };
    int kucuk[dizi_aleman_sayisi] = { 0 };
    int buyuk_ind = 0, kucuk_ind = 0;

    printf("\nortalama : %2.1f\n", sayilar_ort);
    yeniSatir();

    for (size_t i = 0; i <eleman_sayisi; i++)
    {
        if (sayilar[i] > sayilar_ort) {
            buyuk[buyuk_ind++] = sayilar[i];
        }
        if (sayilar[i] < sayilar_ort) {
            kucuk[kucuk_ind++] = sayilar[i];
        }

    }
    printf("Buyuk Sayilar: ");
    for (size_t i = 0; i < buyuk_ind; i++)
    {
        printf("%u ", buyuk[i]);
    }
    printf("\nBuyuk ortalama : %2.1f\n", ortalama(buyuk, dizi_aleman_sayisi));

    yeniSatir();

    printf("Kucuk Sayilar: ");
    for (size_t i = 0; i < kucuk_ind; i++)
    {
        printf("%u ", kucuk[i]);
    }
    printf("\nKucuk ortalama : %2.1f\n", ortalama(kucuk, dizi_aleman_sayisi));

}

int main()
{ 
    int* sayilar = rnd_sayilar();

    float ort = ortalama(sayilar, dizi_aleman_sayisi);

    buyuk_kucuk_ort(sayilar, ort, dizi_aleman_sayisi);
    yeniSatir();
    
    return 0;
}