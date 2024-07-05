/*

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

char s[9];
int d1, d2, d3, d4;
char geciciDepo[10];

void sifreleme(char *sayi)
{

  d1 = (sayi[0] - 48) + 7;
  d2 = (sayi[1] - 48) + 7;
  d3 = (sayi[2] - 48) + 7;
  d4 = (sayi[3] - 48) + 7;

  printf("%02d ", d3);
  printf("%02d ", d4);
  printf("%02d ", d1);
  printf("%02d \n", d2);
}

void sifreCoz()
{
  // void sifreCoz(char *n){

  // d1 = 10 * (n[0] - 48) + (n[1] - 48) - 7;
  // d2 = 10 * (n[2] - 48) + (n[3] - 48) - 7;
  // d3 = 10 * (n[4] - 48) + (n[5] - 48) - 7;
  // d4 = 10 * (n[6] - 48) + (n[7] - 48) - 7;

  // printf("%d ", d3);
  // printf("%d ", d4);
  // printf("%d ", d1);
  // printf("%d ", d2);

  d1 -= 7;
  d2 -= 7;
  d3 -= 7;
  d4 -= 7;
  printf("%d ", d1);
  printf("%d ", d2);
  printf("%d ", d3);
  printf("%d \n", d4);
}

int main(void)
{
  printf("4 basamakli bir sayi : ");
  scanf("%s", s); //10 11 8 9

  sifreleme(s);

  // sprintf(geciciDepo,"%02d%02d%02d%02d",d3,d4,d1,d2);
  // printf("\nsifrelenmis :%s\n",geciciDepo);

  // sifreCoz(geciciDepo);
  sifreCoz();

  getch();
  return 0;
}
