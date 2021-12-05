#include "ogr.h"


void strKucukHarfCevir(char* s) {
	for (; *s != '\0'; s++) {
		if (isupper(*s)) *s = tolower(*s);
	}
}

void strBuyukHarfCevir(char* s) {
	int i;
	/*for (i = 0; s[i] != '\0'; i++) {
		if (islower(s[i])) s[i] = toupper(s[i]);
	}*/

	for (; *s != '\0'; s++)
	{
		if (islower(*s)) *s = toupper(*s);
	}
}


int dosyaSatirSysGetir(const char* dosya_adi) {

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
	return count_lines;
}


void YeniOgrenciEkle() {

	FILE* dosya;
	
	ogrenciTip ogrenci;// = { NULL };  //struct yeni tipte olu�turulan de�i�ken NULL olarak ba�lat�l�yor.
	char cevap = 0;

	if ((dosya = fopen("ogr.txt", "a")) == NULL) // dosyan�n a��l�p a��lmad��� sorgulan�yor.
	{
		fprintf(stdout, "Hata: dosya a�ma....\n");
		exit(EXIT_FAILURE);
	}

	int satir_sayisi = dosyaSatirSysGetir("ogr.txt");

	if (satir_sayisi == 0 || satir_sayisi < 0) satir_sayisi = 1;	//ilk defa dosyaya veri kaydederken hata meydan getiriyor.
	else satir_sayisi++; //bir sonraki sat�ra kaydet.

	do {
		konsolTemizle();
		fflush(stdin);

		printf("\n*** YEN� KAYIT EKLEME I�LEMI\n");
		/* Kullan�c�n�n giri�i s�ras�nda tel(7 karkter), ve alan kodlar�(3 karakter)
		   uyugun formatta m� sorgulanmal� de�ilse uyugn formatta
		   yeniden giri� istenmeli.
		*/

		printf("\nAd		: ");
		scanf("%s", ogrenci.isim);

		printf("\nSoyad		: ");
		scanf("%s", ogrenci.soy_isim);

		printf("\nders Kodu	: ");
		scanf("%s", ogrenci.dersadi);		//3+1


		printf("\nnot1		: ");
		scanf("%f", &ogrenci.not1);

		printf("\nnot2		: ");
		scanf("%f", &ogrenci.not2);	//7+1

		printf("\nnot3		: ");
		scanf("%f", &ogrenci.not3);

		ogrenci.ortalama = (ogrenci.not1 + ogrenci.not2 + ogrenci.not3) / 3.0;

			//�Arya Su 1Not:90.10 2.Not:87.68 3:not94.56 ortalama: 90.78� 
		printf("\n%s %s 1.Not: %.2f 2Not: %.2f 3.Not %.2f Ortalama: %.2f\n", 
			ogrenci.isim, ogrenci.soy_isim, ogrenci.not1, ogrenci.not2, ogrenci.not3, ogrenci.ortalama);

		printf("\nKaydedilsin mi?(E/H)\n");
		cevap = _getch();

		if (cevap == 'E' || cevap == 'e') {

			fprintf(dosya, "%u %s %s %s %.2f %.2f %.2f\n", 
				satir_sayisi, ogrenci.isim, ogrenci.soy_isim, ogrenci.dersadi,ogrenci.not1, ogrenci.not2, ogrenci.not3, ogrenci.ortalama);

			printf("\nKay�t i�lemi BA�ARILI ...\n");
			satir_sayisi++; //yeni kay�t i�in
		}

		printf("\nBa�ka Kayit ?(E/H)\n");
		cevap = _getch();

	} while (cevap == 'E' || cevap == 'e');


	fclose(dosya);
}


int menuOlustur(void)
{
	int id;

	konsolTemizle();

	printf(".........................................................\n");
	printf("\n        ## Telefon Rehberi Menu ��lemleri ##\n\n");
	/*		Listeleme i�lemleri*/
	printf(".........................................................\n");
	printf("[1]. Yeni �grenci Kaydet\n");
	printf("[2]. Kay�tl� �grenciyi G�ncelle\n");
	printf("[3]. Rehberden Sil\n");
	printf("[4]. Listele RAW Dosyadan\n");
	printf("[5]. Listele Formatl� Dosyadan\n");
	printf("[6]. �grenci Ara-Bul \n\n");

	printf("[9]. ��k��\n");

	do {
		printf("\n��leminiz ? [1-9]: ");
		id = _getche() - '0';	//getche() :Karakter girilir girilmez okuma i�lemi ger�ekle�ir
								//Se�im karakter bir say� olaca�� i�in '1'-'9' aras� karakterin
								//1-9 aras� say�ya �evirmek amac�yla '0' karakterinden ��kar�yoruz.
		printf("\n");

	} while (id < 1 || id>9);

	return id;
}


void ilkDosayaOlustur(const char* dosya_yol) {                    
	FILE* dosya;

	//mesaj = -5;

	if ((dosya = fopen(dosya_yol, "r")) == NULL) // dosyan�n a��l�p a��lmad��� sorgulan�yor.
	{
		if ((dosya = fopen(dosya_yol, "w")) == NULL) {
			fprintf(stdout, "Hata: dosya a�ma....\n");
			exit(EXIT_FAILURE);
		}
		else {
			//Format lama i�leminde -13s soldan itibaren 13 karkter bo�luk koy anlam�na geliyor.
			//Buradaki printf format� kay�t ilemindeki ile ayn� olmal�, tab kullanmadan -s ile ayarlanmal�
			fprintf(dosya, "-------------------------------------------------------------------------\n");
			fprintf(dosya, "%-5s %-13s %-22s %-10s %-10s %-10s\n", "#", "ISIM", "SOYISIM", "DERSADI", "NOT1", "NOT2", "NOT3", "ORTALAMA");
			fprintf(dosya, "-------------------------------------------------------------------------\n");
		}

	}

	if (fclose(dosya) != 0)  //Dosya kapat�l�yor...
		printf("Dosya kapama hatasi...\n");

	if ((dosya = fopen(dosya_yol, "r")) == NULL) {
		if ((dosya = fopen(dosya_yol, "w")) == NULL) {
			fprintf(stdout, "Hata: dosya a�ma....\n");
			exit(EXIT_FAILURE);
		}

	}


}

void Listele()
{
	FILE* dosya1;
	char buf[100];
	int satir_sayisi = dosyaSatirSysGetir("ogr.txt");
	int satir_say = 0;

	konsolTemizle();
	fflush(stdout);

		if ((dosya1 = fopen("ogr.txt", "r")) == NULL) // dosyan�n a��l�p a��lmad��� sorgulan�yor.
		{
			fprintf(stdout, "Hata: dosya a�ma....\n");
			exit(EXIT_FAILURE);
		}
		printf("     ### FORMATLI DOSYA LISTELEMESI ###\n\n");

		while (!feof(dosya1) && satir_say < satir_sayisi + 3) {

			fgets(buf, 100, dosya1);

			printf("%s", buf);
			satir_say++;
		}

		fclose(dosya1);

	
}

void struct_swap(ogrenciTip* a, ogrenciTip* b) {

	ogrenciTip temp = *a;  //a n�n adresteki de�erini temp e kopyala
	*a = *b;                //b n�n adresteki de�erini a ya kopyala
	*b = temp;

}

ogrenciTip* dosya_oku(const char* dosya_yol, int* satir_al) {

	FILE* dosya;
	int index = 0;
	char sayi[10];

	int depo_eleman_sys = dosyaSatirSysGetir(dosya_yol);

	ogrenciTip* depo = (ogrenciTip*)malloc(sizeof(ogrenciTip) * (depo_eleman_sys+1));  //dinamik bellek

	//tel_reh_tip depo[depo_eleman_sys];  // tel_reh_tip depo[7];

	if ((dosya = fopen(dosya_yol, "r")) == NULL) // dosyan�n a��l�p a��lmad��� sorgulan�yor.
	{
		fprintf(stdout, "Hata: dosya acma....\n");
		exit(EXIT_FAILURE);
	}

	//rewind(dosya); /* dosyan�n ba��na git...*/
	/* Dosya okunuyor ve i�eri�i struct diziye satir satir kaydediliyor...*/
	while (!feof(dosya) && index < depo_eleman_sys) {


		fscanf(dosya, "%u %s %s %s %f %f %f %f\n", sayi, depo[index].isim, depo[index].soy_isim, depo[index].dersadi,
															depo[index].not1, depo[index].not2, depo[index].not3, depo[index].ortalama);
     	strBuyukHarfCevir(depo[index].isim);
		strBuyukHarfCevir(depo[index].soy_isim);
		index++;
	}
	*satir_al = depo_eleman_sys;
	if (fclose(dosya) != 0)  //Dosaya kapat�l�yor...
		printf("Dosya kapama hatasi...\n");

	return depo;
}


void struct_sirala(ogrenciTip* ogrenciler, int sayi, bool sirala_yon, int sirala_alan) {


	for (size_t i = 0; i < sayi; i++)
	{
		for (size_t j = 0; j < sayi - 1; j++)
		{
			if (sirala_yon) {
				if (strcmp(ogrenciler[i].isim, ogrenciler[j].isim) < 0)
					//if (_rehber[i].isim[0] < _rehber[j].isim[0])    //k���kten b�y��e do�ru (descending)
				{
					struct_swap(&ogrenciler[i], &ogrenciler[j]);
				}
			}

			else
				if (strcmp(ogrenciler[i].isim, ogrenciler[j].isim) > 0)
					//if (_rehber[i].isim[0] > _rehber[j].isim[0])	  //b�y�kten k����e do�ru s�ralama...(ascending)
				{
					struct_swap(&ogrenciler[i], &ogrenciler[j]);
				}

		}
	}/* s�ralama i�lemi sonunda struct ta bulunan b�t�n �yeler de s�ralamaya uygun �ekilde
	 yer de�i�tirip ��renciye ait bilgiler korunmu� olur....*/
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline
		if (find) // if the address is not NULL,
			*find = '\0'; // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}


void birTusaBas() {
	char ch = 0;
	printf("\n\nDevam etmek i�in bir tu�a bas�n...\n\n");
	while (ch == 0) {
		ch = _getche();  // Error C4996 'getch':The POSIX name for this item is deprecated.Instead, use the ISO Cand C++ conformant name : _getch
	}
}


void ogrenciAra() {
	konsolTemizle();

	char isim[50];
	int satirsayisi = 0;

	printf("ismi girin:");
	scanf("%s", isim);

	ogrenciTip* kisiler = dosya_oku("ogr.txt", &satirsayisi);

	for (size_t i = 0; i < satirsayisi; i++)
	{
		if (strcmp(isim, kisiler[i].isim) == 0)
		{
			
			printf("%u %s %s %s %.2f %.2f %.2f\n", kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].not1, kisiler[i].not2, kisiler[i].not3, kisiler[i].ortalama);
		}


	}
}

void ogrenciSil() {
	konsolTemizle();

	char cevap = 0;
	char isim[50];
	char soyisim[50];

	int satirsayisi = 0;

	printf("ismi girin:");
	scanf("%s", isim);

	printf("soy ismi girin:");
	scanf("%s", soyisim);

	strBuyukHarfCevir(isim);
	strBuyukHarfCevir(soyisim);

	ogrenciTip* kisiler = dosya_oku("ogr.txt", &satirsayisi);

	for (size_t i = 0; i < satirsayisi; i++)
	{

		if (strcmp(isim, kisiler[i].isim) == 0 && strcmp(soyisim, kisiler[i].soy_isim) == 0) {

			
			printf("%s %s %2.2f %2.2f %2.2f %2.2f\n", kisiler[i].isim, kisiler[i].soy_isim, 
												kisiler[i].not1, kisiler[i].not2, kisiler[i].not3, kisiler[i].ortalama);

			printf("\nSIL ?(E/H)\n");
			cevap = _getch();

			if ((cevap == 'e') || (cevap == 'E'))
			{
				FILE* dosya;
				dosya = fopen("ogr.txt", "w");

				for (size_t x = 0; x < satirsayisi; x++)
				{
					if (x < i) {
						// str sys j ile ayn�
						printf("%u %s %s %s %.2f %.2f %.2f %.2\n", x,kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].dersadi,
																   kisiler[i].not1, kisiler[i].not2, kisiler[i].not3, kisiler[i].ortalama);
					}

					if (x > i) {
						// str sys j-1 olacak
						printf("%u %s %s %s %.2f %.2f %.2f %.2\n", x, kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].dersadi,
							kisiler[i].not1, kisiler[i].not2, kisiler[i].not3, kisiler[i].ortalama);

					}
				}

				fclose(dosya);
				break;
			}
			else return;
		}


	}



}

//void virgulToNokta(char )



//void Duzenle() {
//	konsolTemizle();
//
//	char cevap[3] = { 0 };
//	char isim[50];
//	char soyisim[50];
//
//	int satirsayisi = 0;
//
//	printf("ismi girin:");
//	scanf("%s", isim);
//
//	printf("soy ismi girin:");
//	scanf("%s", soyisim);
//
//	strBuyukHarfCevir(isim);
//	strBuyukHarfCevir(soyisim);
//
//	ogrenciTip* ogrenci = dosya_oku("ogrenciListesi.txt", &satirsayisi);
//
//	for (size_t i = 0; i < satirsayisi; i++)
//	{
//
//		if (strcmp(isim, ogrenci[i].isim) == 0 && strcmp(soyisim, ogrenci[i].soy_isim) == 0) {
//
//			
//			printf("%u %s %s %s %.2f %.2f %.2f\n", ogrenci[i].isim, ogrenci[i].soy_isim, ogrenci[i].not1, ogrenci[i].not2, ogrenci[i].not3, ogrenci[i].ortalama);
//
//			printf("\nDegistir?(E/H)\n");
//			scanf("%s", cevap);
//
//			if ((cevap[0] == 'e') || (cevap[0] == 'E'))
//			{
//
//				printf("\nAd		: ");
//				scanf("%s", ogrenci.isim);
//
//				printf("\nSoyad		: ");
//				scanf("%s", ogrenci.soy_isim);
//
//				printf("\nders Kodu	: ");
//				scanf("%s", ogrenci.dersadi);		//3+1
//
//
//				printf("\nnot1	: ");
//				scanf("%f", &ogrenci.not1);
//
//				printf("\nnot		: ");
//				scanf("%f", &ogrenci.not2);	//7+1
//
//				printf("\nnot: ");
//				scanf("%f", &ogrenci.not3);
//
//
//				FILE* dosya;
//				dosya = fopen("ogrenciListesi.txt", "w");
//
//				for (size_t x = 0; x < satirsayisi; x++)
//				{
//					printf("%u %s %s %s %.2f %.2f %.2f\n", ogrenci[i].isim, ogrenci[i].soy_isim, ogrenci[i].not1, ogrenci[i].not2, ogrenci[i].not3, ogrenci[i].ortalama);
//				}
//
//				fclose(dosya);
//				break;
//			}
//			else return;
//		}
//
//
//	}
//}


