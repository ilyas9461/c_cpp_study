#include <stdio.h>                 // Preprocessor directive
#include <string.h>
#include <locale.h>

int n = 0;
char digit = 0;
int dig_say = 0;
void bir_tusa_bas();

int main()                         
{
	setlocale(LC_ALL, "Turkish");  //Dil seçimi
	char sayi[5];

	printf("0...N sayýsýný ve bulunacak rakamý aralarýna\n" 
		   "boþluk býrakarak giriniz...\n");

	scanf("%u %c", &n, &digit);

	for (int i = 0; i < n; i++)
	{
		sprintf(sayi, "%u", i);

		for(int x = 0; x < strlen(sayi); x++)
		{
			if (sayi[x] == digit){
				dig_say++;
				printf("%u ", i);
				int mod = (dig_say % 10);
				if (mod == 0)
					//putch('\n');
					putchar('\n');
				break;
			}
		}
	}

	printf("\n\ntoplam:%u\n", dig_say);
	fflush(stdin);
	getchar();
	//getche();
	//bir_tusa_bas();

	return 0;
}

void bir_tusa_bas(){
	char ch = 0;
	printf("\n\nBir tusa BASIN...\n\n");
	while (ch == 0){
		ch = getche();
	}
}