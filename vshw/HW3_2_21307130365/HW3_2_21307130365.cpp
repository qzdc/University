#include<stdio.h>
int main()
{
	int a, b, c, d, max1, min1 , max2 , min2 , max , min;
	printf("Print 4 integers:");
	scanf_s("%d%d%d%d", &a, &b, &c, &d);
	if (a < b) {
		max1 = b;
		min1 = a;
	}
	else { max1 = a; min1 = b; }/*取ab最大数最小数*/
	if (c < d) {
		max2 = d;
		min2 = c;
	}
	else { max2 = c; min2 = d; }/*取cd最大数最小数*/
	if (max1 < max2) {
		max = max2;
	}
	else max = max1;
	if (min1 < min2) {
		min = min1;
	}
	else min = min2;/*比较2组最大数最小数*/
	printf("Largest:%d\n", max);
	printf("Smallest:%d", min);
	return 0;
}