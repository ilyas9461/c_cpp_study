// girilen 3 sayı ile işlemler enb enk
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s1, s2, s3, s4, s5, eb = 0, ek;

int main()
{
	printf("üç sayı girin");
	scanf("%d", &s1);
	
	if (s1 > eb)
	{
		eb = s1;
	}
	if (s1 < eb)
	{
		ek = eb;
	}
	printf("\n eb :%d ek :%d", eb, ek);
	getch();
	return 0;
}