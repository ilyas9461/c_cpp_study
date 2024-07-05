/*
3.44 float türünde üç sayı alan ve bu sayıların bir üçgenin üç kenarı olup olamayacağına
 karar veren bir program yazınız.
*/

#include <conio.h>
#include <ctype.h>
#include <errno.h>
#include <locale.h> //setlocale(LC_ALL, "Turkish");
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float a = 0.0, b = 0.0, c = 0.0;

int main(void)
{
    setlocale(LC_ALL, "Turkish");

    printf("ucgenin kenarlarını olusturacak sekide sayi girin :");
    scanf("%f %f %f", &a, &b, &c);
    printf("\ns :%f %f %f \n", a, b, c);

    float a_kare = a * a;
    float b_kare = b * b;
    float c_kare = c * c;

    if (((a_kare + b_kare) == c_kare) ||
        ((b_kare + c_kare) == a_kare) ||
        ((a_kare + c_kare) == b_kare))
    {
        printf("\ndik ucgen olustu +");
    }
    else
    {
        printf("\ndik ucgen olusmaz -");
    }
    if ((fabs(a - b)) < (c < (a + b)) &&
        (fabs(a - c)) < (b < (a + c)) &&
        (fabs(b - c)) < (a < (b + c)))
    {
        printf("\nucgen olusur :+");
    }
    else
    {
        printf("\nucgen olusmaz :-");
    }

    getch();

    return 0;
}
