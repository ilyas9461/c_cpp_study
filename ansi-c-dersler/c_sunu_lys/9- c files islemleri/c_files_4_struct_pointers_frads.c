/* C FILES :
struct ile dosyadan veri okuma ve konsola
formatlı bir şeklide yazdırma işlemi.
okunacak dosya aynı dizindekli "orn_dosyalar" kalsöründe yer almalıdır. 
C de dosya yolu(path) biçimi : "orn_dosyalar\\students.txt" 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");


struct p_ogrenci {
	char *no;
	char *adi;
	char *soy_adi;
	char *bolum;
};
typedef struct p_ogrenci p_ogr_t;

int main(void)
{
	FILE *dosya;
	int ogr_index = 0;

	/*1- struct içersindeki üyeler pointer olmasına rağmen 
	   struct değişiken dizi olarak bildiriliyorsa;     */
	//p_ogr_t ogr[100];			// pointer struct yeni türetilmiş tip bildirimi
						// türetilmiş tipte bir dizi oluşturulur.
						// free() komutu burada dizi için kullanılırsa hata verir.

	/*2-struct türetilmiş değişken pointer olarak bildiriliyorsa; */
	p_ogr_t *ogr =(p_ogr_t *) malloc(sizeof(p_ogr_t)*100); // a-pointer tip değiştirme (casting) yapılarak malloc komutunun
							       //   dönüş adres değerinin her birinin boyutu belirtiliyor.
							       // b- Toplam oluştuturlacak bellek alanı türetilmiş tip uzunluğu
							       //    çarpı dizini leman sayısı kadar olmalıdır.
							       // free() komutu ile ayrılan alan serbest bırakılmalıdır.
														   

	// Her iki durum içinde struct içersinde pointer olarak tanımlanan üyelere
	// her dizi elemanı için ayrı ayrı yer ayrılır.
	// yer ayrılma işlemi başarılı olduktan sonra artık dizi için sabit bir 
	//bellek bölgesi vardrı bundan dolayı struct üyelere erişirken "." kullanılır.
	// "->" kullanıldığında hata alnır.
	for (size_t i = 0; i < 100; i++)
	{
		ogr[i].adi = (char *)malloc(20);
		ogr[i].soy_adi = (char *)malloc(20);
		ogr[i].no = (char *)malloc(10);
		ogr[i].bolum = (char *)malloc(10);
	}

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
		printf("%02u\t%-8s %-15s %-15s %-8s\n", i, ogr[i].no, ogr[i].adi,
			ogr[i].soy_adi, ogr[i].bolum);
	}

	free(ogr);		// yalnızca malloc komutu ile ayrılmış alanlşarı serbest bırakır diğer türlü hata verir.

	_getch();

	return 0;
}