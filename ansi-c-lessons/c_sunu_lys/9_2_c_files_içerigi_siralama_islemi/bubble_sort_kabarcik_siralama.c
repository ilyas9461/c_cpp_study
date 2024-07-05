
/* 
    S�ralama i�lemleri
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>

void sayi_degistir_swap(int* a, int* b) {

    int temp = *a;  //a n�n adresteki de�erini temp e kopyala
    *a = *b;        //b n�n adresteki de�erini a ya kopyala
    *b = temp;      

}

int* rasgete_sayi(int boyut) {

    int i, sayi;
    //static int r_sayi[10];        // Bu �ekildeki bir tan�mlama ile dianmik dizi olu�turulamaz.
                                    // dizi eleman sayisini belirten de�er sabit olmal�d�r, de�i�ken olamaz.
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

 //---- BUBBLE SORT ALGORITMASI ---- Kabarc�k s�ralamas�  //
void bubble_siralama(int array[], int size)
{
    int i, j, temp;

    for (i = 1; i < size; i++)              // 2. elamandan ba�la ve dizinin boyutu kadar d�n
    {
        int sirali = 1;                     // dizi s�ral�m� ?
        for (j = 0; j < size - i; j++)      // s�f�r�nc� indeks, 1. elmandan ba�la ve i kadar eksi�i miktar�nca d�n.
        {
            if (array[j] > array[j + 1])   //dizideki iki elman� kar��la�t�r. K���kten b�y��e do�ru s�ralama i�lemi
            {
                //temp = array[j + 1];       //e�er s�ralama �art� do�ru ise dizideki lemanlar� yer de�i�tir swap i�lemi.
                //array[j + 1] = array[j];
                //array[j] = temp;

                sayi_degistir_swap(&array[j + 1], &array[j]);

                sirali = 0;
            }
            
        }
        //d�ng� sonunda yukar�daki �arta g�re en b�y�k say� dizinin en sonuna yerle�tirilir.
        //her d�ng�de s�ralama bu �ekilde devam eder. En sondaki elamn en b�y�k oldu�una g�re bir sonraki d�ng�de
        //bu elman� kontrol etmeye gerek yoktur. O y�zden d�ng� say�s� bir azalt�larak devam eder.
        //B�ylece k���kten b�y��e do�ru s�ralama yap�lm�� olur.

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