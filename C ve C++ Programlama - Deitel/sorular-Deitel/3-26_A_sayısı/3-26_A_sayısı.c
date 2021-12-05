

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    printf("\nA\tA+2\tA+4\tA+6");
    for (int i = 0; i < 15; i=i+3)
    {
        int s1 = i + 2;
        int s2 = i + 4;
        int s3 = i + 6;

        printf("\n%d\t%d\t%d\t%d", i, s1, s2, s3);
    }

    getch();
    return 0;
}
