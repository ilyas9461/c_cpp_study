/*	COMP124 Computer Programming
	2019 - 20 Spring
	Programming Assignment
	A Simple File Processing System
        ... .....
	.........
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
//#include "main.h"

//Ekraný temizlemeek için oluþturulan makro.
#define ekrani_temizle() system("CLS")

//Sonuç dosyasý oluþturulurken kitapçýk türüne göre 
//istatistik dedðerlerin tutulduðu yapý.
typedef struct
{
	char dogru_cevap;
	int a_say;
	int b_say;
	int c_say;
	int d_say;
	int bos_say;

}KITAPCIK;

KITAPCIK kitapcik_a[50];
KITAPCIK kitapcik_b[50];
KITAPCIK kitapcik_c[50];
KITAPCIK kitapcik_d[50];

//Öðrencilerile ilgili bilgilerin tutulduðu yapý.
//öðrenciler dosyasýnda gelen verileri tutar.
typedef struct
{
	char no[10];
	char ad[30];
	char soyad[30];
	char bolum[11];
}OGRENCI;
OGRENCI ogr;

typedef struct{
	OGRENCI ogrenci;
	char dogru[10];
	char yanlis[10];
	char puan[10];
} SONUC;
SONUC sonuc;
//Cevaplar dosyasýndan gelen verileri tuttan yapý.
typedef struct
{
	char no[6];
	char kitapcik;
	char cevaplar[50];
}OGRENCI_CEVAP;
OGRENCI_CEVAP ogr_cvp;

//global deðiþkenler
char buf_ogr[1000];				//Öðrenciler dosyasý baþlangýçta bu diziye alýnýr.
char buf_kitapcik[1000];		//Kitapçýklarla ilgili verilern bilgiler bu dizide tutulur.
char buf_ogr_cevaplar[1000];	// öðrenci cevaplarý bu dizide tutulur.

char cvp_ktp_a[50];		//Her soruya ait doðru cevaplarýn tutulduðu diziler.
char cvp_ktp_b[50];
char cvp_ktp_c[50];
char cvp_ktp_d[50];

char ogr_no[6];			//Öðrenci NO yu tutar.
char ogr_kitapcik = 0;	//Öðrencinin kitapçýk türünü tutar.
char ogr_cevaplarý[50];	//Öðrenci cevplarýnýý tutar.

FILE *dosya;

// Kullanýlan Fonksiyonlara ait tanýmlamalar
void gets_txt_buf(char *buf, FILE *d);
int menu_secim(void);
void ogr_listesi();
void bir_tusa_bas();
void kitapcik_turune_gore_cevaplari_listele();
void ogr_cevaplari_listele();
void sonuc_dosyasi_olustur();
int satir_sayisi_bul(FILE *f);
bool ogr_ad_soyad_bul();
bool karsilastir();
void ogr_yeni_kayit();
void siralama_islemi();
void arama_islemi();

int main(){
	int id;  //menu için id 
	setlocale(LC_ALL, "Turkish");  //Dil seçimi

	gets_txt_buf(buf_ogr, "students.txt");
	gets_txt_buf(buf_kitapcik, "booklet.txt");
	gets_txt_buf(buf_ogr_cevaplar, "answers.txt");

	do {
		printf("\n");
		id = menu_secim();

		switch (id) {
		case 1:		//Öðrenci listesi listelenir.
			ogr_listesi();
			bir_tusa_bas();

			break;
		case 2:		//Kitapçýk türüne göre cevaplar listelenir.
			kitapcik_turune_gore_cevaplari_listele();
			bir_tusa_bas();
			break;
		case 3:		//Öðrencilerin cevaplarý listelenir.
			ogr_cevaplari_listele();
			bir_tusa_bas();
			break;
		case 4:		//Yeni öðrenci kaydý yapýlýr
			ogr_yeni_kayit();
			bir_tusa_bas();
			break;
		case 5:		//Yeni öðrenciye ait cevaplarýn kaydý yapýlýr.
			
			break;
		case 6:    //Ýstenen formatta sonuc dosyasý oluþturulur
			sonuc_dosyasi_olustur();
			break;
		case 7:		//Sonuçlar puan göre sýralanýr.
			siralama_islemi();
			bir_tusa_bas();
			break;

		case 8:   //Ýsme göre sonuc buma iþlemi
			arama_islemi();
			bir_tusa_bas();
			break;

		}
	} while (id != 9);

	return(0);
}//main

int menu_secim(void)
{
	int id;
	
	ekrani_temizle();
	printf("\n   ## ISLEMLER ##\n\n");
	printf("[1]. Ogrenci Listesi\n");
	printf("[2]. Kitapçýk Turune Gore Cevaplar\n");
	printf("[3]. Ogrencilerin Cevaplari\n");
	printf("[4]. Dosyaya Ogrenci Kaydetme\n");
	printf("[5]. Ogrenci Cevabi Kaydetme\n");
	printf("[6]. Sonuc Dosyasi Olusturma\n");
	printf("[7]. Sonuclari Sirala\n");
	printf("[8]. NO'ya Gore Sonuc Bulma\n");
	printf("[9]. Cikis\n");

	do {
		printf("\nSECIM [1-9]: ");
		id = getche() - '0';
		printf("\n");
	} while (id<1 || id>9);

	return id;
}

void arama_islemi(){
	//Bellek ayýrma iþlemi dinamik yapýlarak txt dosya boyutundaki deðiþimlere göre ayarlanabilir.
	unsigned int boyut=sizeof(SONUC);
	SONUC *s = malloc(boyut); //pointer kullanýlýnca struct elemanlarý . yerine -> ile 
									  //ifade ediliyor...
	char no[10];
	ekrani_temizle();
	printf("Öðrenci No:? ");
	gets(no);
	//printf("%s", no);
	FILE *f_sirala = fopen("sirala.txt", "r");
	while (!feof(f_sirala)){
		fscanf(f_sirala, "%s %s %s %s %s %s %s",
			&s->ogrenci.no, &s->ogrenci.ad, &s->ogrenci.soyad, &s->ogrenci.bolum, &s->dogru, &s->yanlis, &s->puan);

		if (strcmp(s->ogrenci.no, no) == 0){
			printf("NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
			printf("%s\t%s %s\t\t%s\t%s\t%s\t%s\n",
				&s->ogrenci.no, &s->ogrenci.ad, &s->ogrenci.soyad, &s->ogrenci.bolum, &s->dogru, &s->yanlis, &s->puan);
			break;
		}
	}
	free(s);
}

void siralama_islemi(){
	FILE *f_sirala = "sirala.txt";//fopen("sirala.txt", "r");
	int satir_sys = satir_sayisi_bul(f_sirala);
	int i= 0,j=0;
	//Bellek ayýrma iþlemi dinamik yapýlarak txt dosya boyutundaki deðiþimlere göre ayarlanabilir.
	//arama_islemi() bakýnýz.
	SONUC s[7];		//sabit bellek ayýrma iþlemi
	SONUC temp;

	f_sirala = fopen("sirala.txt", "r");
	while (!feof(f_sirala)){
		fscanf(f_sirala, "%s %s %s %s %s %s %s",
			  &s[i].ogrenci.no,&s[i].ogrenci.ad,&s[i].ogrenci.soyad,&s[i].ogrenci.bolum,&s[i].dogru,&s[i].yanlis,&s[i].puan);
		i++;
	}
	i = j = 0;
	fclose(f_sirala);

	for ( i = 0; i < satir_sys; i++)
	{
		for (j = 0; j < satir_sys - 1; j++){

			if (atof(s[j].puan) < atof(s[i].puan)){   //büyükten küçüðe doðru sýralama...(ascending)

				memcpy(&temp, &s[i], sizeof(s[j]));	//hedef,kaynak, size
				memcpy(&s[i], &s[j], sizeof(s[j]));
				memcpy(&s[j], &temp, sizeof(s[j]));
			}
		}
		
	}

	ekrani_temizle();
	f_sirala = fopen("sirala.txt", "w");
	//fprintf(f_sirala, "NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
	printf("NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
	
	for (i = 0; i < satir_sys; i++){
		//Dosyaya yaz..
		fprintf(f_sirala, "%s %s %s %s %s %s %s\n",
			s[i].ogrenci.no, s[i].ogrenci.ad, s[i].ogrenci.soyad, s[i].ogrenci.bolum, s[i].dogru, s[i].yanlis, s[i].puan);
		//Ekrana yaz
		printf("%s\t%s %s\t\t%s\t%s\t%s\t%s\n",
			s[i].ogrenci.no, s[i].ogrenci.ad, s[i].ogrenci.soyad, s[i].ogrenci.bolum, s[i].dogru, s[i].yanlis, s[i].puan);
	}
	fclose(f_sirala);
	
}

void ogr_yeni_kayit(){
	char ad[30];
	char soyad[30];
	char no[10];
	char bolum[10];
	char cevap = 0;
	FILE *f_ogr = fopen("students.txt","a");

	ekrani_temizle();
	while(true){
		fflush(stdin);
		printf("Öðrenci NO(Max 6 Karakter):? ");
		gets(ogr.no);
		//scanf("%s", ogr.no);
		printf("Öðrenci ADI:? ");
		gets(ogr.ad);
		printf("Öðrenci SOYAD:? ");
		gets(ogr.soyad);
		printf("Öðrenci BÖLÜM:? ");
		gets(ogr.bolum);
		printf("%s %s %s %s\n", ogr.no,ogr.ad,ogr.soyad,ogr.bolum);
		printf("Kaydedilsin mi?(E/H)\n");
		cevap = getch();

		if (cevap == 'E' || cevap=='e'){

			fprintf(f_ogr, "%s %s %s %s\n", ogr.no, ogr.ad, ogr.soyad, ogr.bolum);
			printf("Yeni Kayýt (E/H)? ");
			cevap = getch();
			if (cevap == 'H' || cevap == 'h')
				break;

		}
		else{
			printf("Yeni Kayýt (E/H)? ");
			cevap = getch();
			if (cevap == 'H' || cevap=='h')
				break;
		}
	}

	fclose(f_ogr);

}
void sonuc_dosyasi_olustur(){

	int dogru_sys = 0;
	int yanlis_sys = 0;
	int bos_sys = 0;
	float puan = 0.0;
	float sinav_ort = 0.0;
	float basari_orani;
	int ogr_sayisi = 0;
	int a_say = 0, b_say = 0, c_say = 0, d_say = 0, bos_say = 0;

	int satir_sys = satir_sayisi_bul("booklet.txt");

	dosya = fopen("booklet.txt", "r");

	if (dosya != NULL){
		fscanf(dosya, "%s", &cvp_ktp_a);
		fscanf(dosya, "%s", &cvp_ktp_b);
		fscanf(dosya, "%s", &cvp_ktp_c);
		fscanf(dosya, "%s", &cvp_ktp_d);
	}
	else{
	}
	fclose(dosya);
	ekrani_temizle();
	
	FILE *f_sirala_buf = fopen("sirala.txt", "w");
	FILE *f_sonuc = fopen("results.txt", "r");
	if (f_sonuc != NULL){
		fclose(f_sonuc);
		remove("results.txt"); //dosya ismini olduðu gibi yazmak gerekti.
		f_sonuc = fopen("results.txt", "a");
		fprintf(f_sonuc, "BÖLÜM-A (Sonuçlar)\n");
		fprintf(f_sonuc, "NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
		printf("BÖLÜM-A (Sonuçlar)\n");
		printf("NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
	}
	else if(f_sonuc == NULL){
		
		f_sonuc = fopen("results.txt", "a");
		fprintf(f_sonuc, "BÖLÜM-A (Sonuçlar)\n");
		fprintf(f_sonuc, "NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
		printf("BÖLÜM-A (Sonuçlar)\n");
		printf("NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
		
	}

	FILE *f_ogr_cevaplar = fopen("answers.txt", "r");
	if (f_ogr_cevaplar != NULL){
		do{
			fflush(stdout);		//çýktý tampon belleðini sil

			fscanf(f_ogr_cevaplar, "%s %c %s", &ogr_no, &ogr_kitapcik, &ogr_cevaplarý);
			//fscanf(dosya, "%s %c %s", &ogr_cvp.no, &ogr_cvp.kitapcik, &ogr_cvp.cevaplar);
			//printf("%s %c %s", ogr_no, ogr_kitapcik, ogr_cevaplarý);

			if (ogr_kitapcik == 'A'){
				for (int x = 0; x < 50; x++){

					kitapcik_a[x].dogru_cevap = cvp_ktp_a[x];
					if (ogr_cevaplarý[x] == 'A') kitapcik_a[x].a_say++;
					if (ogr_cevaplarý[x] == 'B') kitapcik_a[x].b_say++;
					if (ogr_cevaplarý[x] == 'C') kitapcik_a[x].c_say++;
					if (ogr_cevaplarý[x] == 'D') kitapcik_a[x].d_say++;

					if (ogr_cevaplarý[x] == '*'){
						kitapcik_a[x].bos_say++;
					}
					else if (cvp_ktp_a[x] == ogr_cevaplarý[x]){
						dogru_sys++;
					}
					else yanlis_sys++;
				}
			}
			if (ogr_kitapcik == 'B'){
				for (int x = 0; x < 50; x++){

					kitapcik_b[x].dogru_cevap = cvp_ktp_b[x];
					if (ogr_cevaplarý[x] == 'A') kitapcik_b[x].a_say++;
					if (ogr_cevaplarý[x] == 'B') kitapcik_b[x].b_say++;
					if (ogr_cevaplarý[x] == 'C') kitapcik_b[x].c_say++;
					if (ogr_cevaplarý[x] == 'D') kitapcik_b[x].d_say++;

					if (ogr_cevaplarý[x] == '*'){
						kitapcik_b[x].bos_say++;
					}
					else if (cvp_ktp_b[x] == ogr_cevaplarý[x]){
						dogru_sys++;
					}
					else yanlis_sys++;
				}
			}
			//if (ogr_cvp.kitapcik == 'C')
			if (ogr_kitapcik == 'C')
			{
				for (int x = 0; x < 50; x++){

					kitapcik_c[x].dogru_cevap = cvp_ktp_c[x];
					if (ogr_cevaplarý[x] == 'A') kitapcik_c[x].a_say++;
					if (ogr_cevaplarý[x] == 'B') kitapcik_c[x].b_say++;
					if (ogr_cevaplarý[x] == 'C') kitapcik_c[x].c_say++;
					if (ogr_cevaplarý[x] == 'D') kitapcik_c[x].d_say++;

					if (ogr_cevaplarý[x] == '*'){
						kitapcik_c[x].bos_say++;
					}
					else if (cvp_ktp_c[x] == ogr_cevaplarý[x]){
						dogru_sys++;
					}
					else yanlis_sys++;
				}			
			}
			if (ogr_kitapcik == 'D'){
				for (int x = 0; x < 50; x++){

					kitapcik_d[x].dogru_cevap = cvp_ktp_d[x];
					if (ogr_cevaplarý[x] == 'A') kitapcik_d[x].a_say++;
					if (ogr_cevaplarý[x] == 'B') kitapcik_d[x].b_say++;
					if (ogr_cevaplarý[x] == 'C') kitapcik_d[x].c_say++;
					if (ogr_cevaplarý[x] == 'D') kitapcik_d[x].d_say++;

					if (ogr_cevaplarý[x] == '*'){
						kitapcik_d[x].bos_say++;
					}
					else if (cvp_ktp_d[x] == ogr_cevaplarý[x]){
						dogru_sys++;
					}
					else yanlis_sys++;
				}
			}

			puan = (dogru_sys - (float)(yanlis_sys / 5.0)) * 2.0;
			ogr_sayisi++;
			if (dogru_sys == 0 && yanlis_sys == 0)
				puan = 0.0;

			sinav_ort += puan;

			//printf("NO:%s D:%u Y:%u P:%3.2f\n", ogr_no, dogru_sys, yanlis_sys, puan);

			if (ogr_ad_soyad_bul())
			{
				printf("%s\t%s %s\t\t%s\t%u\t%u\t%3.2f\n", ogr_no, ogr.ad, ogr.soyad, ogr.bolum, dogru_sys, yanlis_sys, puan);
				fprintf(f_sonuc, "%s\t%s %s\t\t%s\t%u\t%u\t%3.2f\n", ogr_no, ogr.ad, ogr.soyad, ogr.bolum, dogru_sys, yanlis_sys, puan);
				fprintf(f_sirala_buf, "%s %s %s %s %u %u %3.2f\n", ogr_no, ogr.ad, ogr.soyad, ogr.bolum, dogru_sys, yanlis_sys, puan);
			}
			
			dogru_sys = yanlis_sys = 0;	//deþiþkenleri sýfýrla
			memset(ogr_no, 0, 6);		//ogrneci no yu tutan diziyi sýfýrla. Arama iþlemi öðrenci no ya göre yapýlýyor.
		} while (!feof(f_ogr_cevaplar));
	}
	else{

	}
	fclose(f_sirala_buf);
	fclose(f_ogr_cevaplar);

	printf("\nSINAV ORTALAMASI = %3.2f\n", (float)(sinav_ort / ogr_sayisi));
	fprintf(f_sonuc,"\nSINAV ORTALAMASI = %3.2f\n", (float)(sinav_ort / ogr_sayisi));

	printf("\nBÖLÜM-B (Ýstatistikler)\n");
	fprintf(f_sonuc,"\nBÖLÜM-B (Ýstatistikler)\n");
	printf("Kitapçýk-A\n");
	fprintf(f_sonuc, "Kitapçýk-A\n");

	printf("SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");
	fprintf(f_sonuc, "SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");
	int toplam_abcd = 0;
	for (int x = 0; x < 50; x++){
		toplam_abcd = kitapcik_a[x].a_say + kitapcik_a[x].b_say + kitapcik_a[x].c_say + kitapcik_a[x].d_say;
		if (toplam_abcd !=0){	// sýfýra bölünme hatasýný önlemek için.
			if (kitapcik_a[x].dogru_cevap == 'A')
				basari_orani = ((kitapcik_a[x].a_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_a[x].dogru_cevap == 'B')
				basari_orani = ((kitapcik_a[x].b_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_a[x].dogru_cevap == 'C')
				basari_orani = ((kitapcik_a[x].c_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_a[x].dogru_cevap == 'D')
				basari_orani = ((kitapcik_a[x].d_say) / (toplam_abcd)) * 100.0;
		}
		else basari_orani = 0.0;

		printf("%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x+1, kitapcik_a[x].dogru_cevap, kitapcik_a[x].a_say, kitapcik_a[x].b_say, kitapcik_a[x].c_say, kitapcik_a[x].d_say, kitapcik_a[x].bos_say, basari_orani);
		fprintf(f_sonuc,"%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_a[x].dogru_cevap, kitapcik_a[x].a_say, kitapcik_a[x].b_say, kitapcik_a[x].c_say, kitapcik_a[x].d_say, kitapcik_a[x].bos_say, basari_orani);
	}

	printf("Kitapçýk-B\n");
	fprintf(f_sonuc, "Kitapçýk-B\n");

	printf("SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");
	fprintf(f_sonuc, "SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");

	for (int x = 0; x < 50; x++){
		toplam_abcd = kitapcik_b[x].a_say + kitapcik_b[x].b_say + kitapcik_b[x].c_say + kitapcik_b[x].d_say;
		if (toplam_abcd != 0){
			if (kitapcik_b[x].dogru_cevap == 'A')
				basari_orani = ((kitapcik_b[x].a_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_b[x].dogru_cevap == 'B')
				basari_orani = ((kitapcik_b[x].b_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_b[x].dogru_cevap == 'C')
				basari_orani = ((kitapcik_b[x].c_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_b[x].dogru_cevap == 'D')
				basari_orani = ((kitapcik_b[x].d_say) / (toplam_abcd)) * 100.0;
		}
		else basari_orani = 0.0;

		printf("%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
		fprintf(f_sonuc, "%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
	}

	printf("Kitapçýk-C\n");
	fprintf(f_sonuc, "Kitapçýk-C\n");

	printf("SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");
	fprintf(f_sonuc, "SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");

	for (int x = 0; x < 50; x++){
		toplam_abcd = kitapcik_c[x].a_say + kitapcik_c[x].b_say + kitapcik_c[x].c_say + kitapcik_c[x].d_say;
		if (toplam_abcd != 0){
			if (kitapcik_c[x].dogru_cevap == 'A')
				basari_orani = ((kitapcik_c[x].a_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_c[x].dogru_cevap == 'B')
				basari_orani = ((kitapcik_c[x].b_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_c[x].dogru_cevap == 'C')
				basari_orani = ((kitapcik_c[x].c_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_c[x].dogru_cevap == 'D')
				basari_orani = ((kitapcik_c[x].d_say) / (toplam_abcd)) * 100.0;
		}
		else basari_orani = 0.0;

		printf("%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
		fprintf(f_sonuc, "%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
	}

	printf("Kitapçýk-D\n");
	fprintf(f_sonuc, "Kitapçýk-D\n");

	printf("SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");
	fprintf(f_sonuc, "SORU\tCEVAP\tA\tB\tC\tD\tBOS\tBASARI ORANI\n");

	for (int x = 0; x < 50; x++){
		toplam_abcd = kitapcik_d[x].a_say + kitapcik_d[x].b_say + kitapcik_d[x].c_say + kitapcik_d[x].d_say;
		if (toplam_abcd != 0){
			if (kitapcik_d[x].dogru_cevap == 'A')
				basari_orani = ((kitapcik_d[x].a_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_d[x].dogru_cevap == 'B')
				basari_orani = ((kitapcik_d[x].b_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_d[x].dogru_cevap == 'C')
				basari_orani = ((kitapcik_d[x].c_say) / (toplam_abcd)) * 100.0;
			if (kitapcik_d[x].dogru_cevap == 'D')
				basari_orani = ((kitapcik_d[x].d_say) / (toplam_abcd)) * 100.0;
		}
		else basari_orani = 0.0;

		printf("%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
		fprintf(f_sonuc, "%u\t%c\t%u\t%u\t%u\t%u\t%u\t%3.2f\n",
			x + 1, kitapcik_b[x].dogru_cevap, kitapcik_b[x].a_say, kitapcik_b[x].b_say, kitapcik_b[x].c_say, kitapcik_b[x].d_say, kitapcik_b[x].bos_say, basari_orani);
	}


	fclose(f_sonuc);
	bir_tusa_bas();
}

bool ogr_ad_soyad_bul(){
	 FILE *f_ogr = fopen("students.txt", "r");
	 bool sonuc;
	if (f_ogr != NULL){
		while (!feof(f_ogr)){
			fscanf(f_ogr, "%s %s %s %s",ogr.no,ogr.ad,ogr.soyad,ogr.bolum);
			//result = strcmp(ogr_cvp.no, ogr.no);
			sonuc = karsilastir();
			if (sonuc==true){ // okunan deðer girdiðimiz isme eþitse strcmp 0 döndürür
				//printf("%s %s\n",ogr.ad,ogr.soyad);
				fclose(f_ogr);
				return true;
			}
		}
		fclose(f_ogr);
		return false;
	}
}

bool karsilastir(){
	bool esitmi = true;
	int n = 6;
	for (int i = 0; i<n; ++i){
		if (ogr_no[i] != ogr.no[i]){
			esitmi = false;
		}
	}
	return esitmi;
}

int satir_sayisi_bul(FILE *f){
	char k;
	int satir = 0;
	dosya = fopen(f, "r");
	if (dosya != NULL){

		while ((k = getc(dosya)) != EOF){
			if (k == '\n')satir++;
		}
	}
	else{
		satir = 0;
		return satir;
	}

	fclose(dosya);
	return satir;

}
void bir_tusa_bas(){
	char ch = 0;
	printf("\n\nBir tusa BASIN...\n\n");
	while (ch == 0){
		ch = getche();
	}
}
void ogr_listesi(){
	ekrani_temizle();
	printf("Ogrenci Kayitlari :\n\n");
	for (int x = 0; x < strlen(buf_ogr); x++){
		putchar(buf_ogr[x]);
	}
}
void kitapcik_turune_gore_cevaplari_listele(){
	ekrani_temizle();
	printf("\r\nKitapcik Turune Gore Cevaplar :\n\n");
	for (int x = 0; x < strlen(buf_kitapcik); x++){
		putchar(buf_kitapcik[x]);

	}
}

void ogr_cevaplari_listele(){
	ekrani_temizle();
	printf("\r\nOgrenci Cevaplari :\n\n");
	for (int x = 0; x < strlen(buf_ogr_cevaplar); x++){
		putchar(buf_ogr_cevaplar[x]);
	}
}

void gets_txt_buf(char *buf_txt, FILE *f)
{
	char k;
	int i = 0;
	dosya = fopen(f, "r");
	if (dosya != NULL){
		//printf("Dosya Oku OK ...\r\n");

		while ((k = getc(dosya)) != EOF){
			//putchar(k);
			buf_txt[i++] = k;
		}
	}
	else printf("NONE...\r\n");
	fclose(dosya);
	
}


