#include <stdio.h>
int sum(int n);

int main()
{
	int number, result;

	printf("pozitif bir tamsayı girin: ");
	scanf("%d", &number);

	result = sum(number);

	printf("Toplam = %d", result);
	getch();
	return 0;
}

int sum(int num)
{
	if (num != 0)
		return num + sum(num - 1); // sum() function calls itself
	else
		return num;
}