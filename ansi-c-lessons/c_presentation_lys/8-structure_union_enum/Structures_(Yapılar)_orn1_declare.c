/* Structures (Yap�lar) �rnek 1 
	* Tan�mlama
	* �yelere Eri�im
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

char* s_gets(char* st, int n);	// konsoldan n karakter kadar string giri� alabilen fonksiyon.

#define MAX_BASLIK 41	/* max ba�l�k  + 1 */
#define MAX_YAZAR  31	/* max yazar ismi + 1 */

struct kitap  /* structure template: tag is book -yap� �ablonu: etiket kitap  */
{ 
	/* Yap� i�ersinde tan�mlanan �yeler :*/
	char baslik[MAX_BASLIK];
	char yazar[MAX_YAZAR];
	float fiyat;
}; /* end of structure template - yap� �ablonu sonu */

int main(void)
{
	struct kitap kitaplar; /* kitap_listesi kitap yap�s� t�t�nde tan�mland�. */

	printf("Kitap ismi : ?\n");
	s_gets(kitaplar.baslik, MAX_BASLIK); /* baslik �yesine eri�im...*/

	printf("Yazar ismi : ?\n");
	s_gets(kitaplar.yazar, MAX_YAZAR);

	printf("Kitap fiyati : ?\n");
	scanf("%f", &kitaplar.fiyat);

	printf("%s , %s: $%.2f\n",kitaplar.baslik,
		kitaplar.yazar, kitaplar.fiyat);
	printf("%s: \"%s\" ($%.2f)\n", kitaplar.yazar,
		kitaplar.baslik, kitaplar.fiyat);
	printf("\nTamam...\n");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline
		if (find) // if the address is not NULL,
			*find = '\0'; // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}



