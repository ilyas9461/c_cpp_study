/* Konsoldan klavye ile girilen bir karakter dizisindeki(string) türkçe karakerlerin yerlerini
  bulan program... Konsoldan giriþ-çýkýþ iþlemlerinde Türkçe karakter kullanýlmasýný saðlar.
*/

#include <stdio.h>          // Preprocessor directive
#include <string.h>			//Karakterlerle ilgili iþlemleri yapabilmek için.
#include <locale.h>			// Dile göre karakter seti seçmak için.
#include <windows.h>		// Arkaplan ve yazý rengi
#include <conio.h>			//console input/output. https://anilozbek.blogspot.com/2017/10/conioh.html
#include <wchar.h>			//geniþ karakter kullanýmý için geerekli tip ve fonksiyonlar için.
#include <consoleapi.h>		//console için karakter ayarlama ile ilgili komutlar .

//Konsola yazma(çýkýþ) ve okuma(giriþ) iþlemlerinde türkçe karakterlerin kullanýlmasýný
//saðlayan fonksiyon. <consoleapi.h> baþlýk dosasýna ihtiyaç duyar.
void setConsoleTRchar(void){
	/*https://stackoverflow.com/questions/49557472/read-write-special-characters-like-tilde-%C3%B1-in-a-console-application-c
	  adresindeki ispanyolca için yapýlmýþ açýklmalara göre türkçe için uyarlanmýþtýr.
	*/
	unsigned int gPrevConsoleCP = 0, gPrevConsoleOutputCP = 0;  //
	wchar_t *locale_name = L"tr-TR";			//16bit geniþ karakterler için deðiþken tipinde tanýmlanmýþ dizi deðiþken.
												// char tip 8 bit iken wchar_t 16bit tir.

	if (_wsetlocale(LC_ALL, locale_name))		//setlocale(LC_ALL, "Turkish"); komutunun geniþ karkter versiyonu.
	{
		int codepage;
		gPrevConsoleCP = GetConsoleCP();		//Çaðýran iþlemle iliþkili konsol tarafýndan kullanýlan giriþ kodu sayfasýný alýr. 
												//Bir konsol, klavye giriþini ilgili karakter deðerine çevirmek için giriþ kodu sayfasýný kullanýr.
												//https://docs.microsoft.com/en-us/windows/console/getconsolecp

		if (gPrevConsoleCP) {					// The process is attached to a console.

			gPrevConsoleOutputCP = GetConsoleOutputCP();	//Çaðýran iþlemle iliþkili konsol tarafýndan kullanýlan çýktý kodu sayfasýný alýr.
															//Bir konsol, çýkýþ kodu sayfasýný çeþitli çýkýþ iþlevleri tarafýndan yazýlan
															//karakter deðerlerini konsol penceresinde görüntülenen görüntülere çevirmek için kullanýr.
															//https://docs.microsoft.com/en-us/windows/console/getconsoleoutputcp

			if (GetLocaleInfoEx(locale_name,				//Adýyla belirtilen bir yerel ayar hakkýndaki bilgileri alýr.
				LOCALE_IDEFAULTANSICODEPAGE |				//https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getlocaleinfoex
				LOCALE_RETURN_NUMBER,
				(LPWSTR)&codepage,
				sizeof(codepage) / sizeof(wchar_t))
				) {
				if (!codepage) {							// The locale doesn't have an ANSI codepage.
					codepage = GetACP();					//Ýþletim sistemi için geçerli Windows ANSI kod sayfasý tanýmlayýcýsýný alýr.
															//https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getacp
				}
				SetConsoleCP(codepage);						//Çaðrý süreciyle iliþkili konsol tarafýndan kullanýlan giriþ kodu sayfasýný ayarlar.
															//https://docs.microsoft.com/en-us/windows/console/setconsolecp

				SetConsoleOutputCP(codepage);				//Çaðrý süreciyle iliþkili konsol tarafýndan kullanýlan çýktý kodu sayfasýný ayarlar.
															//https://docs.microsoft.com/en-us/windows/console/setconsoleoutputcp

				//atexit(reset_console);					//Programdan çýkýþta paramere olarak verilen fonksiyonu çalýþtýrýr.
			}
		}
	}
}
			/*  Tanýmlanan probleme iliþkin gerçekleþtiirilen çözümler... */
//1: Konsol Türkçe karakter giriþ ve çýkýþý için ayarlanarak gerçekþeltirilen çözüm.
void setTRcharCozum(void){
	const char trk_kar_set_1[12] = "çÇðÐýöÖþÞüÜ\0";		//Türkçe karakterlerin karþýlaþtýrma için tutulduðu
													    // char tipinde sabit dizi.		
	char ifade[100];	// konsoldan okunacak karakterlerin tutulduðu char tipinde 100 elemanlý dizi deðiþken.
						// GÝirilecek karakter sayýsý max 100 ile sýnýrlandýrýlmýþtýr.

	setConsoleTRchar();		//Konsola çýkýþ ve giriþte Türkçe karakter kullanýlmasý iiçn gerekeli
							//ayarlama iþlemlerini gerçekleþtiren fonksiyon.

	printf("Aktif \"locale\" durumu:  %s.\n", setlocale(LC_CTYPE, ""));		//Ýþlemler sonucunda aktif durumdaki local durumunu ekrana yazar.
	printf("\nTürkçe karakter içeren bir ifade giriniz...\n");

	gets(&ifade);				//Konsoldan karkter dizisi (string) okunarak ifade isimli diziye alýnýr.

	printf("\n%s\n", ifade);		//Okunan deðer ekrana yazdýrýlýr.

	printf("Toplam Karakter : %u\n", strlen(ifade));  //Karakter dizisinini uzunluðu(toplam karakter sayýsý) yazdýrýlr.

	//Türkçe karakterlerin arandýðý bölüm
	for (size_t i = 0; i < strlen(ifade); i++)				//girilen her bir karakter, Türkçe karakterlerin bulunduðu dizideki 
	{														//her bir karakter ile karþýlaþtýrýlýr;
		for (size_t j = 0; j < strlen(trk_kar_set_1); j++)
		{
			if (ifade[i] == trk_kar_set_1[j]){					// eðer eþleþen karakter varsa karakterin kendisi ve girilen
				printf("%c -> %u\n", trk_kar_set_1[j], i + 1);	// karakterler arasýnda ilk karakterden itibaren yeri ekrana yazdýrýlýr.
			}
		}
	}
}

//2:Konsol için gerekli ayarlamalar yapýlmadan yapýlan çözüm...
void arrayCozum(void)
{
	const char trk_kar_set_1[12] = "çÇðÐýöÖþÞüÜ\0";	//Türkçe karakterlerin karþýlaþtýrma için tutulduðu
													// char tipinde sabit dizi.	
									// ç	Ç	  ð	   Ð	ý	   ö	Ö	  þ	   Þ	ü	   Ü
	const char trk_kar_set_0[12] = { -121, -128, -89, -90, -115, -108, -103, -97, -98, -127, -102 };// Debug iþlemi kullanýlarak Türkçe karakterlerin 
																									// konsoldan giriþ iþlminden sonra aldýðý sayýsal
																									// karþýlýklarýn tutulduðu dizi sabit. 
																									// Bu sayýsal deðerler sürüme göre deðiþebilir.
	char ifade[100];	// konsoldan okunacak karakterlerin tutulduðu char tipinde 100 elemanlý dizi deðiþken.
						// GÝirilecek karakter sayýsý max 100 ile sýnýrlandýrýlmýþtýr.

	printf("Aktif \"locale\" durumu:  %s.\n", setlocale(LC_CTYPE, ""));		//aktif durumdaki local durumu ekrana yazar.
	printf("\nTürkçe karakter içeren bir ifade giriniz...\n");

	gets(&ifade);	//Konsoldan karkter dizisi (string) okunarak ifade isimli diziye alýnýr.

	printf("\n%s\n", ifade); //Okunan deðer ekrana yazdýrýlýr.

	printf("Toplam Karakter : %u\n", strlen(ifade));		// Karakter dizisinini uzunluðu(toplam karakter sayýsý) yazdýrýlr.

	//Türkçe karakterlerin arandýðý bölüm
	for (size_t i = 0; i < strlen(ifade); i++)					//girilen her bir karakter, Türkçe karakterlerin mevcut locale 
	{														    //durumuna göre oluþturulan sayýsal karþýlýk deðerler ile ayrý ayrý
		for (size_t j = 0 ; j < strlen(trk_kar_set_0) ; j++)	//karþýlaþtýrýlýr;
		{
			if (ifade[i] == trk_kar_set_0[j])
			{													//eðer eþleþme bulunursa karakterin kendisi, Türkçe karakterlerin
				printf("%c -> %u\n", trk_kar_set_1[j], i + 1);	//bulunduðu diziden faydalanarak bulunur ve girilen karakterler arasýnda ilk 
			}													//karakterden itibaren yeri ekrana yazdýrýlýr.
		}
	}
}
			
int main(void){
	
	//system("color f1"); // Arkaplan ve yazý rengi

	//setTRcharCozum();		//	1. ÇÖZÜM
	arrayCozum();			//	2. ÇÖZÜM	

	printf("\nBir tuþa basýn ...\n");
	getch();

	return 0;
}//

//setlocale(LC_ALL, "Turkish");  //Dil seçimi
//printf("The current locale is %s.\n", setlocale(LC_CTYPE, ""));
//setlocale(LC_ALL, "tr_TR.UTF-8");
//setlocale(LC_CTYPE, "en_US.UTF-8");