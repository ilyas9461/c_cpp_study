
/* 

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>


int main()
{ 
   char* str1 = "hello";   /* str1 unchangeable */
   printf("str1:%s\n", str1);
   
   char* str2 = "goodbye"; /* str2 unchangeable */
   printf("str2:%s\n", str2);
   
   char* str3; /* Not tied to space-uzaya baðlý deðil */
   printf("\nDegiskene atama: \n");
   
   str3 = str1; /* str3 points to same space s1 connected to-str3 ayný boþluðu gösterir s1 baðlý */
   printf("str3:%s\n", str3);
   
   str3 = str2;
   printf("str3:%s\n", str3);
   
   printf("\nYeni icerik atama: \n");
   
   str1 = "Merhaba1";
   printf("str1:%s\n", str1);
   
   str2 = "Merhaba2";
   printf("str2:%s\n", str2);
   
   str3 = "Merhaba3";
   printf("str3:%s\n", str3);
   
   printf("\nYanlis kullanim \n");
   
   char s1[6] = "hello";
   char s2[6];
   printf("s1:%s\n", s1);
   
   int s_uzunluk = strlen(s1);
   for (size_t i = 0; i <= s_uzunluk; i++)
   {
       s2[i] = s1[i]; //i, deðiþkeni jher iki 
                   //dizininde indekslerini deðiþtirir
   }
   printf("s2= %s\n", s2);
   
   printf("\n%s, %p, %c\n", "We", "are", (*"space farers"));
   
   #define MSG "I'm special."
   char ar[] = MSG;
   const char* pt = MSG;
   printf("\naddress of \"I'm special\": %p \n", "I'm special");
   printf(" address ar: %p\n", ar);
   printf(" address pt: %p\n", pt);
   printf(" address of MSG: %p\n", MSG);
   printf("address of \"I'm special\": %p \n", "I'm special");
   
   printf("pt char print: %c \n", *(pt + 5));        //5. indeksteki deðer.


    return 0;
}



