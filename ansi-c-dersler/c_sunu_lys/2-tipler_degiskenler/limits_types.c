// Example 2-1. 
// limits.c: Display the value ranges of char and int.
// ---------------------------------------------------
#include <stdio.h>
#include <limits.h>     // Contains the macros CHAR_MIN, INT_MIN, etc.
#include <stdint.h>		//int tipi i�in kulllan�lan makrolar...

#define ARR_SIZE 10
typedef signed int int_fast32_t;

int main()
{
	printf("Storage sizes and value ranges of the types char and int\n\n");

	printf("The type char is %s.\n\n", CHAR_MIN < 0 ? "signed" : "unsigned");// Tek sat�rl�k if yap�s� kullan�m�;
																			 // <mant�ksal ifade > ? <do�ru ise yap�lacak> :<de�ilse yap�lacak>

	printf(" Type   Size (in bytes)   Minimum         Maximum\n"
		"---------------------------------------------------\n");
	printf(" char %8u %20d %15d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf(" int  %8u %20d %15d\n", sizeof(int), INT_MIN, INT_MAX);

	putchar('\n');
	int_fast32_t arr[ARR_SIZE]; // Define an array arr
	// with elements of type int_fast32_t
	for (int i = 0; i < ARR_SIZE; ++i){
		arr[i] = (int_fast32_t)i; // Initialize each element
		printf("arr[i]=%d \n", i);
	}
	putchar('\n');

	getchar(); // konsoldan bir karakter okur ve enter(sat�r sonu)bekler.

	return 0;
}
