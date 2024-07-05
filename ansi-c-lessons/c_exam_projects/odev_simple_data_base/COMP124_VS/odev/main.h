// ana dosya için baþlýk dosyasý

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
	char no[6];
	char ad[30];
	char soyad[30];
	char bolum[11];
}OGRENCI;
OGRENCI ogr;

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