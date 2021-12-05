// kredi kartı limiti oluuşturma

#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float limit, ilk_bakiye, son_bakiye, toplam_harcama, beklenen, fazladan, g;

int main(void)
{
   while (limit != -1)
   {
      printf("\nLütfen hesap numarasını girin :");
      scanf("%f", &g);

      printf("\nlimitinizi girin :");
      scanf("%f", &limit);
      printf("ilk bakiyenizi girin :");
      scanf("%f", &ilk_bakiye);
      printf("son bakiyenizi girin :");
      scanf("%f", &son_bakiye);
      toplam_harcama = ilk_bakiye + son_bakiye;
      printf("\nToplam harcanan para :%2.f", toplam_harcama);
      if (limit < toplam_harcama)
      {
         beklenen = toplam_harcama - limit;
      }
      else
      {
         fazladan = limit - toplam_harcama;
      }
      printf("\nfazladan harcanan para :%2.f", beklenen);
      printf("\nfazladan harcanan para :%2.f", fazladan);
   }

   getch(); // enter tuşu basılana kadar algılar
   return 0;
}
