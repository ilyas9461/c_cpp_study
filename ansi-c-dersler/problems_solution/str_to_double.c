/*
    string to double conversion
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
    double strtod(const char *nptr, char **endptr);

    Strtod i�levi, dizenin ba��ndaki t�m bo�luk karakterlerini atlar, sonraki karakterleri 
    say�n�n par�as� olarak d�n��t�r�r ve sonra say� olmayan ilk karakterle kar��la�t���nda durur.

    nptr    : A pointer to a string to convert to a double.
    endptr  : D�n���m�n nerede durdu�unu belirtmek i�in strtod i�levi taraf�ndan kullan�l�r.
              Strtod i�levi endptr'i de�i�tirir (endptr bir bo� g�sterici de�ilse), b�ylece endptr 
              d�n��t�r�lmemi� ilk karakteri g�sterir.
   https://www.techonthenet.com/c_language/standard_library_functions/stdlib_h/strtod.php#:~:text=In%20the%20C%20Programming%20Language,that%20isn't%20a%20number.
*/

int main()
{
    char str[100];
    double sayi;
    char* endptr; //endptr

    printf("sayi gir:");
    //scanf("%lf", &sayi);
    scanf("%s", str);

    sayi= strtod(str, &endptr);

    /* If the result is 0, test for an error */
    if (sayi == 0)
    {
        /* If the value provided was out of range, display a warning message */
        if (errno == ERANGE)
            printf("The value provided was out of range\n");
    }

    printf("\nSayi :%2.2lf", sayi);
    

    return 0;
}