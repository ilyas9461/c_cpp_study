/* Ýki boyutlu dizilerle not defteri uygulamasý.
   c++ <array> kütüphanesi kullanýlmýþtýr.
*/
#include<iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // contains sort and binary_search
#include <vector>   
#include <stdexcept>


using namespace std;

#define DUSUK       0
#define YUKSEK      1
#define ORTALAMA    2

static const size_t students{ 10 }; // number of students
vector<int> grades{ 87, 96, 70, 68, 87, 90, 94, 100, 90, 100 };
// iki boyutlu vector tanýmý : vector< vector<int> > grades;


float enYuksekNot(vector<int> notlar, char minMaxOrt, bool cGoster) {

	float notMinMaxOrt{ 0.0 };
	int notSayisi{ 0 };

	if (minMaxOrt == DUSUK) notMinMaxOrt = 100.0; //düþük
	if (minMaxOrt == YUKSEK) notMinMaxOrt = 0.0; //yüksek olan

	if (cGoster)
		cout << setw(7) << "Notlar" << endl;
	for (auto ogrNot : notlar) {

		if (cGoster) cout << setw(6) << ogrNot;

		if (minMaxOrt == DUSUK)
			if (ogrNot < notMinMaxOrt) notMinMaxOrt = (float)ogrNot;
		if (minMaxOrt == YUKSEK)
			if (ogrNot > notMinMaxOrt) notMinMaxOrt = (float)ogrNot;

		if (minMaxOrt == ORTALAMA) {
			notMinMaxOrt += ogrNot;
			notSayisi++;
		}

		if (cGoster) cout << endl; // start new line of output             
	}
	if (cGoster) {
		cout << endl;
		if (minMaxOrt == DUSUK)
			cout << "En Dusuk Not :" << notMinMaxOrt;
		if (minMaxOrt == YUKSEK)
			cout << "En Yuksek Not :" << notMinMaxOrt;
		if (minMaxOrt == ORTALAMA) {
			notMinMaxOrt /= notSayisi;
			cout << "Ortalama Not :" << notMinMaxOrt;
		}

		cout << endl;
	}
	else {
		if (minMaxOrt == ORTALAMA) {
			notMinMaxOrt /= notSayisi;
		}
	}

	return notMinMaxOrt;
}
void konsoldaGoster(vector<int> notlar) {

    int ogrSayisi{ 0 };
    int testSay{ 0 };
    float testOrt{ 0.0 };

    float ortalama = enYuksekNot(notlar, ORTALAMA, false);
    float maxNot = enYuksekNot(grades, YUKSEK, false);
    float minNot = enYuksekNot(grades, DUSUK, false);

	cout << "Notlar   :" << endl;

    for (auto ogrNot : notlar) {
        ogrSayisi++;
        cout << setw(10) << "Ogrenci" << setw(3) << ogrSayisi<< setw(3)<<":"<<ogrNot;
		cout << endl;
    }
	cout << endl;

    cout << "En Yuksek NOT\t\t: " << maxNot << endl;
    cout << "En Dusuk NOt\t\t: " << minNot << endl;
    cout << "Notlarin Ortalamasi\t: " << ortalama << endl;

    cout << endl;
}

void notDagilimi(vector<int> notlar) {
    //not aralýklarýndaki notlarýn hangi sýklýkta olduðunu tutan array.
    // öðrenci sayýyýsý+1 elemana sahiptir. Her bir not aralýðý
    //ve 100 deðerindeki notlar sayýlarý bir elemanýnda tutulur.
    //   arrray< type, lenght> name{initiliazers};
    array<unsigned int, students + 1> notFrekansi{};               

    cout << "\nNotlarin Dagilimi:" << endl;  
    //Range based for  yapýsý
    for (auto const& ogrNot : notlar) //satýrlar
    {
		++notFrekansi[ogrNot / 10];
    }

    // for each grade frequency, print bar in chart
    for (size_t count{ 0 }; count < students+1; ++count) {
        // output bar label ("0-9:", ..., "90-99:", "100:")
        if (0 == count) {
            cout << "  0-9: ";
        }
        else if (10 == count) {
            cout << "  100: ";
        }
        else {
            cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        // print bar of asterisks
        for (unsigned int stars{ 0 }; stars < notFrekansi[count]; ++stars)
            cout << '*';

        cout << endl; // start a new line of output
    }
}

void siralanmisNotlar() {
    int ind{ 0 };
    cout << endl;
    cout << "Siralanmis Notlar :";
    cout << endl;

    sort(grades.begin(), grades.end());
    ind = 0;
    cout << endl;
    for (auto const notSira : grades)
    {
        cout << notSira << ' ';
        ind++;
        if (ind % 5 == 0)cout << endl;
    }

    cout << endl;
}

int main(void) {
    grades.push_back(45);
    grades.push_back(55);

	konsoldaGoster(grades);
	notDagilimi(grades);
	siralanmisNotlar(); 

	return 0;
}

