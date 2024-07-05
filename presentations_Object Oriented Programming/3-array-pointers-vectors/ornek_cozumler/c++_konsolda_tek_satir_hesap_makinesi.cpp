//Ama�: konsoldan 215+456 �eklinde iki say�l� olerak girilen matematiksel i�lemin
//      sonucunun ekranda g�sterilmesi 
//Not : ��z�m olu�turulurken new ve delete komutlar� dinamik dizi olmas� i�in kullan�lm��t�r. 

#include<iostream>
#include <iomanip>
using namespace std;

#define or ||

/* 
	dizinin b�t�n elemanlar�n�n s�f�rlanmas�n� sa�lar.
*/
void resetArr(char* arr, int uz) {
	for (int i = 0; i < uz; i++) arr[i] = '\0';
}
/*
	dizinin uzunlu�unu bulur. Son eleman� '\0' null karakterdir.
*/
int uzunlukBul(char* ifade) {
	int n{ 0 };
	while (*ifade++ != '\0')
		n++;
	return n;
}

/* Konsoldan girilen iki say�l� matematiksel ifadedeki i�lem
  operat�r�n� ve ifadedeki yerini bularak dizi �eklinde geri d�nd�r�r.
*/
int* islemBul(char* ifade) {
	int* islem = new int[2];
	int n{ 0 }; //i�lemin dizi indexi

	while (*ifade != '\0') {
		//cout << *ifade; 
		if (*ifade == '+' || *ifade == '-' || *ifade == '*') {
			islem[0] = n;		//islem dizi indexi ilk elemanda 
			islem[1] = *ifade;  // islem ikinci elemanda saklan�r
		}
		ifade++;
		n++;
	}
	//cout << endl;
	return islem;  // islem dizi indeksini ve islemi geri d�nd�r�r.
}
/*
	Konsoldan girilen iki say�l� matematiksel ifadedeki say�lar� bularak
	dizi �eklinde sa�ylar� geri d�nd�r�r. sayiUzunluk parametresi
	say�lar�n max rakam say�s�d�r(dijit).
*/
int* sayilariBul(char* ifade, unsigned int sayiUzunluk) {

	char* sayi = new char[sayiUzunluk];
	int* sayilar = new int[2];
	resetArr(sayi, sayiUzunluk);

	int ifadeUzunluk = uzunlukBul(ifade);
	int ifadeIslemIndex = islemBul(ifade)[0];

	//1. say�n�n bulunmas�
	for (int i = 0; i < ifadeIslemIndex; i++)
		sayi[i] = ifade[i];
	sayilar[0] = atoi(sayi);

	//ikinci say�n�n bulunmas�
	resetArr(sayi, sayiUzunluk);
	for (int i = ifadeIslemIndex + 1; i < ifadeUzunluk; i++)
		sayi[i - (ifadeIslemIndex + 1)] = ifade[i];
	sayilar[1] = atoi(sayi);

	return sayilar; //say�lar� d�nd�r�r.
}

/*
	konsoldan girilen matematiksel ifadedeki i�lemi yaparak sonucu
	geri d�nd�r�r.
*/
int islemYap(char* ifade) {

	char islem = (char)islemBul(ifade)[1];
	int sayi1 = sayilariBul(ifade, 10)[0];
	int sayi2 = sayilariBul(ifade, 10)[1];

	switch (islem)
	{
	case '+':
		return sayi1 + sayi2;
		break;
	case '-':
		return sayi1 - sayi2;
		break;
	case '*':
		return sayi1 * sayi2;
		break;
	default:
		break;
	}

}


int main(void) {

	char* islemIfade = new char[50];
	char yesNo = 0;

	resetArr(islemIfade, 25);

	do {
		cout << "islem gir ?"; cout << endl;
		cin >> islemIfade;

		cout << "Sonuc = " << islemYap(islemIfade);
		cout << endl;

		cout << endl;
		cout << "Yeni islem (E/H) ?";
		cin >> yesNo;
		cout << endl;

		if ((yesNo == 'h') or (yesNo == 'H'))break;

	} while (1);


	delete[] islemIfade;

	return 0;
}

//int ifadeUzunluk = uzunlukBul(islemIfade);
//int ifadeIslemIndex = islemBul(islemIfade)[0];
//char ifadeIslem = (char)islemBul(islemIfade)[1];

//int sayi1 = sayilariBul(islemIfade)[0];
//int sayi2 = sayilariBul(islemIfade)[1];

//cout << endl;
//cout << ifadeUzunluk; cout << endl;
//cout << ifadeIslemIndex; cout << endl;
//cout << ifadeIslem; cout << endl;