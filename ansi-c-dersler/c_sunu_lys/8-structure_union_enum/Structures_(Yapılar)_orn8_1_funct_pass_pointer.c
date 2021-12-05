/* Structures: fonksiyonlara yapı üyelerinin değer
   yoluyla geçirilmesi...*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>  //setlocale(LC_ALL, "Turkish");

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);

char * s_gets(char * st, int n);

int main(void)
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);

	getchar();
	return 0;
}

/* void getinfo(struct namect * pst):
Yapı fonksiyona pointer argüman olarak geçirilmiş.
Adresi referans olarak verilen yapı değişkeninin üyeleri
fonksiyon içersindeki ilgili değişimlerden etkilenirler.

Üyelerin değerleri değiştirilebilir.*/

void getinfo(struct namect * pst)
{
	printf("Please enter your first name.\n");
	s_gets(pst->fname, NLEN);
	printf("Please enter your last name.\n");
	s_gets(pst->lname, NLEN);
}

void makeinfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) +
		strlen(pst->lname);
}

/* void showinfo(const struct namect * pst):
Yapı fonksiyona sabit pointer olark geçirilmiş, 
fonksiyonda yapı ile ilgil ideğişmlerden üyeleri
etkilenmezler. Değişim ilei ilgili kod oluşturulursa,
C derleyicisi "'=': left operand must be l-value"
hatası oluşturur.*/

void showinfo(const struct namect * pst)
{
	printf("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letters);
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


