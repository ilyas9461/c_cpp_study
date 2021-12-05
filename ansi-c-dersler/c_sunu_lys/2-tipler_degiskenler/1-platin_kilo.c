/* platin.c --  ağırlığın platin değeri */

#include <stdio.h>

int global_deg = 0;

int main(void)
{
	float kilo = 0.0; /* kullanıcı ağırlığı*/
	float deger = 0.0; /* platin eşdeğeri */

	printf("Platin olarak kilonuza değer misiniz?\n");
	printf("\nHadi kontrol edelim.\n");
	printf("\nLütfen kilonuzu pound cinsinden girin: ");

	/* kullanıcıdan giriş al */
	scanf("%f", &kilo);

	/* platinin ons başına 1700 dolar olduğunu varsayalım */
	/* 14.5833 katsayısı kuuymcu tartısına göre onsu çevirir... */
	deger = 1700.0 * kilo * 14.5833;

	printf("Platin kilonuzun değeri: $%.2f.\n", deger);
	printf("\nBuna kolayca değersin! Platin fiyatları düşerse,\n");
	printf("değerinizi korumak için daha fazla yiyin.\n");

	getch();

	return 0;
}


