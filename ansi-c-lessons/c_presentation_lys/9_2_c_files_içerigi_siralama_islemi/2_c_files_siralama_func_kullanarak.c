
/* Struct ile dosyadaki verilerin sıralanması işlemi.
   fonksiyon kullanarak...
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define KUCUK_TEN_BUYUGE true
#define BUYUK_TEN_KUCUGE false
#define NO		0
#define ADI		1
#define SOYADI	2
#define BOLUM	3

struct ogrenci {

	char no[10];
	char adi[20];
	char soy_adi[20];
	char bolum[10];

};
typedef struct ogrenci ogr_t;

int dosyaSatirSysGetir_getc(const char *dosya_adi);
int dosyaSatirSysGetir_fgets(const char *dosya_adi_yol);
void struct_swap(ogr_t* a, ogr_t* b);
ogr_t *dosya_oku(const char *dosya_yol, int *satir_sys_al);
void struct_sirala(ogr_t *_ogr, int sayi, bool sirala_yon, int sirala_alan);

int main()
{

	int satir_sayisi = 0;
	ogr_t *ogr;				// yeni türetilmiş tip olarak struct değişiken bildirimi...

	ogr = dosya_oku("orn_dosyalar\\students.txt", &satir_sayisi);
	
	struct_sirala(ogr, satir_sayisi,KUCUK_TEN_BUYUGE, NO);

	/* %-08s -> sola dayalı 8 bosluk bırakarak yazdır.*/
	printf("%s\t%-08s %-30s %-10s\n", "SN", "NO", "Ad-Soyad", "Bolum");
	printf("----------------------------------------------------------\n");

	for (size_t i = 0; i < satir_sayisi; i++)
	{
		printf("%02u\t%-8s %-15s %-15s %-8s\n", i, ogr[i].no, ogr[i].adi,
			ogr[i].soy_adi, ogr[i].bolum);
	}

	_getch();

	return 0;
}//main...

/* Fonksiyonlar */
void struct_swap(ogr_t* a, ogr_t* b) {

	ogr_t temp = *a;  //a nın adresteki değerini temp e kopyala
	*a = *b;        //b nın adresteki değerini a ya kopyala
	*b = temp;

}

ogr_t *dosya_oku(const char *dosya_yol, int *satir_sys_al) {
	FILE *dosya;
	int index = 0;
	
	//ogr_t ogr_depo[100];				// yeni türetilmiş tip olarak struct değişiken bildirimi...

	int depo_eleman_sys = dosyaSatirSysGetir_getc(dosya_yol);
	ogr_t *ogr_depo = (ogr_t *)malloc(sizeof(ogr_t)*depo_eleman_sys);


	if ((dosya = fopen(dosya_yol, "r")) == NULL) // dosyanın açılıp açılmadığı sorgulanıyor.
	{
		fprintf(stdout, "Hata: dosya acma....\n");
		exit(EXIT_FAILURE);
	}

	//rewind(dosya); /* dosyanın başına git...*/
	/* Dosya okunuyor ve içeriği struct diziye satir satir kaydediliyor...*/
	while (!feof(dosya)) {
		fscanf(dosya, "%s %s %s %s", ogr_depo[index].no, ogr_depo[index].adi,
			ogr_depo[index].soy_adi, ogr_depo[index].bolum);
		index++;
	}

	if (fclose(dosya) != 0)  //Dosaya kapatılıyor...
		printf("Dosya kapama hatasi...\n");

	*satir_sys_al = index;

	return ogr_depo;
}

void struct_sirala(ogr_t *_ogr, int sayi, bool sirala_yon, int sirala_alan) {

	/* struct diziye alınan bilgiler structa ait .adi üyesine göre sıralanıyor...*/
	for (size_t i = 0; i < sayi; i++)
	{
		for (size_t j = 0; j < sayi - 1; j++)
		{
			switch (sirala_alan)
			{
			case NO:
				if (sirala_yon) {
					if(strcmp(_ogr[i].no, _ogr[j].no)<0)
					//if (_ogr[i].no[0] < _ogr[j].no[0])    //küçükten büyüğe doğru (descending)
					{
						struct_swap(&_ogr[i], &_ogr[j]);
					}
				}
				
				else if (strcmp(_ogr[i].no, _ogr[j].no)>0)
					//if (_ogr[i].no[0]>_ogr[j].no[0])	  //büyükten küçüğe doğru sıralama...(ascending)
				{
					struct_swap(&_ogr[i], &_ogr[j]);
				}
				break;
			case ADI:
				if (sirala_yon) {
					if (_ogr[i].adi[0] < _ogr[j].adi[0])    //küçükten büyüğe doğru (descending)
					{
						struct_swap(&_ogr[i], &_ogr[j]);
					}
				}
				else if (_ogr[i].adi[0]>_ogr[j].adi[0])	  //büyükten küçüğe doğru sıralama...(ascending)
				{
					struct_swap(&_ogr[i], &_ogr[j]);
				}
				break;
			default:
				break;
			}
			
		}
	}/* sıralama işlemi sonunda struct ta bulunan bütün üyeler de sıralamaya uygun şekilde
	 yer değiştirip öğrenciye ait bilgiler korunmuş olur....*/
}

int dosyaSatirSysGetir_fgets(const char *dosya_adi_yol) {
	int line = 0;
	char buf[100];
	FILE* _file;
	_file = fopen(dosya_adi_yol, "r");
	if (_file != NULL) {
		do {
			fgets(buf, sizeof(buf), _file);
			line++;
		} while (!feof(_file));
		fclose(_file);
	}
	else line = -1;
	return line;
}

int dosyaSatirSysGetir_getc(const char *dosya_adi) {
	FILE* fileptr;
	int count_lines = 0;
	char chr;

	fileptr = fopen(dosya_adi, "r");
	//extract character from file and store in chr
	if (fileptr != NULL) {
		do {
			//take next character from file.
			chr = getc(fileptr);
			//Count whenever new line is encountered
			if (chr == '\n')
			{
				count_lines++;
			}
		} while (chr != EOF);
	}
	else return -1;

	fclose(fileptr); //close file.
	if (count_lines == 0) return 0;
	return count_lines + 1;
}


