#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long say = 0;

int main()
{
    while (say<3000000)
    {
        say++;

        if(say%1000000==0){
            printf("%ld\n",say);
        }
    }

    getch();
    return 0;
}