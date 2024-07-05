
/* Struct ile dosyadaki verilerin sıralanması işlemi.
   min içersinden fonksiyon kullanmadan...
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


int main()
{
	FILE *dosya;
	int ogr_index = 0;
	ogr_t temp;

	ogr_t ogr[100];				// yeni türetilmiş tip olarak struct değişiken bildirimi...

	if ((dosya = fopen("orn_dosyalar\\students.txt", "r")) == NULL) // dosyanın açılıp açılmadığı sorgulanıyor.
	{
		fprintf(stdout, "Hata: dosya acma....\n");
		exit(EXIT_FAILURE);
	}
	puts("Dosya okunuyor...");

	//rewind(dosya); /* dosyanın başına git...*/
	/* Dosya okunuyor ve içeriği struct diziye satir satir kaydediliyor...*/
	while (!feof(dosya)) {
		fscanf(dosya, "%s %s %s %s", ogr[ogr_index].no, ogr[ogr_index].adi,
			ogr[ogr_index].soy_adi, ogr[ogr_index].bolum);
		ogr_index++;
	}

	if (fclose(dosya) != 0)  //Dosaya kapatılıyor...
		printf("Dosya kapama hatasi...\n");
	/* struct diziye alınan bilgiler structa ait .adi üyesine göre sıralanıyor...*/
	for (size_t i = 0; i < ogr_index; i++)
	{
		for (size_t j = 0; j < ogr_index-1; j++)
		{
			if (ogr[i].adi[0]<ogr[j].adi[0])    //küçükten büyüğe doğru (descending)
			//if(ogr[i].adi[0]>ogr[j].adi[0])		  //büyükten küçüğe doğru sıralama...(ascending)
			{
				/* struct dizide ;
				   her i indeksteki eleman, j indekseteki elemanlarla karşılaştırılır ve 
				   şartı sağlayan eleman struct olarak bütünüyleyer değiştiriliyor.
				   swap işlemi;
				   - i. indeksteki eleman içeriği bütünüyle depo değişkene kopyalanır,
				   - j. indekteki eleman içeriği bütünüyle i. indeksteki elemana kopyalanır,
				   - depo değşiken içeriği bütünüyle j. indeksteki eleamna kopyaalnır,
				   böylece dizinin elemanları yer değiştirmiş olur.
				 */
				//memcpy(hedef,kaynak, size)
				memcpy(&temp, &ogr[i], sizeof(ogr[j]));	
				memcpy(&ogr[i], &ogr[j], sizeof(ogr[j]));
				memcpy(&ogr[j], &temp, sizeof(ogr[j]));
			}
		}
	}/* sıralama işlemi sonunda struct ta bulunan bütün üyeler de sıralamaya uygun şekilde 
	    yer değiştirip öğrenciye ait bilgiler korunmuş olur....*/

	/* %-08s -> sola dayalı 8 bosluk bırakarak yazdır.*/
	printf("%s\t%-08s %-30s %-10s\n", "SN", "NO", "Ad-Soyad", "Bolum");
	printf("----------------------------------------------------------\n");

	for (size_t i = 0; i < ogr_index; i++)
	{
		printf("%02u\t%-8s %-15s %-15s %-8s\n", i, ogr[i].no, ogr[i].adi,
			ogr[i].soy_adi, ogr[i].bolum);
	}

	_getch();

	return 0;
}


