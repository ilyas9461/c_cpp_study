
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#include "ogr.h"

int id = 0;		// i�lemler men�s�nde se�ilen i�lem numaras�n� tutar.
int mesaj = 0;


int main()
{
	setlocale(LC_ALL, "Turkish");

	do {
		printf("\n");
		id = menuOlustur();
		switch (id) {
		case 1:
			YeniOgrenciEkle();
			birTusaBas();
			break;
		case 2:

			//Duzenle();
			birTusaBas();
			break;
		case 3:

			ogrenciSil();
			birTusaBas();
			break;
		case 4:
			Listele();

			birTusaBas();
			break;
		case 5:
			//rehberiListele("ogrenciListesi.txt");
			birTusaBas();
			break;
		case 6:
			ogrenciAra();
			birTusaBas();
			break;
		case 7:


			break;
		}
	} while (id != 9);





	return 0;
}

