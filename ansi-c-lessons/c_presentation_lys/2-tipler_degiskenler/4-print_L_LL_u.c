/* print2.c-more printf() properties */
#include <stdio.h>

int main(void)
{
	unsigned int un = 3000000000u; /* system with 32-bit int */
	short end = 200u; /* and 16-bit short */
	long big = 65537lu;
	long long verybig = 12345678908642LL;

	printf("un = %u and not %d\n", un, un);

	printf("end = %hd and %d\n", end, end);

	printf("big = %ld and not %hd\n", big, big);

	printf("verybig= %lld and not %ld\n", verybig, verybig);

	getch();
	return 0;
}