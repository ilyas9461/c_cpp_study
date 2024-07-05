/* Sesli Harfleri Bul*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>

const char SESLI_HARFLER[9] = "aAeEiuUoO";
char ifade[100];

void sesli_harf_bul(char* ifade);
void yaz(int sesli_sys, int* sesli_yer_dizi, int sayi);

int main()
{
tekrar:
    system("CLS");
    printf("ifade giriniz max 100 :");
    //scanf("%s", ifade);   // ilk boþluða kadar okur
    gets(ifade);

    sesli_harf_bul(ifade);

    printf("\nBaska giris ?(E/H)");
    char s = _getch();

    if(s=='E' || s=='e') goto tekrar;
            ;
    return 0;

}

void sesli_harf_bul(char* ifade) {
    int sesli_harflerin_sayisi[9] = { 0 };
    int a_yer[100], A_yer[100];
    int a_yer_say = 0, A_yer_say = 0;
    for (size_t x = 0; x < strlen(SESLI_HARFLER); x++)
    {
        for (size_t i = 0; i < strlen(ifade); i++)
        {
            if (SESLI_HARFLER[x] == ifade[i]) {
                sesli_harflerin_sayisi[x]++;

                if (SESLI_HARFLER[x] == 'a') {
                    a_yer[a_yer_say++] = i+1;
                }
                if (SESLI_HARFLER[x] == 'A') {
                    A_yer[A_yer_say++] = i+1;
                }
            }
        }
    }

    printf("\tHarf\tMiktari\t\tYeri\n");
    printf("\t---------------------------\n");

    for (size_t i = 0; i < strlen(SESLI_HARFLER); i++)
    {
        char sesli = SESLI_HARFLER[i];
        printf("\t%c", sesli);
        switch (sesli)
        {
        case 'a':
            yaz(sesli_harflerin_sayisi[i], a_yer,a_yer_say);
            break;
        case 'A':
            yaz(sesli_harflerin_sayisi[i], A_yer, A_yer_say);
            break;
        default:
            break;
        }

        putchar('\n');
          
    }
    


}

void yaz(int sesli_sys,int *sesli_yer_dizi,int sayi) {

    
    printf("\t%u\t\t", sesli_sys);
    for (size_t i = 0; i < sayi; i++)
    {
        printf("%u,", sesli_yer_dizi[i]);
    }
    putchar('\n');
}
    


