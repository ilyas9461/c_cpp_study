int imin(int, int);

int main(void)
{

	int evil1, evil2;

	printf("Enter a pair of integers (q to quit):\n");
	int scanfRet = scanf("%d %d", &evil1, &evil2);
	printf("ret:%d\n", scanfRet);

	while (scanfRet == 2)
	{
		printf("The lesser of %d and %d is %d. ret:%d\n",
			   evil1, evil2, imin(evil1, evil2), scanfRet);

		printf("Enter a pair of integers (q to quit):\n");
		scanfRet = scanf("%d %d", &evil1, &evil2);
		printf("ret:%d\n", scanfRet);
	}

	printf("Bye.\n");

	_getch();

	return 0;
}

int imin(int n, int m)
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return min;
}
