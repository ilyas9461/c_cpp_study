/*
   
*/

#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char s = 0, n[9];
int d1, d2, d3, d4;

int main(void)
{
  printf("4 basamaklı bir sayi yazın");
  scanf("%s", n); // 10 11 8 9

  d1 = 10 * (n[0] - 48) + (n[1] - 48) - 7;
  d2 = 10 * (n[2] - 48) + (n[3] - 48) - 7;
  d3 = 10 * (n[4] - 48) + (n[5] - 48) - 7;
  d4 = 10 * (n[6] - 48) + (n[7] - 48) - 7;

  printf("%d ", d1);
  printf("%d ", d2);
  printf("%d ", d3);
  printf("%d ", d4);

  getch();
  return 0;
}
