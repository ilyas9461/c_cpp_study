
/* Sesli Harfleri Bul
 girilen sesli harflerin(a,e,i,o,u ...) kaç tane ve ifadenin nerelerinde kullanýldýðýný
ayrý ayrý konsolda gösteren bir programý fonksiyonlarý kullanarak yazýnýz.
En az iki fonksiyon olmalý ;
       1- Sesli harrflerin sayýsýný ve yerini bulan,
       2- Konsolda uygun formatta gösteren

Örnek çýktý :

konsoldan girilen ifade :   "Selam sana"   ise
Konsoldaki çýktý;


             Sesli Harf    Miktarý        Yeri
             ------------     ---------         -----
              a                   3                  4, 8, 10
              e                   1                  2
Ýþlem sonucunda kullanýcýdan yeni iþlem yapmak isediði sorularak, yeni iþlem isteði varsa 
ekran temizlenip iþlem tekrar edilmeli aksi durumda programdan çýkýlmalýdýr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>


char harfler[] = "aeio";    //lys: Aranan sesli harflerin bulunduðu dizi, sabit olarak tanýmlanmasýu daha uygun olur.
char giris[100];            //lys: Konsoldan girilen ifadenin alýndýðý dizi.

int a_yerler[100] = { 0 };  //merve:indexin tutulduðu dosya,küme
                            //lys: a harfine ait her bir konum deðerlerinin tutulduðu(depolandýðý) dizi.
int a_ind = 0;              //merve:a harfinin konumlarýný belirleyen deðiþken
                            //lys: a harfine ait konumlarý tutan diziyi indeksleyen deðiþken,
                            //ayný zamanda a harfinin toplam kaç tane konumu olduðunu da sayar.	
                            //Harfe ait konumlarýn deðerlerine ulaþmak için for döngüsünde kullanýlýr.
/* Alttaki deðiþkenler a harfi ile aynýdýr. */
int e_yerler[100] = { 0 };
int e_ind = 0;

int i_yerler[100] = { 0 };
int i_ind = 0;

int o_yerler[100] = { 0 };
int o_ind = 0;

/*  FONK. : int* sesli(char* kelime)

    merve:sesli harflerin sayýsýný ve konumu belirleyen fonksiyon   
    lys: Parametre olarak girilen string içersinde sesli harflerin her birinin toplam
    sayýsýný ayrý ayrý hesaplar ve her bir sesli harf için tanýmlanan sesli harf dizi
    sindeki indeks sýrasýna göre dizi olarak döndür. Ayrýca global olarak tanýmlanan
    her bir sesli harfe ait string içersindeki konumlarýný ve toplam sayýlarýný
    hesaplayarak ilgili global deðiþken ve dizilere uygun formatta atar.

    Fonk. Parametre :string ifade, bu program için 100 karakter, char tipinde dizi.
    Fonk Dönüþ Deðeri: Harflerin string içersindeki toplam sayýlarý int tipinde dizi
                      olarak döndürülmüþtür. 
*/
int* sesli(char* kelime) {                 

    static int depo[4] = { 0 }; //sesli harflerin stringdeki sayýlarýný tutan dizi,küme.
                                //lys:Sesli harflerin her birinin string ifadedeki toplam sayýlarýný tutan
                                //dizi. 4 tane sesli harf olduðu için 4 elemanlý olarak ve fonksiyonun dönüþ
                                //deðeri olacaðý için static tanýmlanmýþtýr.
                                // static deðiþkenler:
                                // Varsayýlan olarak, deðiþkenler tanýmlandýklarý kapsamda yereldir.
                                // Ama static deðiþkenler tanýmlandýklarý dosya/sayfa içersinde global olurlar. 
                                // Sayfada/dosyada her yerden eriþileibilirler.

    for (size_t i = 0; i < 4; i++)                    //4 harfi sýrasýyla iþelem yaptýran for
                                                      //lys:harfler dizisindeki her harfe ulamak için kullanýlan for
                                                      // i burada hasrfler dizisini indeksler, i deðiþdikçe harfler 
                                                      // dizisindeki elemanlar ve içerikleride sýrayla deðiþir.
    {
        for (size_t x = 0; x < strlen(kelime); x++)   // girilen kelimedeki tüm harfleri ele alan for
                                                      //lys: x deðiþkeni kelime dizisini indeksler. 
                                                      //Artmasýyla birlikte sýrayla kelime dizisindeki tüm 
                                                      //harflere teker teke ulaþýlabilir.
        {
            if (harfler[i] == kelime[x])             //lys:harfler dizisini her bir harfi (i deðiþtikçe) sýrayla
                                                     //kelime dizisinin tüm harfleri ile(x arttýkça) karþýlaþtýrýlýr.
                                                     //Eþlenen sesli harf bulunduðunda ise;
            {

                depo[i]++;                          //harfleirn her birinden girilen ifadedeki miktarýný sayar.

                if (harfler[i] == 'a')              //lys: eðer harf a ise;
                    a_yerler[a_ind++] = x + 1;      //merve:bulunan harfin konumunu dosyaya kaydeder
                                                    //lys: Eþleþen harfin kelime dizisindeki yerini-konumunu diziye
                                                    //0. elemandan baþlayarak sýrayla kaydeder ve toplam yer sayýsýný
                                                    //hesaplar. a_ind deðiþkeni a_yerler dizisine kaydedilecek yer-konum bilgisinin
                                                    //dizideki hangi elemana yerleþtirileceðini sýrayla sayar(indeksleme iþlemi).

                if (harfler[i] == 'e')
                    e_yerler[e_ind++] = x + 1;

                if (harfler[i] == 'i')
                    i_yerler[i_ind++] = x + 1;

                if (harfler[i] == 'o')
                    o_yerler[o_ind++] = x + 1;


            }
        }
    }

    return depo;    // lys: Fonk. dönüþ dizisi.
}

int main()
{
    int* harf_sayilari;     // lys: Fonksiyondan dönüþ deðerini dizi olarak alabilmek için pointer olarak 
                            // tanýmlanan int tipindeki deðiþken.
yeni:     //lys: Etiket (label) tanýmlanmsý. goto komutu için.
    system("CLS");                                          //ekraný temizler

    printf("kelimeler girin: ");
    //scanf("%s", giris);                //boþluktan öncesini almaz, sadece ilk kelimeyi ele alýr
    gets(giris);                         //boþluktan sonrasýný da alýr. lys: Konsoldan girilen bütün string ifadeyi alýr ve char tipinde diziye atar.

    harf_sayilari = sesli(giris);       //lys: Fonk. dönüþ deðeri olan int tipindeki dizi, pointer oarlak tanýmlanan int tipindeki deðiþkene atanýr.

    /* lys: Formatlý olarak konsola sonuçlarýn yuazdýrýlmasý iþþllemleri*/

    printf("HARF\t SAYISI\t YERLER\n");
    printf("------------------------\n");

    for (size_t i = 0; i < 4; i++)      // lysÇ Belirlenen dört adet sesli harf için;
    {
        printf("\n%c\t %u\t", harfler[i], harf_sayilari[i]);    // lys: Sesli harfi ve toplam sayýsýný yaz.

        switch (harfler[i])                     // lys: Her bir harf için,
        {
        case 'a':
            for (size_t i = 0; i < a_ind; i++)  //lys:yer-konumlarý yaz
            {
                printf("%u, ", a_yerler[i]);
            }
            putchar('\n');      // lys:bu harfle ilgili iþlem bittiði için yeni satýra geç.
            break;
        case 'e':
            for (size_t i = 0; i < e_ind; i++)
            {
                printf("%u, ", e_yerler[i]);
            }
            putchar('\n');
            break;

        /* devamý ekisk ....*/

        default:
            break;
        }

    }

    putchar('\n');     // lys: yeni satýra geç..                                    

    printf("yeni islem ?(e/h)");
    char c = _getch();          //lys: klavyeden sadece bir karkter okur. En büyük özelliði karaktere basýlýr basýlmaz okumasýdýr.
    if (c == 'e') goto yeni;    // 'e' karakterine basýldý ise yeni etiketine git.

    return 0;
}