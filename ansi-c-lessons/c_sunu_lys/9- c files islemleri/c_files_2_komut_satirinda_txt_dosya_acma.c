/* C FILES :
	Komut satırında derlenmiş C kodunun çalıştırılması;
	Komut satırına gitmek için;
		* win+x tuş kombinasyonu
		* çalıştır, gelen pencereye cmd yaz ve onayla.
	veya
		aramaya cmd yaz, sonucu çalıştır.

	Komut satırında C derlenmiş (.exe) program dosyasının
	bulunduğu konuma gitmek için ;
		* Komut satırında iken cd <program tam yolu> 
		  (explorer den tam yol kopyalanıp cd den sonra yapıştırılabilir)
    Aşağıdaki programı derledikten sonra komut satırında;
	    <programIsmi.exe> <dosya ismi ve uzantısı) enter ile onaylanır.
		orn.:
		     Project1.exe courses.txt

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

int main(int argc, char *argv[])
{
	int ch; // place to store each character as read
	FILE *fp; // "file pointer"
	unsigned long count = 0;

	if (argc != 2)		//arguman sayısı 2 ye eşit değilse. argc arguman sayısını verir.
	{
		printf("Usage: %s filename\n", argv[0]); //  argv[0]: programın adı örneğin Prpject1.exe
												 //	          programın adını değiştiriseniz değişir.
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) // argv[1] : dosyanın adı
	{
		printf("Can't open %s\n", argv[1]);		
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)		// Dosya sonuna kadar oku ve konsola yaz.
	{
		putc(ch, stdout); // same as putchar(ch);	
		count++;
	}

	fclose(fp);

	printf("\n\nFile %s has %Lu characters\n\n", argv[1], count);
	
	return 0;
}