/*	Alt fonksiyonlar	*/
#include "rehber.h"

int menuOlustur(void)
{
	int id;

	konsolTemizle();

	printf(".........................................................\n");
	printf("\n        ## Telefon Rehberi Menu Ýþlemleri ##\n\n");
	/*		Listeleme iþlemleri*/
	printf(".........................................................\n");
	printf("[1]. Yeni Kiþi Kaydet\n");
	printf("[2]. Kayýtlý Kiþiyi Güncelle\n");
	printf("[3]. Rehberden Sil\n");
	printf("[4]. Rehberi Listele RAW Dosyadan\n");
	printf("[5]. Rehberi Listele Formatlý Dosyadan\n");
	printf("[6]. Rehberde Ara\n\n");
	printf("[7]..........\n");
	printf("[8]. ........\n");
	printf(".........................................................\n");
	printf("[9]. Çýkýþ\n");
	printf(".........................................................\n");
	do {
		printf("\nÝþleminiz ? [1-9]: ");
		id = _getche() - '0';	//getche() :Karakter girilir girilmez okuma iþlemi gerçekleþir
								//Seçim karakter bir sayý olacaðý için '1'-'9' arasý karakterin
								//1-9 arasý sayýya çevirmek amacýyla '0' karakterinden çýkarýyoruz.
		printf("\n");

	} while (id < 1 || id>9);

	return id;
}

void ilkDosayaOlustur(const char* dosya_yol) {
	FILE* dosya;

	mesaj = -5;

	if ((dosya = fopen(dosya_yol, "r")) == NULL) // dosyanýn açýlýp açýlmadýðý sorgulanýyor.
	{
		if ((dosya = fopen(dosya_yol, "w")) == NULL) {
			fprintf(stdout, "Hata: dosya açma....\n");
			exit(EXIT_FAILURE);
		}
		else {
			//Format lama iþleminde -13s soldan itibaren 13 karkter boþluk koy anlamýna geliyor.
			//Buradaki printf formatý kayýt ilemindeki ile ayný olmalý, tab kullanmadan -s ile ayarlanmalý
			fprintf(dosya, "-------------------------------------------------------------------------\n");
			fprintf(dosya, "%-5s %-13s %-22s %-10s %-10s %-10s\n", "#", "ISIM", "SOYISIM", "ULKE", "ALAN", "TELEFON");
			fprintf(dosya, "-------------------------------------------------------------------------\n");
		}

	}

	if (fclose(dosya) != 0)  //Dosya kapatýlýyor...
		printf("Dosya kapama hatasi...\n");

	if ((dosya = fopen(RAW_DOSYA, "r")) == NULL) {

		if ((dosya = fopen(RAW_DOSYA, "w")) == NULL) {
			fprintf(stdout, "Hata: dosya açma....\n");
			exit(EXIT_FAILURE);
		}

	}

	if (fclose(dosya) != 0)  //Dosya kapatýlýyor...
		printf("Dosya kapama hatasi...\n");

}

void rehberiListele(int bicim)
{
	FILE* dosya;
	char buf[100];
	int satir_sayisi = dosyaSatirSysGetir(RAW_DOSYA);
	int satir_say = 0;

	konsolTemizle();
	fflush(stdout);

	if (bicim == FORMATLI_DOSYA) {

		if ((dosya = fopen("tel_rehberi.txt", "r")) == NULL) // dosyanýn açýlýp açýlmadýðý sorgulanýyor.
		{
			fprintf(stdout, "Hata: dosya açma....\n");
			exit(EXIT_FAILURE);
		}
		printf("     ### FORMATLI DOSYA LISTELEMESI ###\n\n");

		while (!feof(dosya) && satir_say < satir_sayisi + 3) {

			fgets(buf, 100, dosya);

			printf("%s", buf);
			satir_say++;
		}

		fclose(dosya);
	}
	else if (bicim == RAW_DOSYA) {
		printf("     ### RAW DOSYA LISTELEMESI ###\n\n");

		tel_reh_tip* tel_sirala = dosya_oku(RAW_DOSYA, &satir_sayisi);

		struct_sirala(tel_sirala, satir_sayisi, KUCUK_TEN_BUYUGE, ADI);

		printf("-------------------------------------------------------------------------\n");
		printf("%-5s %-13s %-22s %-10s %-10s %-10s\n", "#", "ISIM", "SOYISIM", "ULKE", "ALAN", "TELEFON");
		printf("-------------------------------------------------------------------------\n");

		for (size_t i = 0; i < satir_sayisi; i++)
		{
			printf("%-5u %-13s %-22s %-10s %-10s %-10s\n", i + 1, tel_sirala[i].isim, tel_sirala[i].soy_isim,
				tel_sirala[i].ulke_kodu, tel_sirala[i].alan_kodu, tel_sirala[i].tel);
		}

		printf("-------------------------------------------------------------------------\n");
	}


}

void rehbereKayitEkle(const char* dosya_yol) {

	FILE* dosya;
	FILE* f_raw;

	tel_reh_tip rehber;// = { NULL };  //struct yeni tipte oluþturulan deðiþken NULL olarak baþlatýlýyor.
	char cevap = 0;

	int satir_sayisi = dosyaSatirSysGetir(RAW_DOSYA);

	if ((f_raw = fopen(RAW_DOSYA, "a")) == NULL) // dosyanýn açýlýp açýlmadýðý sorgulanýyor.
	{
		fprintf(stdout, "Hata: dosya açma....\n");
		exit(EXIT_FAILURE);
	}

	if (satir_sayisi == 0 || satir_sayisi < 0) satir_sayisi = 1;	//ilk defa dosyaya veri kaydederken hata meydan getiriyor.
	else satir_sayisi++; //bir sonraki satýra kaydet.

	do {
		konsolTemizle();
		fflush(stdin);

		printf("\n*** REHBERE YENÝ KAYIT EKLEME IÞLEMI\n");
		/* Kullanýcýnýn giriþi sýrasýnda tel(7 karkter), ve alan kodlarý(3 karakter)
		uyugun formatta mý sorgulanmalý deðilse uyugn formatta
		yeniden giriþ istenmeli.
		*/

		printf("\nAd		: ");
		s_gets(rehber.isim, 50);

		printf("\nSoyad		: ");
		s_gets(rehber.soy_isim, 50);

		printf("\nÜlke Kodu	: ");
		s_gets(rehber.ulke_kodu, 4);		//3+1

		printf("\nAlan Kodu	: ");
		s_gets(rehber.alan_kodu, 4);

		printf("\nTelefon		: ");
		s_gets(rehber.tel, 8);	//7+1

								/* Aþaðýdaki sorgulama yapýlmazsa "tel_reh_tip *dosya_oku(const char *dosya_yol, int *satir_al)"
								fonksiyonunda dosya okuma için kullanýlan fscanf okuma formatý bozulduðundan dosyadan veriler
								yanlýþ okunuyor.
								Eðer konsoldan bir deðper girilmemiþse fscanf de verilen okuma formatýndan baþka bir karakter
								dosyaya yazdýrýlmalý. Böylece scanf okuma formatý bozulmamýþ olur.
								*/
		if (strcmp(rehber.isim, "") == 0)
			strcpy(rehber.isim, "---");

		if (strcmp(rehber.soy_isim, "") == 0)
			strcpy(rehber.soy_isim, "---");

		if (strcmp(rehber.ulke_kodu, "") == 0)
			strcpy(rehber.ulke_kodu, "---");

		if (strcmp(rehber.alan_kodu, "") == 0)
			strcpy(rehber.alan_kodu, "---");

		if (strcmp(rehber.tel, "") == 0)
			strcpy(rehber.tel, "---");


		//“Cem Kalyoncu, Tel: +90 (542) 652-1234” 
		printf("\n%s %s, Tel: %s (%s) %s\n", rehber.isim, rehber.soy_isim, rehber.ulke_kodu, rehber.alan_kodu, rehber.tel);

		printf("\nKaydedilsin mi?(E/H)\n");
		cevap = _getch();

		if (cevap == 'E' || cevap == 'e') {

			fprintf(f_raw, "%u %s %s %s %s %s\n", satir_sayisi, rehber.isim, rehber.soy_isim, rehber.ulke_kodu, rehber.alan_kodu, rehber.tel);
			printf("\nKayýt iþlemi BAÞARILI ...\n");
			satir_sayisi++; //yeni kayýt için
		}

		printf("\nBaþka Kayit ?(E/H)\n");
		cevap = _getch();

	} while (cevap == 'E' || cevap == 'e');


	fclose(f_raw);

	/* Rehbere raw dosyadaki bilgiler sýralý bir þekilde yazdýrýlýyor...*/

	if ((dosya = fopen(dosya_yol, "w")) == NULL) // dosyanýn açýlýp açýlmadýðý sorgulanýyor.
	{
		fprintf(stdout, "Hata: dosya açma....\n");
		exit(EXIT_FAILURE);
	}

	tel_reh_tip* tel_sirala = dosya_oku(RAW_DOSYA, &satir_sayisi);  // Sýralama iþleminin doðru olmasý için 
																	// AD ve soyad bilgileri büyük harfe yada
																	// küçük harfe dönüþtürülmeli.
	struct_sirala(tel_sirala, satir_sayisi, KUCUK_TEN_BUYUGE, ADI);

	fprintf(dosya, "-------------------------------------------------------------------------\n");
	fprintf(dosya, "%-5s %-13s %-22s %-10s %-10s %-10s\n", "#", "ISIM", "SOYISIM", "ULKE", "ALAN", "TELEFON");
	fprintf(dosya, "-------------------------------------------------------------------------\n");

	for (size_t i = 0; i < satir_sayisi; i++)
	{
		diziArayaKarakterKoy(tel_sirala[i].tel, 4, ' ');

		fprintf(dosya, "%-5u %-13s %-22s %-10s %-10s %-10s\n", i + 1, tel_sirala[i].isim, tel_sirala[i].soy_isim,
			tel_sirala[i].ulke_kodu, tel_sirala[i].alan_kodu, tel_sirala[i].tel);
	}

	fclose(dosya);

}

void struct_swap(tel_reh_tip* a, tel_reh_tip* b) {

	tel_reh_tip temp = *a;  //a nýn adresteki deðerini temp e kopyala
	*a = *b;                //b nýn adresteki deðerini a ya kopyala
	*b = temp;

}

tel_reh_tip* dosya_oku(const char* dosya_yol, int* satir_al) {

	FILE* dosya;
	int index = 0;
	char sayi[10];

	int depo_eleman_sys = dosyaSatirSysGetir(dosya_yol);

	tel_reh_tip* depo = (tel_reh_tip*)malloc(sizeof(tel_reh_tip) * (depo_eleman_sys));  //dinamik bellek

																						//tel_reh_tip depo[depo_eleman_sys];  // tel_reh_tip depo[7];

	if ((dosya = fopen(dosya_yol, "r")) == NULL) // dosyanýn açýlýp açýlmadýðý sorgulanýyor.
	{
		fprintf(stdout, "Hata: dosya acma....\n");
		exit(EXIT_FAILURE);
	}

	//rewind(dosya); /* dosyanýn baþýna git...*/
	/* Dosya okunuyor ve içeriði struct diziye satir satir kaydediliyor...*/
	while (!feof(dosya) && index < depo_eleman_sys) {
		fscanf(dosya, "%s %s %s %s %s %s", sayi, depo[index].isim, depo[index].soy_isim, depo[index].ulke_kodu, depo[index].alan_kodu, depo[index].tel);
		strBuyukHarfCevir(depo[index].isim);
		strBuyukHarfCevir(depo[index].soy_isim);
		index++;
	}
	*satir_al = depo_eleman_sys;

	if (fclose(dosya) != 0)  //Dosaya kapatýlýyor...
		printf("Dosya kapama hatasi...\n");

	return depo;
}


void struct_sirala(tel_reh_tip* _rehber, int sayi, bool sirala_yon, int sirala_alan) {


	for (size_t i = 0; i < sayi; i++)
	{
		for (size_t j = 0; j < sayi - 1; j++)
		{
			if (sirala_yon) {
				if (strcmp(_rehber[i].isim, _rehber[j].isim) < 0)
					//if (_rehber[i].isim[0] < _rehber[j].isim[0])    //küçükten büyüðe doðru (descending)
				{
					struct_swap(&_rehber[i], &_rehber[j]);
				}
			}

			else
				if (strcmp(_rehber[i].isim, _rehber[j].isim) > 0)
					//if (_rehber[i].isim[0] > _rehber[j].isim[0])	  //büyükten küçüðe doðru sýralama...(ascending)
				{
					struct_swap(&_rehber[i], &_rehber[j]);
				}

		}
	}/* sýralama iþlemi sonunda struct ta bulunan bütün üyeler de sýralamaya uygun þekilde
	 yer deðiþtirip öðrenciye ait bilgiler korunmuþ olur....*/
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

void diziArayaKarakterKoy(char* arr, int location, char ch) {

	int len = strlen(arr);
	for (size_t i = len; i >= location; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[location - 1] = ch;
	arr[len + 1] = '\0';		// diziyi string yap.
}


void birTusaBas() {
	char ch = 0;
	printf("\n\nDevam etmek için bir tuþa basýn...\n\n");
	while (ch == 0) {
		ch = _getche();  // Error C4996 'getch':The POSIX name for this item is deprecated.Instead, use the ISO Cand C++ conformant name : _getch
	}
}

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


void RehberdeAra() {
	konsolTemizle();

	char isim[50];
	int satirsayisi = 0;

	printf("ismi girin:");
	scanf("%s", isim);

	tel_reh_tip* kisiler = dosya_oku(RAW_DOSYA, &satirsayisi);

	for (size_t i = 0; i < satirsayisi; i++)
	{
		if (strcmp(isim, kisiler[i].isim) == 0)
		{
			diziArayaKarakterKoy(kisiler[i].tel, 4, '-');
			printf("%s %s,tel: %s(%s) %s\n", kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].ulke_kodu, kisiler[i].alan_kodu, kisiler[i].tel);
		}


	}
}

void RehberdenSil() {
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

	tel_reh_tip* kisiler = dosya_oku(RAW_DOSYA, &satirsayisi);

	for (size_t i = 0; i < satirsayisi; i++)
	{

		if (strcmp(isim, kisiler[i].isim) == 0 && strcmp(soyisim, kisiler[i].soy_isim) == 0) {

			diziArayaKarakterKoy(kisiler[i].tel, 4, '-');
			printf("%s %s,tel: %s(%s) %s\n", kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].ulke_kodu, kisiler[i].alan_kodu, kisiler[i].tel);

			printf("\nSIL ?(E/H)\n");
			cevap = _getch();

			if ((cevap == 'e') || (cevap == 'E'))
			{
				FILE* dosya;
				dosya = fopen(RAW_DOSYA, "w");

				for (size_t x = 0; x < satirsayisi; x++)
				{
					if (x < i) {
						// str sys j ile ayný
						fprintf(dosya, "%u %s %s %s %s %s\n", x + 1, kisiler[x].isim, kisiler[x].soy_isim,
							kisiler[x].ulke_kodu, kisiler[x].alan_kodu, kisiler[x].tel);

					}

					if (x > i) {
						// str sys j-1 olacak
						fprintf(dosya, "%u %s %s %s %s %s\n", x, kisiler[x].isim, kisiler[x].soy_isim,
							kisiler[x].ulke_kodu, kisiler[x].alan_kodu, kisiler[x].tel);

					}
				}

				fclose(dosya);
				break;
			}
			else return;
		}


	}



}


void RehberDuzenle() {
	konsolTemizle();

	char cevap[3] = { 0 };
	char isim[50];
	char soyisim[50];

	int satirsayisi = 0;

	printf("ismi girin:");
	scanf("%s", isim);

	printf("soy ismi girin:");
	scanf("%s", soyisim);

	strBuyukHarfCevir(isim);
	strBuyukHarfCevir(soyisim);

	tel_reh_tip* kisiler = dosya_oku(RAW_DOSYA, &satirsayisi);

	for (size_t i = 0; i < satirsayisi; i++)
	{

		if (strcmp(isim, kisiler[i].isim) == 0 && strcmp(soyisim, kisiler[i].soy_isim) == 0) {

			diziArayaKarakterKoy(kisiler[i].tel, 4, '-');
			printf("%s %s,tel: %s(%s) %s\n", kisiler[i].isim, kisiler[i].soy_isim, kisiler[i].ulke_kodu, kisiler[i].alan_kodu, kisiler[i].tel);

			printf("\nDegistir?(E/H)\n");
			scanf("%s", cevap);

			if ((cevap[0] == 'e') || (cevap[0] == 'E'))
			{
				printf("\nAd		: ");
				scanf("%s", kisiler[i].isim);

				printf("\nSoyad		: ");
				scanf("%s", kisiler[i].soy_isim);

				printf("\nÜlke Kodu	: ");
				scanf("%s", kisiler[i].ulke_kodu);		//3+1

				printf("\nAlan Kodu	: ");
				scanf("%s", kisiler[i].alan_kodu);

				printf("\nTelefon		: ");
				scanf("%s", kisiler[i].tel);	//7+1

												/* Aþaðýdaki sorgulama yapýlmazsa "tel_reh_tip *dosya_oku(const char *dosya_yol, int *satir_al)"
												fonksiyonunda dosya okuma için kullanýlan fscanf okuma formatý bozulduðundan dosyadan veriler
												yanlýþ okunuyor.
												Eðer konsoldan bir deðper girilmemiþse fscanf de verilen okuma formatýndan baþka bir karakter
												dosyaya yazdýrýlmalý. Böylece scanf okuma formatý bozulmamýþ olur.
												*/
				if (strcmp(kisiler[i].isim, "") == 0)
					strcpy(kisiler[i].isim, "---");

				if (strcmp(kisiler[i].soy_isim, "") == 0)
					strcpy(kisiler[i].soy_isim, "---");

				if (strcmp(kisiler[i].ulke_kodu, "") == 0)
					strcpy(kisiler[i].ulke_kodu, "---");

				if (strcmp(kisiler[i].alan_kodu, "") == 0)
					strcpy(kisiler[i].alan_kodu, "---");

				if (strcmp(kisiler[i].tel, "") == 0)
					strcpy(kisiler[i].tel, "---");


				FILE* dosya;
				dosya = fopen(RAW_DOSYA, "w");

				for (size_t x = 0; x < satirsayisi; x++)
				{
					fprintf(dosya, "%u %s %s %s %s %s\n", x + 1, kisiler[x].isim, kisiler[x].soy_isim,
						kisiler[x].ulke_kodu, kisiler[x].alan_kodu, kisiler[x].tel);
				}

				fclose(dosya);
				break;
			}
			else return;
		}


	}
}

void sil_2_dosya() {

	FILE *dosya, *yedek;//

	char isim[20];
	char soyisim[20];
	char s_sayi[5];
	int sayi = 0;

	tel_reh_tip depo;

	dosya = fopen(RAW_DOSYA, "r");//okunacak dosya
	yedek = fopen("yedek.txt", "w");

	konsolTemizle();

	printf("\n***** REHBERDEN KAYIT SILME IÞLEMI  ****\n ");
	printf("\nSilinecek ogrencinin adini giriniz : ");
	scanf("%s", isim);
	printf("\nSilinecek ogrencinin soy adini giriniz : ");
	scanf("%s", soyisim);

	strBuyukHarfCevir(isim);
	strBuyukHarfCevir(soyisim);

	bool sil_kayit=false;

	while (!feof(dosya))
	{
		fscanf(dosya, "%s %s %s %s %s %s", s_sayi, depo.isim, depo.soy_isim, depo.ulke_kodu, depo.alan_kodu, depo.tel);

		strBuyukHarfCevir(depo.isim);
		strBuyukHarfCevir(depo.soy_isim);

		if (!(strcmp(isim, depo.isim) == 0 && strcmp(soyisim, depo.soy_isim) == 0)) {

			fprintf(yedek, "%d %s %s %s %s %s\n", ++sayi, depo.isim, depo.soy_isim, depo.ulke_kodu, depo.alan_kodu, depo.tel);
		}
		else {
			sil_kayit = true;
		}

	}

	fclose(dosya);
	fclose(yedek);

	/*free(dosya);
	free(yedek);*/
	
	if (sil_kayit) {

		int ret = remove(RAW_DOSYA); //silmek icin
	    //int ret = _unlink(RAW_DOSYA); //silmek icin

		if (ret == 0) {
			rename("yedek.txt", RAW_DOSYA); // isim deðiþikliði için

			puts("\nSilme islemi tamamlandi ! Devam etmek icin bir tusa basin...\n");
		}
		else {
			printf("\nHata: Kayýt bulunamadý veya silme iþleminde hata !!!\n");
			remove("yedek.txt"); // hata varsa yedek.txt dosyasýna ihtiyaç yokkkk.
		}

		
	}
	else {
		printf("\nHata: Kayýt bulunamadý veya silme iþleminde hata !!!\n");
		remove("yedek.txt"); // hata varsa yedek.txt dosyasýna ihtiyaç yokkkk.
	}

	
}

