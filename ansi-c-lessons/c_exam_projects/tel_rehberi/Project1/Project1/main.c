/*	COMP124 Computer Programming
2019-2020 Spring RESIT EXAM
IDE: Visual Studio 2019
... .....
.........

NOTLAR : 1- S�ralama i�lemi b�y�k k���k harf duyarl� harf �evirme yap�ld�.
2- scanf ile d�zg�n okuyabilmek i�in;
�ki adet dosya olu�turuldu, formatl� ��kt�n�n oldu�u ve kay�tlar�n tutuldu�u.
Aksi takdirde formatl� olan dosyadan veriler okunduktan sonra split edilmeli
ve format i�in kullan�lan bo�luk karakterleri silinmeli.

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


int id = 0;		// i�lemler men�s�nde se�ilen i�lem numaras�n� tutar.
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

