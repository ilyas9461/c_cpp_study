#include <stdio.h>
int x[], b = 0;

int main()

{
  scanf("%d", x[0]);

  for (int i = 0; i < x[0]; i++)
  {

    scanf("%d", x[i]);
    if (b < x[i])
      b = x;
  }

  printf("\n x == %d sayilar.\n", x);
  printf("\n buyuk sayi== %d.\n", b);
  return 0;
}
