/* fgets1.c -- using fgets() and fputs() */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define ANSWER "Grant"
#define SIZE 40

char* s_gets(char* st, int n);

int compfunc(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

int main(void) {
	char idizi[] ="ilyas" ;	//{ 14, 35, 4, 17, 5, 9, 43, 11, 21, 16 }
	int id;
	int num = sizeof(idizi) / sizeof(idizi[0]);

	for (id = 0; id < num; id++) {
		printf("%c ", idizi[id]);
	}

	qsort(idizi, num-1, sizeof(char), compfunc);

	printf("\n");

	for (id = 0; id < num; id++) {
		printf("%c ", idizi[id]);
	}

	return 0;
}

char* strstr(const char* s1, const char* s2);


char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
