#include<stdio.h>
int main() 
{
	int rm ,a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13;
	printf("Enter a 13-digit EAN:");
	scanf_s("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12, &a13);
	rm = ((3 * (a2 + a4 + a6+a8 + a10 + a12) + a1 + a3 + a5 + a7 + a9 + a11) - 1) % 10;
	if (a13 == 9 - rm) {
		printf("VALID");
	}
	else printf("NOT VALID");
	return 0;
}