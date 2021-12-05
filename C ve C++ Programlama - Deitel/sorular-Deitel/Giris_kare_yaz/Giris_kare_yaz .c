#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char giris[50];

int main(void)
{
  printf("Kare olustur: ");
  scanf("%s", giris);

  printf("\n");

  int padding = strlen(giris);

  printf(" %s \n", giris);

  for (size_t i = 0; i < strlen(giris); i++)
  {
    printf("%c%*s%c\n", giris[0], padding, " ", giris[0]); // *: padding(dolgu) için değişken girişi sağlar
    // printf("%c\t%s%c\n", giris[0]," ",giris[0]);  //tab ile şekil bozuldu
  }
  printf(" %s \n", giris);

  // 2. yol :

  // for (size_t i = 0; i < strlen(giris); i++)
  // {
  //   printf("%c", giris[0]);

  //   for (int i = 0; i < strlen(giris); i++)
  //   {
  //     printf(" ");
  //   }
  //   printf("%c\n", giris[0]);
  // }
  //   printf(" %s \n", giris);

  getch();
  return 0;
}
