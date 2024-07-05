/* while2.c -- watch your semicolons */
#include "stdio.h"

int main(void)
{

	int ans, n=0;
	ans = 2;
	for (;;)
		ans = ans * n;

	printf("n = %d; ans = %d.\n", n, ans);




	return 0;
}

//Severity	Code	Description	Project	File	Line	Suppression State
//Error	C4996	'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation,
//use _CRT_SECURE_NO_WARNINGS.See online help for details.c_sablon	C : \Users\ilyas\Desktop\COMP124_ANSI_C\VS_problems_solution\vs2019 - sablon\c_sablon\main.c	16




