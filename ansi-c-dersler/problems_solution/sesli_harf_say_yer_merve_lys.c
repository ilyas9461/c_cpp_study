
/* Sesli Harfleri Bul
 girilen sesli harflerin(a,e,i,o,u ...) ka� tane ve ifadenin nerelerinde kullan�ld���n�
ayr� ayr� konsolda g�steren bir program� fonksiyonlar� kullanarak yaz�n�z.
En az iki fonksiyon olmal� ;
       1- Sesli harrflerin say�s�n� ve yerini bulan,
       2- Konsolda uygun formatta g�steren

�rnek ��kt� :

konsoldan girilen ifade :   "Selam sana"   ise
Konsoldaki ��kt�;


             Sesli Harf    Miktar�        Yeri
             ------------     ---------         -----
              a                   3                  4, 8, 10
              e                   1                  2
��lem sonucunda kullan�c�dan yeni i�lem yapmak isedi�i sorularak, yeni i�lem iste�i varsa 
ekran temizlenip i�lem tekrar edilmeli aksi durumda programdan ��k�lmal�d�r
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>


char harfler[] = "aeio";    //lys: Aranan sesli harflerin bulundu�u dizi, sabit olarak tan�mlanmas�u daha uygun olur.
char giris[100];            //lys: Konsoldan girilen ifadenin al�nd��� dizi.

int a_yerler[100] = { 0 };  //merve:indexin tutuldu�u dosya,k�me
                            //lys: a harfine ait her bir konum de�erlerinin tutuldu�u(depoland���) dizi.
int a_ind = 0;              //merve:a harfinin konumlar�n� belirleyen de�i�ken
                            //lys: a harfine ait konumlar� tutan diziyi indeksleyen de�i�ken,
                            //ayn� zamanda a harfinin toplam ka� tane konumu oldu�unu da sayar.	
                            //Harfe ait konumlar�n de�erlerine ula�mak i�in for d�ng�s�nde kullan�l�r.
/* Alttaki de�i�kenler a harfi ile ayn�d�r. */
int e_yerler[100] = { 0 };
int e_ind = 0;

int i_yerler[100] = { 0 };
int i_ind = 0;

int o_yerler[100] = { 0 };
int o_ind = 0;

/*  FONK. : int* sesli(char* kelime)

    merve:sesli harflerin say�s�n� ve konumu belirleyen fonksiyon   
    lys: Parametre olarak girilen string i�ersinde sesli harflerin her birinin toplam
    say�s�n� ayr� ayr� hesaplar ve her bir sesli harf i�in tan�mlanan sesli harf dizi
    sindeki indeks s�ras�na g�re dizi olarak d�nd�r. Ayr�ca global olarak tan�mlanan
    her bir sesli harfe ait string i�ersindeki konumlar�n� ve toplam say�lar�n�
    hesaplayarak ilgili global de�i�ken ve dizilere uygun formatta atar.

    Fonk. Parametre :string ifade, bu program i�in 100 karakter, char tipinde dizi.
    Fonk D�n�� De�eri: Harflerin string i�ersindeki toplam say�lar� int tipinde dizi
                      olarak d�nd�r�lm��t�r. 
*/
int* sesli(char* kelime) {                 

    static int depo[4] = { 0 }; //sesli harflerin stringdeki say�lar�n� tutan dizi,k�me.
                                //lys:Sesli harflerin her birinin string ifadedeki toplam say�lar�n� tutan
                                //dizi. 4 tane sesli harf oldu�u i�in 4 elemanl� olarak ve fonksiyonun d�n��
                                //de�eri olaca�� i�in static tan�mlanm��t�r.
                                // static de�i�kenler:
                                // Varsay�lan olarak, de�i�kenler tan�mland�klar� kapsamda yereldir.
                                // Ama static de�i�kenler tan�mland�klar� dosya/sayfa i�ersinde global olurlar. 
                                // Sayfada/dosyada her yerden eri�ileibilirler.

    for (size_t i = 0; i < 4; i++)                    //4 harfi s�ras�yla i�elem yapt�ran for
                                                      //lys:harfler dizisindeki her harfe ulamak i�in kullan�lan for
                                                      // i burada hasrfler dizisini indeksler, i de�i�dik�e harfler 
                                                      // dizisindeki elemanlar ve i�erikleride s�rayla de�i�ir.
    {
        for (size_t x = 0; x < strlen(kelime); x++)   // girilen kelimedeki t�m harfleri ele alan for
                                                      //lys: x de�i�keni kelime dizisini indeksler. 
                                                      //Artmas�yla birlikte s�rayla kelime dizisindeki t�m 
                                                      //harflere teker teke ula��labilir.
        {
            if (harfler[i] == kelime[x])             //lys:harfler dizisini her bir harfi (i de�i�tik�e) s�rayla
                                                     //kelime dizisinin t�m harfleri ile(x artt�k�a) kar��la�t�r�l�r.
                                                     //E�lenen sesli harf bulundu�unda ise;
            {

                depo[i]++;                          //harfleirn her birinden girilen ifadedeki miktar�n� sayar.

                if (harfler[i] == 'a')              //lys: e�er harf a ise;
                    a_yerler[a_ind++] = x + 1;      //merve:bulunan harfin konumunu dosyaya kaydeder
                                                    //lys: E�le�en harfin kelime dizisindeki yerini-konumunu diziye
                                                    //0. elemandan ba�layarak s�rayla kaydeder ve toplam yer say�s�n�
                                                    //hesaplar. a_ind de�i�keni a_yerler dizisine kaydedilecek yer-konum bilgisinin
                                                    //dizideki hangi elemana yerle�tirilece�ini s�rayla sayar(indeksleme i�lemi).

                if (harfler[i] == 'e')
                    e_yerler[e_ind++] = x + 1;

                if (harfler[i] == 'i')
                    i_yerler[i_ind++] = x + 1;

                if (harfler[i] == 'o')
                    o_yerler[o_ind++] = x + 1;


            }
        }
    }

    return depo;    // lys: Fonk. d�n�� dizisi.
}

int main()
{
    int* harf_sayilari;     // lys: Fonksiyondan d�n�� de�erini dizi olarak alabilmek i�in pointer olarak 
                            // tan�mlanan int tipindeki de�i�ken.
yeni:     //lys: Etiket (label) tan�mlanms�. goto komutu i�in.
    system("CLS");                                          //ekran� temizler

    printf("kelimeler girin: ");
    //scanf("%s", giris);                //bo�luktan �ncesini almaz, sadece ilk kelimeyi ele al�r
    gets(giris);                         //bo�luktan sonras�n� da al�r. lys: Konsoldan girilen b�t�n string ifadeyi al�r ve char tipinde diziye atar.

    harf_sayilari = sesli(giris);       //lys: Fonk. d�n�� de�eri olan int tipindeki dizi, pointer oarlak tan�mlanan int tipindeki de�i�kene atan�r.

    /* lys: Formatl� olarak konsola sonu�lar�n yuazd�r�lmas� i��llemleri*/

    printf("HARF\t SAYISI\t YERLER\n");
    printf("------------------------\n");

    for (size_t i = 0; i < 4; i++)      // lys� Belirlenen d�rt adet sesli harf i�in;
    {
        printf("\n%c\t %u\t", harfler[i], harf_sayilari[i]);    // lys: Sesli harfi ve toplam say�s�n� yaz.

        switch (harfler[i])                     // lys: Her bir harf i�in,
        {
        case 'a':
            for (size_t i = 0; i < a_ind; i++)  //lys:yer-konumlar� yaz
            {
                printf("%u, ", a_yerler[i]);
            }
            putchar('\n');      // lys:bu harfle ilgili i�lem bitti�i i�in yeni sat�ra ge�.
            break;
        case 'e':
            for (size_t i = 0; i < e_ind; i++)
            {
                printf("%u, ", e_yerler[i]);
            }
            putchar('\n');
            break;

        /* devam� ekisk ....*/

        default:
            break;
        }

    }

    putchar('\n');     // lys: yeni sat�ra ge�..                                    

    printf("yeni islem ?(e/h)");
    char c = _getch();          //lys: klavyeden sadece bir karkter okur. En b�y�k �zelli�i karaktere bas�l�r bas�lmaz okumas�d�r.
    if (c == 'e') goto yeni;    // 'e' karakterine bas�ld� ise yeni etiketine git.

    return 0;
}