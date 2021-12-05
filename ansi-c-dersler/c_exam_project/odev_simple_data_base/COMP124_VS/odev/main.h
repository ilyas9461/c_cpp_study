// ana dosya i�in ba�l�k dosyas�

//Ekran� temizlemeek i�in olu�turulan makro.
#define ekrani_temizle() system("CLS")

//Sonu� dosyas� olu�turulurken kitap��k t�r�ne g�re 
//istatistik ded�erlerin tutuldu�u yap�.
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

//��rencilerile ilgili bilgilerin tutuldu�u yap�.
//��renciler dosyas�nda gelen verileri tutar.
typedef struct
{
	char no[6];
	char ad[30];
	char soyad[30];
	char bolum[11];
}OGRENCI;
OGRENCI ogr;

//Cevaplar dosyas�ndan gelen verileri tuttan yap�.
typedef struct
{
	char no[6];
	char kitapcik;
	char cevaplar[50];
}OGRENCI_CEVAP;
OGRENCI_CEVAP ogr_cvp;

//global de�i�kenler
char buf_ogr[1000];				//��renciler dosyas� ba�lang��ta bu diziye al�n�r.
char buf_kitapcik[1000];		//Kitap��klarla ilgili verilern bilgiler bu dizide tutulur.
char buf_ogr_cevaplar[1000];	// ��renci cevaplar� bu dizide tutulur.

char cvp_ktp_a[50];		//Her soruya ait do�ru cevaplar�n tutuldu�u diziler.
char cvp_ktp_b[50];
char cvp_ktp_c[50];
char cvp_ktp_d[50];

char ogr_no[6];			//��renci NO yu tutar.
char ogr_kitapcik = 0;	//��rencinin kitap��k t�r�n� tutar.
char ogr_cevaplar�[50];	//��renci cevplar�n�� tutar.

FILE *dosya;

// Kullan�lan Fonksiyonlara ait tan�mlamalar
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