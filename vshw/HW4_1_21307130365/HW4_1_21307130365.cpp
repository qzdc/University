#include<stdio.h>
int main()
{
	int  a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;
	char num;
	printf("Enter an integer:");
	while (1) {
		num = getchar()-'0';
		if (num == '\n'-'0')
		break;
		switch (num)
		{
		case 0:a0 += 1;  break;
		case 1:a1 += 1;  break;
		case 2:a2 += 1;  break;
		case 3:a3 += 1;  break;
		case 4:a4 += 1;  break;
		case 5:a5 += 1;  break;
		case 6:a6 += 1;  break;
		case 7:a7 += 1;  break;
		case 8:a8 += 1;  break;
		case 9:a9 += 1;  break;
		default:;
		}
	}
	printf("Digit\toccurrence:\n");
	if (a0 > 0)
		printf("0\t%d\n", a0);
	if(a1>0)
		printf("1\t%d\n", a1);
	if (a2 > 0)
		printf("2\t%d\n", a2);
	if (a3 > 0)
		printf("3\t%d\n", a3);
	if (a4 > 0)
		printf("4\t%d\n", a4);
	if (a5 > 0)
		printf("5\t%d\n", a5);
	if (a6 > 0)
		printf("6\t%d\n", a6);
	if (a7 > 0)
		printf("7\t%d\n", a7);
	if (a8 > 0)
		printf("8\t%d\n", a8);
	if (a9 > 0)
		printf("9\t%d\n", a9);
	return 0;
}