

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    printf("\nN\t10*N\t100*N\t1000*N");
    for (int i = 1; i < 10; i++)
    {
        int s1 = 10 * i;
        int s2 = 100 * i;
        int s3 = 1000 * i;

        printf("\n%d\t%d\t%d\t%d",i,s1,s2,s3);
        
    }

    getch();
    return 0;
}
