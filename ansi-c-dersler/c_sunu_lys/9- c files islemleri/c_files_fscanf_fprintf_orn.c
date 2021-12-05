/* C FILES :
	fscanf() ve fprintf() ornek.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	if ((fp = fopen("orn.txt", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"orn.txt\" file.\n");
		exit(EXIT_FAILURE);
	}

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");

	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);

	puts("File contents:");
	rewind(fp); /* go back to beginning of file */

	while (fscanf(fp, "%s", words) == 1)
		puts(words);

	puts("\nDone!");

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	_getch();

	return 0;
}