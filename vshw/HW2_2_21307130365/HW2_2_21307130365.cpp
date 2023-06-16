#include<stdio.h>
int main()
{
	int qian, bai,shi, ge,sum ;
	printf("Enter a 4-digit number:");
	scanf_s("%1d%1d%1d%1d", &qian, &bai, &shi, &ge);
	sum = qian + ge + shi + bai;
	printf("%d\n", sum);
	return 0;

}