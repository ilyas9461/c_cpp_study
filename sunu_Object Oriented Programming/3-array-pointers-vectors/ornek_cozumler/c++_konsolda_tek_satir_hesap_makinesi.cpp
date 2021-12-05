//Amaç: konsoldan 215+456 þeklinde iki sayýlý olerak girilen matematiksel iþlemin
//      sonucunun ekranda gösterilmesi 
//Not : Çözüm oluþturulurken new ve delete komutlarý dinamik dizi olmasý için kullanýlmýþtýr. 

#include<iostream>
#include <iomanip>
using namespace std;

#define or ||

/* 
	dizinin bütün elemanlarýnýn sýfýrlanmasýný saðlar.
*/
void resetArr(char* arr, int uz) {
	for (int i = 0; i < uz; i++) arr[i] = '\0';
}
/*
	dizinin uzunluðunu bulur. Son elemaný '\0' null karakterdir.
*/
int uzunlukBul(char* ifade) {
	int n{ 0 };
	while (*ifade++ != '\0')
		n++;
	return n;
}

/* Konsoldan girilen iki sayýlý matematiksel ifadedeki iþlem
  operatörünü ve ifadedeki yerini bularak dizi þeklinde geri döndürür.
*/
int* islemBul(char* ifade) {
	int* islem = new int[2];
	int n{ 0 }; //iþlemin dizi indexi

	while (*ifade != '\0') {
		//cout << *ifade; 
		if (*ifade == '+' || *ifade == '-' || *ifade == '*') {
			islem[0] = n;		//islem dizi indexi ilk elemanda 
			islem[1] = *ifade;  // islem ikinci elemanda saklanýr
		}
		ifade++;
		n++;
	}
	//cout << endl;
	return islem;  // islem dizi indeksini ve islemi geri döndürür.
}
/*
	Konsoldan girilen iki sayýlý matematiksel ifadedeki sayýlarý bularak
	dizi þeklinde saýylarý geri döndürür. sayiUzunluk parametresi
	sayýlarýn max rakam sayýsýdýr(dijit).
*/
int* sayilariBul(char* ifade, unsigned int sayiUzunluk) {

	char* sayi = new char[sayiUzunluk];
	int* sayilar = new int[2];
	resetArr(sayi, sayiUzunluk);

	int ifadeUzunluk = uzunlukBul(ifade);
	int ifadeIslemIndex = islemBul(ifade)[0];

	//1. sayýnýn bulunmasý
	for (int i = 0; i < ifadeIslemIndex; i++)
		sayi[i] = ifade[i];
	sayilar[0] = atoi(sayi);

	//ikinci sayýnýn bulunmasý
	resetArr(sayi, sayiUzunluk);
	for (int i = ifadeIslemIndex + 1; i < ifadeUzunluk; i++)
		sayi[i - (ifadeIslemIndex + 1)] = ifade[i];
	sayilar[1] = atoi(sayi);

	return sayilar; //sayýlarý döndürür.
}

/*
	konsoldan girilen matematiksel ifadedeki iþlemi yaparak sonucu
	geri döndürür.
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