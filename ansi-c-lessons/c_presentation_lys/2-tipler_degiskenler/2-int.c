#include <stdio.h>

const int VALUE = 100;

int main(void)
{
	int ten = 10;
	int two = 2;

	printf("Doing it right: ");
	printf("\n%d minus %d is %d\n", ten, 2, ten - two);

	printf("\nDoing it wrong: \n");
	printf("%d minus %d is %d\n", ten); // forgot 2 arguments

	printf("\nThis is int constant: %d", VALUE);

	getch();

	return 0;
}