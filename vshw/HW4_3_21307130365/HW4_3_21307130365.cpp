#include<stdio.h>
int main()
{
	int a1, b1, a2, b2, a3, b3, i;
	printf("Enter 2 fractions separated by a plus sign:");
		scanf("%d/%d+%d/%d", &a1, &b1, &a2, &b2);
	a3 = a1 * b2 + a2 * b1;
	b3 = b1 * b2;
	if(a3 > 0){
		a3 >= b3 ? i = b3 : i = a3;
		for (; 1; i--)
		if (b3 % i + a3 % i == 0)
			break;
		a3 /= i;
		b3 /= i;
		if (b3 != 1)
			printf("%d/%d+%d/%d=%d/%d", a1, b1, a2, b2, a3, b3);
		else printf("%d/%d+%d/%d=%d", a1, b1, a2, b2, a3);
	}
	if(a3 == 0)
		printf("%d/%d+%d/%d=%d", a1, b1, a2, b2, a3);
	if(a3 < 0){
		a3 *= -1;
		a3 >= b3 ? i = b3 : i = a3;
		for (; 1; i--)
		if (b3 % i + a3 % i == 0)
			break;
		a3 /= i;
		b3 /= i;
		if (b3 != 1)
			printf("%d/%d+%d/%d=-%d/%d", a1, b1, a2, b2, a3, b3);
		else printf("%d/%d+%d/%d=-%d", a1, b1, a2, b2, a3);
	}
	
	return 0;
}

