/* C FILES :
	 struct ile dosyadan veri okuma ve konsola
	 formatlı bir şeklide yazdırma işlemi.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

struct ogrenci {

	char no[10];
	char adi[20];
	char soy_adi[20];
	char bolum[10];

};
typedef struct ogrenci ogr_t;


int main(void)
{
	FILE *dosya;
	int ogr_index = 0;

	//struct ogrenci ogr[100];  //struct yapısı ile bildirim...
	//ogr_t ogr[100];				// yeni türetilmiş tip olarak bildirim...

	if ((dosya = fopen("orn_dosyalar\\students.txt", "r")) == NULL)
	{
		fprintf(stdout, "Hata: dosya acma....\n");
		exit(EXIT_FAILURE);
	}

	puts("Dosya okunuyor...");

	rewind(dosya); /* dosyanın başına git...*/

	while (!feof(dosya)) {
		fscanf(dosya, "%s %s %s %s", ogr[ogr_index].no, ogr[ogr_index].adi, 
			   ogr[ogr_index].soy_adi, ogr[ogr_index].bolum);
		ogr_index++;
	}
	
	if (fclose(dosya) != 0)
		printf("Dosya kapama hatasi...\n");

	/* %-08s -> sola dayalı 8 bosluk bırakarak yazdır.*/
	printf("%s\t%-08s %-30s %-10s\n", "SN", "NO", "Ad-Soyad", "Bolum");
	printf("----------------------------------------------------------\n");

	for (size_t i = 0; i < ogr_index; i++)
	{
		printf("%02u\t%-8s %-15s %-15s %-8s\n",i, ogr[i].no, ogr[i].adi, 
			   ogr[i].soy_adi, ogr[i].bolum);
	}
	
	_getch();

	return 0;
}