/* Structures (Yapýlar) örnek 1 
	* Tanýmlama
	* Üyelere Eriþim
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

char* s_gets(char* st, int n);	// konsoldan n karakter kadar string giriþ alabilen fonksiyon.

#define MAX_BASLIK 41	/* max baþlýk  + 1 */
#define MAX_YAZAR  31	/* max yazar ismi + 1 */

struct kitap  /* structure template: tag is book -yapý þablonu: etiket kitap  */
{ 
	/* Yapý içersinde tanýmlanan üyeler :*/
	char baslik[MAX_BASLIK];
	char yazar[MAX_YAZAR];
	float fiyat;
}; /* end of structure template - yapý þablonu sonu */

int main(void)
{
	struct kitap kitaplar; /* kitap_listesi kitap yapýsý tütünde tanýmlandý. */

	printf("Kitap ismi : ?\n");
	s_gets(kitaplar.baslik, MAX_BASLIK); /* baslik üyesine eriþim...*/

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



