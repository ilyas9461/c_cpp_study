/* String parçalamak...bölmek...string split iþlemi */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

char* bolStr(char* input_string, char* separator, int segment_number) //segment 1'den baþlar 
{
    #define MAX_STRING_LEN 32   //bölünecek string max karakter sayýsý
    //String ifadenin sonu her zaman '\0' karakteri olmalýdýr. 

    char *act;      //
    char *sub="";
    static char copy[MAX_STRING_LEN];
    int i;

    strcpy(copy, input_string);

    for (i = 1, act = copy; i <= segment_number; i++, act = NULL) {

        sub = strtok(act, separator);
        if (sub == NULL)
            break;
    }
    return sub;
}

int karSay(char *str, char kar) {
    int uz = strlen(str);
    int say = 0;
    for (size_t i = 0; i < uz; i++)
    {
        if (str[i] == kar)
            say++;
    }

    return say;
}

int main()
{
    setlocale(LC_ALL, "Turkish");  //Dil seçimi

    char cdizi[] = "10,15,45,56,89,12,23,78,45,10";
    printf("Karakter dizisi: %s\n", cdizi);
    char *alt_str;
    int uzunluk = karSay(cdizi, ',');

    for (size_t i = 1; i <uzunluk+2; i++)
    {
        alt_str = bolStr(cdizi, ",", i);
        printf("%u. parca: %s\n", i,alt_str);
    }

    return 0;

}

