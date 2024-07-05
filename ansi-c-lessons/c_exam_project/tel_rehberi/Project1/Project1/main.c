/*	COMP124 Computer Programming
2019-2020 Spring RESIT EXAM
IDE: Visual Studio 2019
... .....
.........

NOTLAR : 1- Sýralama iþlemi büyük küçük harf duyarlý harf çevirme yapýldý.
2- scanf ile düzgün okuyabilmek için;
Ýki adet dosya oluþturuldu, formatlý çýktýnýn olduðu ve kayýtlarýn tutulduðu.
Aksi takdirde formatlý olan dosyadan veriler okunduktan sonra split edilmeli
ve format için kullanýlan boþluk karakterleri silinmeli.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#include "rehber.h"


int id = 0;		// iþlemler menüsünde seçilen iþlem numarasýný tutar.
int mesaj = 0;


int main()
{
	setlocale(LC_ALL, "Turkish");
	ilkDosayaOlustur("tel_rehberi.txt");

	printf("\nmesaj: %d\n", mesaj);
	birTusaBas();
	do {
		printf("\n");
		id = menuOlustur("tel_rehberi.txt");
		switch (id) {
		case 1:
			rehbereKayitEkle("tel_rehberi.txt");
			birTusaBas();
			break;
		case 2:

			RehberDuzenle();
			birTusaBas();
			break;
		case 3:
			//RehberdenSil();
			sil_2_dosya();
			birTusaBas();
			break;
		case 4:
			rehberiListele(RAW_DOSYA);

			birTusaBas();
			break;
		case 5:
			rehberiListele(FORMATLI_DOSYA);
			birTusaBas();
			break;
		case 6:
			RehberdeAra();
			birTusaBas();
			break;
		case 7:


			break;
		}
	} while (id != 9);

	return 0;
}//main...

