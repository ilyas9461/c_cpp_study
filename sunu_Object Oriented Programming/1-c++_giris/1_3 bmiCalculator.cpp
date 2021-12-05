//BMI Calculator
#include <iostream>
//#include <cstdlib>
//#include <ctime>
using namespace std;

//BMI sýnýr deðerleri
#define ZAYIF       18.50
#define SAGLIKLI    24.99
#define ASIRI       29.99
#define OBEZ        30

float boy = 0.0;
float kilo = 0.0;
char cevap = 0;

int main()
{

    do {
        system("cls");
        cout << "\t\t *** BMI Hesaplama ***" << endl << endl;
        cout << "\tLutfen kilo ve boyunuzla ilgili degerleri giriniz :" << endl;

        cout << "\tKilo (kg) ?: ";
        cin >> kilo;
        cout << "\tBoy(m) ?: ";
        cin >> boy;
        cout << endl;

        float bmi = kilo / (boy * boy);

        cout << "\t\tKilonuz = " << kilo << "\tBoyunuz = " << boy << endl;
        cout << "\t\tBMI = " << bmi << endl<<endl<<"\tBuna gore :" << endl;

        if (bmi < ZAYIF) cout << "\tZayifsiniz biraz kilo almalisiniz..." << endl;
        if (bmi > ZAYIF && bmi < SAGLIKLI) cout << "\tSagliklisiniz, kilonuzu koruyunuz..." << endl;
        if (bmi > SAGLIKLI && bmi < ASIRI) cout << "\tAsiri kilolusunuz, kilo vermeniz gerekir." << endl;
        if (bmi >= OBEZ) cout << "\tObez , kesinlikle kilo vermelisiniz..." << endl;

        cout << endl;

        cout << "\tYeni giris (e/h) ?";
        cin >> cevap;

    }while (cevap == 'e' || cevap == 'E');
    
   return 0; // indicate successful termination

} // end 






