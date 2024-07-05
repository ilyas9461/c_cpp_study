
/* 
    Sýralama iþlemleri
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>

void sayi_degistir_swap(int* a, int* b) {

    int temp = *a;  //a nýn adresteki deðerini temp e kopyala
    *a = *b;        //b nýn adresteki deðerini a ya kopyala
    *b = temp;      

}

int* rasgete_sayi(int boyut) {

    int i, sayi;
    //static int r_sayi[10];        // Bu þekildeki bir tanýmlama ile dianmik dizi oluþturulamaz.
                                    // dizi eleman sayisini belirten deðer sabit olmalýdýr, deðiþken olamaz.
    int* r_sayi =(int*) malloc(boyut * sizeof(int));  //ptr = (cast-type*) malloc(byte-size)

    srand(time(NULL));
    for (size_t i = 0; i < boyut; i++)
    {
        sayi = rand() % 100;
        r_sayi[i] = sayi;
        printf("%d ", sayi);
    }

    return r_sayi;
}

 //---- BUBBLE SORT ALGORITMASI ---- Kabarcýk sýralamasý  //
void bubble_siralama(int array[], int size)
{
    int i, j, temp;

    for (i = 1; i < size; i++)              // 2. elamandan baþla ve dizinin boyutu kadar dön
    {
        int sirali = 1;                     // dizi sýralýmý ?
        for (j = 0; j < size - i; j++)      // sýfýrýncý indeks, 1. elmandan baþla ve i kadar eksiði miktarýnca dön.
        {
            if (array[j] > array[j + 1])   //dizideki iki elmaný karþýlaþtýr. Küçükten büyüðe doðru sýralama iþlemi
            {
                //temp = array[j + 1];       //eðer sýralama þartý doðru ise dizideki lemanlarý yer deðiþtir swap iþlemi.
                //array[j + 1] = array[j];
                //array[j] = temp;

                sayi_degistir_swap(&array[j + 1], &array[j]);

                sirali = 0;
            }
            
        }
        //döngü sonunda yukarýdaki þarta göre en büyük sayý dizinin en sonuna yerleþtirilir.
        //her döngüde sýralama bu þekilde devam eder. En sondaki elamn en büyük olduðuna göre bir sonraki döngüde
        //bu elmaný kontrol etmeye gerek yoktur. O yüzden döngü sayýsý bir azaltýlarak devam eder.
        //Böylece küçükten büyüðe doðru sýralama yapýlmýþ olur.

        if (sirali) break;
    }


    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
}

int main()
{
    const int dizi_eleman_sayisi = 4;

    int *random_dizi = rasgete_sayi(dizi_eleman_sayisi);
    printf("\n");
    bubble_siralama(random_dizi, dizi_eleman_sayisi);
    printf("\n");

    return 0;
}