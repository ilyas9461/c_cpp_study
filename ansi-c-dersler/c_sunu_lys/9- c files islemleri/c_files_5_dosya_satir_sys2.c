/* Text dosyadaki satýr sayýsýný bulmak...*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

int dosyaSatirSysGetir(const char* dosya_adi);

int main()
{
	FILE* fileptr;
	int count_lines = 0;
	char chr;

	fileptr = fopen("orn_dosyalar\\students.txt", "r");
	//extract character from file and store in chr

	do{
		//take next character from file.
		chr = getc(fileptr);
		//Count whenever new line is encountered
		if (chr == '\n')
		{
			count_lines++;
		}
	} while (chr != EOF);

	fclose(fileptr); //close file.

	printf("Satir Sayisi1: %d \n", count_lines+1);

	printf("Satir Sayisi2: %d \n", dosyaSatirSysGetir("orn_dosyalar\\students.txt"));
	return 0;
}

int dosyaSatirSysGetir(const char *dosya_adi) {
	FILE* fileptr;
	int count_lines = 0;
	char chr;

	fileptr = fopen(dosya_adi, "r");
	//extract character from file and store in chr
	if (fileptr != NULL) {
		do {
			//take next character from file.
			chr = getc(fileptr);
			//Count whenever new line is encountered
			if (chr == '\n')
			{
				count_lines++;
			}
		} while (chr != EOF);
	}
	else return -1;

	fclose(fileptr); //close file.
	if (count_lines == 0) return 0;
	return count_lines+1;
}


