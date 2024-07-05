const int el_sayi = 10;
char puan[10];
int at;

int main(void)
{
	printf("sınav notlarınnı gırın \n");

	for (int i = 0; i < el_sayi; i++)
	{
		printf("\n\t%u. puan=", i + 1);
		scanf("%u", &puan[i]);
	}
	for (int j = 1; j < el_sayi; j++)
	{
		for (int i = 0; i < el_sayi; i++)
		{

			if (puan[j] <= puan[i])
			{ // karşılaştırma yaparak for for döngüsü kullanılmıştır/
				at = puan[i];
				puan[i] = puan[j];
				puan[j] = at;
			}
		}
	}
	for (int i = 0; i < el_sayi; i++)
	{

		printf("\nSıralama =%d \n", puan[i]);
	}
	// printf("\nk: %d \n", kucuk);
	// printf("b: %d \n", buyuk);

	getch();

	return 0;
}