/* Ýki boyutlu dizilerle not defteri uygulamasý.
   c++ <array> kütüphanesi kullanýlmýþtýr.
*/
#include<iostream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // contains sort and binary_search


using namespace std;

#define DUSUK       0
#define YUKSEK      1
#define ORTALAMA    2

static const size_t students{ 10 }; // number of students
static const size_t tests{ 3 }; // number of tests  

// Yazým : 
//         Tek boyutlu dizi:    arrray< type, lenght> name{initiliazers};
//         Ýki boyutlu dizi:    array<array<type,length-col>, row-length> name{initilaizers};
//    (col,row) sutunlar , satýrlar  isim
 array<array<int, tests>, students> grades{
  87, 96, 70 ,
  68, 87, 90 ,
  94, 100, 90 ,
  100, 81, 82 ,
  83, 65, 85 ,
  78, 87, 65 ,
  85, 75, 83 ,
  91, 94, 100 ,
  76, 72, 84 ,
  87, 93, 73 };
 

float enYuksekNot(array<array<int, tests>, students> notlar, char minMaxOrt, bool cGoster) {
    float notMinMaxOrt{ 0.0 };
    int notSayisi{ 0 };

    if (minMaxOrt==DUSUK) notMinMaxOrt = 100.0; //düþük
    if (minMaxOrt==YUKSEK) notMinMaxOrt = 0.0; //yüksek olan
  
    if (cGoster)
        cout << setw(7)<<"Test1" << setw(7) << "Test2" << setw(7) << "Test3" << endl;
    for (auto const& ogr : notlar) {
        // loop through columns of current row                
        for (auto const& testNot : ogr) {

            if(cGoster) cout << setw(6) << testNot;

            if (minMaxOrt== DUSUK) 
                if (testNot < notMinMaxOrt) notMinMaxOrt = (float)testNot;
            if (minMaxOrt == YUKSEK)
                if (testNot > notMinMaxOrt) notMinMaxOrt =(float) testNot;

            if (minMaxOrt == ORTALAMA) {
                notMinMaxOrt += testNot;
                notSayisi++;
            }
            
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
void konsoldaGoster(array<array<int, tests>, students> notlar) {
    int ogrSayisi{ 0 };
    int testSay{ 0 };
    float testOrt{ 0.0 };

    float ortalama = enYuksekNot(notlar, ORTALAMA, false);
    float maxNot = enYuksekNot(grades, YUKSEK, false);
    float minNot = enYuksekNot(grades, DUSUK, false);

    cout << setw(17) << "Test1" << setw(7) << "Test2" << setw(7) << "Test3" << setw(10)<< "Ortalama"<<endl;

    for (auto const& ogr : notlar) {
        ogrSayisi++;
        cout << setw(6) << "Ogrenci" << setw(3) << ogrSayisi;
        for (auto const& testNot : ogr) {     
           cout<<setw(6)<<testNot;
           testOrt += (float)testNot;
           testSay++;

           if (testSay > 2) {
               testSay = 0;
               testOrt = testOrt / 3;
               cout << setw(13) << setprecision(4)<<testOrt;
               testOrt = 0.0;

           }
        }

        cout << endl; // start new line of output             
    }
    cout << endl;

    cout << "En Yuksek NOT\t\t: " << maxNot << endl;
    cout << "En Dusuk NOt\t\t: " << minNot << endl;
    cout << "Notlarin Ortalamasi\t: " << ortalama << endl;

    cout << endl;
}

void notDagilimi(array<array<int, tests>, students> notlar) {
    //not aralýklarýndaki notlarýn hangi sýklýkta olduðunu tutan array.
    // öðrenci sayýyýsý+1 elemana sahiptir. Her bir not aralýðý
    //ve 100 deðerindeki notlar sayýlarý bir elemanýnda tutulur.
    //   arrray< type, lenght> name{initiliazers};
    array<unsigned int, students + 1> notFrekansi{};               

    cout << "\nNotlarin Dagilimi:" << endl;  
    //Range based for  yapýsý
    for (auto const& student : grades) //satýrlar
    {
        for (auto const& test : student) 
        {
            ++notFrekansi[test / 10];
        }
    }

    // for each grade frequency, print bar in chart
    for (size_t count{ 0 }; count < students; ++count) {
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
    array<int, 30> siralama{};
    int ind{ 0 };
    cout << endl;
    cout << "Siralanmis Notlar :";
    cout << endl;
    // iki boyutlu diziyi tek boyutlu diziye çevir
    for (auto const student : grades) //satýrlar
    {
        for (auto const test : student)
        {
            siralama[ind++] = test;
        }
    }

    sort(siralama.begin(), siralama.end());
    ind = 0;
    cout << endl;
    for (auto const notSira : siralama)
    {
        cout << notSira << ' ';
        ind++;
        if (ind % 3 == 0)cout << endl;
    }
}

int main(void) { 
   konsoldaGoster(grades);
   notDagilimi(grades);
   siralanmisNotlar(); 
   
	return 0; 
}

