#include<stdio.h>
int main()
{
	int n, hang, i;
	char c = ' ';
	printf("Enter n:");
	scanf_s("%d", &n);
	for (i = 1; i <= 2 * n - 1; i++)
		printf("*");
	printf("\n");
	for (hang=2; hang<n; hang++) {
		for (i = 1; i < hang; i++)
			printf(" ");
		printf("*");
		for (i = 1; i <= 2 * n - 1 - hang * 2; i++)
			printf(" ");
		printf("*\n");
	}
	for (i = 1; i <=  n- 1 ; i++)
		printf(" ");
	if(n != 1)
		printf("*");
	return 0;
}
