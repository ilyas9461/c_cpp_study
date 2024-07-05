/* Konsoldan klavye ile girilen bir karakter dizisindeki(string) t�rk�e karakerlerin yerlerini
  bulan program... Konsoldan giri�-��k�� i�lemlerinde T�rk�e karakter kullan�lmas�n� sa�lar.
*/

#include <stdio.h>          // Preprocessor directive
#include <string.h>			//Karakterlerle ilgili i�lemleri yapabilmek i�in.
#include <locale.h>			// Dile g�re karakter seti se�mak i�in.
#include <windows.h>		// Arkaplan ve yaz� rengi
#include <conio.h>			//console input/output. https://anilozbek.blogspot.com/2017/10/conioh.html
#include <wchar.h>			//geni� karakter kullan�m� i�in geerekli tip ve fonksiyonlar i�in.
#include <consoleapi.h>		//console i�in karakter ayarlama ile ilgili komutlar .

//Konsola yazma(��k��) ve okuma(giri�) i�lemlerinde t�rk�e karakterlerin kullan�lmas�n�
//sa�layan fonksiyon. <consoleapi.h> ba�l�k dosas�na ihtiya� duyar.
void setConsoleTRchar(void){
	/*https://stackoverflow.com/questions/49557472/read-write-special-characters-like-tilde-%C3%B1-in-a-console-application-c
	  adresindeki ispanyolca i�in yap�lm�� a��klmalara g�re t�rk�e i�in uyarlanm��t�r.
	*/
	unsigned int gPrevConsoleCP = 0, gPrevConsoleOutputCP = 0;  //
	wchar_t *locale_name = L"tr-TR";			//16bit geni� karakterler i�in de�i�ken tipinde tan�mlanm�� dizi de�i�ken.
												// char tip 8 bit iken wchar_t 16bit tir.

	if (_wsetlocale(LC_ALL, locale_name))		//setlocale(LC_ALL, "Turkish"); komutunun geni� karkter versiyonu.
	{
		int codepage;
		gPrevConsoleCP = GetConsoleCP();		//�a��ran i�lemle ili�kili konsol taraf�ndan kullan�lan giri� kodu sayfas�n� al�r. 
												//Bir konsol, klavye giri�ini ilgili karakter de�erine �evirmek i�in giri� kodu sayfas�n� kullan�r.
												//https://docs.microsoft.com/en-us/windows/console/getconsolecp

		if (gPrevConsoleCP) {					// The process is attached to a console.

			gPrevConsoleOutputCP = GetConsoleOutputCP();	//�a��ran i�lemle ili�kili konsol taraf�ndan kullan�lan ��kt� kodu sayfas�n� al�r.
															//Bir konsol, ��k�� kodu sayfas�n� �e�itli ��k�� i�levleri taraf�ndan yaz�lan
															//karakter de�erlerini konsol penceresinde g�r�nt�lenen g�r�nt�lere �evirmek i�in kullan�r.
															//https://docs.microsoft.com/en-us/windows/console/getconsoleoutputcp

			if (GetLocaleInfoEx(locale_name,				//Ad�yla belirtilen bir yerel ayar hakk�ndaki bilgileri al�r.
				LOCALE_IDEFAULTANSICODEPAGE |				//https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getlocaleinfoex
				LOCALE_RETURN_NUMBER,
				(LPWSTR)&codepage,
				sizeof(codepage) / sizeof(wchar_t))
				) {
				if (!codepage) {							// The locale doesn't have an ANSI codepage.
					codepage = GetACP();					//��letim sistemi i�in ge�erli Windows ANSI kod sayfas� tan�mlay�c�s�n� al�r.
															//https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getacp
				}
				SetConsoleCP(codepage);						//�a�r� s�reciyle ili�kili konsol taraf�ndan kullan�lan giri� kodu sayfas�n� ayarlar.
															//https://docs.microsoft.com/en-us/windows/console/setconsolecp

				SetConsoleOutputCP(codepage);				//�a�r� s�reciyle ili�kili konsol taraf�ndan kullan�lan ��kt� kodu sayfas�n� ayarlar.
															//https://docs.microsoft.com/en-us/windows/console/setconsoleoutputcp

				//atexit(reset_console);					//Programdan ��k��ta paramere olarak verilen fonksiyonu �al��t�r�r.
			}
		}
	}
}
			/*  Tan�mlanan probleme ili�kin ger�ekle�tiirilen ��z�mler... */
//1: Konsol T�rk�e karakter giri� ve ��k��� i�in ayarlanarak ger�ek�eltirilen ��z�m.
void setTRcharCozum(void){
	const char trk_kar_set_1[12] = "�����������\0";		//T�rk�e karakterlerin kar��la�t�rma i�in tutuldu�u
													    // char tipinde sabit dizi.		
	char ifade[100];	// konsoldan okunacak karakterlerin tutuldu�u char tipinde 100 elemanl� dizi de�i�ken.
						// G�irilecek karakter say�s� max 100 ile s�n�rland�r�lm��t�r.

	setConsoleTRchar();		//Konsola ��k�� ve giri�te T�rk�e karakter kullan�lmas� ii�n gerekeli
							//ayarlama i�lemlerini ger�ekle�tiren fonksiyon.

	printf("Aktif \"locale\" durumu:  %s.\n", setlocale(LC_CTYPE, ""));		//��lemler sonucunda aktif durumdaki local durumunu ekrana yazar.
	printf("\nT�rk�e karakter i�eren bir ifade giriniz...\n");

	gets(&ifade);				//Konsoldan karkter dizisi (string) okunarak ifade isimli diziye al�n�r.

	printf("\n%s\n", ifade);		//Okunan de�er ekrana yazd�r�l�r.

	printf("Toplam Karakter : %u\n", strlen(ifade));  //Karakter dizisinini uzunlu�u(toplam karakter say�s�) yazd�r�lr.

	//T�rk�e karakterlerin arand��� b�l�m
	for (size_t i = 0; i < strlen(ifade); i++)				//girilen her bir karakter, T�rk�e karakterlerin bulundu�u dizideki 
	{														//her bir karakter ile kar��la�t�r�l�r;
		for (size_t j = 0; j < strlen(trk_kar_set_1); j++)
		{
			if (ifade[i] == trk_kar_set_1[j]){					// e�er e�le�en karakter varsa karakterin kendisi ve girilen
				printf("%c -> %u\n", trk_kar_set_1[j], i + 1);	// karakterler aras�nda ilk karakterden itibaren yeri ekrana yazd�r�l�r.
			}
		}
	}
}

//2:Konsol i�in gerekli ayarlamalar yap�lmadan yap�lan ��z�m...
void arrayCozum(void)
{
	const char trk_kar_set_1[12] = "�����������\0";	//T�rk�e karakterlerin kar��la�t�rma i�in tutuldu�u
													// char tipinde sabit dizi.	
									// �	�	  �	   �	�	   �	�	  �	   �	�	   �
	const char trk_kar_set_0[12] = { -121, -128, -89, -90, -115, -108, -103, -97, -98, -127, -102 };// Debug i�lemi kullan�larak T�rk�e karakterlerin 
																									// konsoldan giri� i�lminden sonra ald��� say�sal
																									// kar��l�klar�n tutuldu�u dizi sabit. 
																									// Bu say�sal de�erler s�r�me g�re de�i�ebilir.
	char ifade[100];	// konsoldan okunacak karakterlerin tutuldu�u char tipinde 100 elemanl� dizi de�i�ken.
						// G�irilecek karakter say�s� max 100 ile s�n�rland�r�lm��t�r.

	printf("Aktif \"locale\" durumu:  %s.\n", setlocale(LC_CTYPE, ""));		//aktif durumdaki local durumu ekrana yazar.
	printf("\nT�rk�e karakter i�eren bir ifade giriniz...\n");

	gets(&ifade);	//Konsoldan karkter dizisi (string) okunarak ifade isimli diziye al�n�r.

	printf("\n%s\n", ifade); //Okunan de�er ekrana yazd�r�l�r.

	printf("Toplam Karakter : %u\n", strlen(ifade));		// Karakter dizisinini uzunlu�u(toplam karakter say�s�) yazd�r�lr.

	//T�rk�e karakterlerin arand��� b�l�m
	for (size_t i = 0; i < strlen(ifade); i++)					//girilen her bir karakter, T�rk�e karakterlerin mevcut locale 
	{														    //durumuna g�re olu�turulan say�sal kar��l�k de�erler ile ayr� ayr�
		for (size_t j = 0 ; j < strlen(trk_kar_set_0) ; j++)	//kar��la�t�r�l�r;
		{
			if (ifade[i] == trk_kar_set_0[j])
			{													//e�er e�le�me bulunursa karakterin kendisi, T�rk�e karakterlerin
				printf("%c -> %u\n", trk_kar_set_1[j], i + 1);	//bulundu�u diziden faydalanarak bulunur ve girilen karakterler aras�nda ilk 
			}													//karakterden itibaren yeri ekrana yazd�r�l�r.
		}
	}
}
			
int main(void){
	
	//system("color f1"); // Arkaplan ve yaz� rengi

	//setTRcharCozum();		//	1. ��Z�M
	arrayCozum();			//	2. ��Z�M	

	printf("\nBir tu�a bas�n ...\n");
	getch();

	return 0;
}//

//setlocale(LC_ALL, "Turkish");  //Dil se�imi
//printf("The current locale is %s.\n", setlocale(LC_CTYPE, ""));
//setlocale(LC_ALL, "tr_TR.UTF-8");
//setlocale(LC_CTYPE, "en_US.UTF-8");