/* Structures: dosyaya yazma ve okuma işlemi*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */

struct book { /* set up book template */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);

int main(void)
{
	struct book library[MAXBKS]; /* array of structures */
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	/*void rewind(FILE *stream);
	Stream parametresi ile gösterilen akışın aktif dosya konumunu en başa alır.*/
	rewind(pbooks); /* go to start of file */

	//size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
	/*ptr: Minimum boyutu (size * count) kadar olan bir bellek bloğunu gösteren işaretçidir.
	size : Okunacak olan her bir elemanın boyutunu gösterir.
	count : Okunacak eleman sayısını gösterir.
	stream : Karakterlerin okunacağı akışı tanımlayan FILE nesnesi işaretçisidir.*/

	while (count < MAXBKS && fread(&library[count], size,
		1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}

	filecount = count;

	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");

	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue; /* clear input line */
		if (count < MAXBKS)
			puts("Enter the next title.");
	}
	if (count > 0)
	{
		puts("Here is the list of your books:");

		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);

		//size_t fwrite(void *ptr, size_t size, size_t count, FILE *stream);
		/*ptr: Minimum boyutu (size * count) kadar olan bir bellek bloğunu gösteren işaretçidir.
		size : Yazılacak olan her bir elemanın boyutunu gösterir.
		count : Yazılacak eleman sayısını gösterir.
		stream : Karakterlerin yazılacağı akışı tanımlayan FILE nesnesi işaretçisidir*/

		fwrite(&library[filecount], size, count - filecount,
			pbooks);
	}
	else
		puts("No books? Too bad.\n");
	puts("Bye.\n");

	fclose(pbooks);

	getchar();
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline
		if (find) // if the address is not NULL,
			*find = '\0'; // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}


