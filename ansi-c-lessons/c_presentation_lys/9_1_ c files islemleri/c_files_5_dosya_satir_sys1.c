/* Text dosyadaki satýr sayýsýný bulmak...*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

int dosyaSatirSysGetir(const char* dosya_adi);
int getTotalLlineOfRecords(FILE* f);

int main(void)
{
	int line = 0;
	char buf[100];

	FILE* file;
	file = fopen("orn_dosyalar\\students.txt", "r");

	if (file != NULL) {
		do {
			fgets(buf, sizeof(buf), file);
			line++;
		} while (!feof(file));

		fclose(file);
	}
	else line = -1;

	printf("Satir Sys1: %u\n", line);

	printf("Satir Sys2: %u\n", dosyaSatirSysGetir("orn_dosyalar\\students.txt"));

	return 0;
}

int dosyaSatirSysGetir(const char *dosya_adi) {
	int line = 0;
	char buf[100];
	FILE* _file;
	_file = fopen(dosya_adi, "r");
	if (_file != NULL) {
		do {
			fgets(buf, sizeof(buf), _file);
			line++;
		} while (!feof(_file));
		fclose(_file);
	}
	else line = -1;
	return line;
}

int getTotalLlineOfRecords(FILE* f) {
	int line = 0;
	char buf[100];

	if (f != NULL) {
		do {
			fgets(buf, sizeof(buf), f);
			line++;
		} while (!feof(f));
		fclose(f);
	}
	else line = -1;
	return line;
}

