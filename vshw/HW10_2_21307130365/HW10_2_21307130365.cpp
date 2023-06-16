#include<stdio.h>
#include<math.h>//ÒÑÍ¨¹ı²âÊÔ
int a, b;
int isk( int n) {
	int sum, i, weishu;
	for (i = n, weishu = 0; i; i /= 10, weishu++);
	for (i = 1; i <= weishu - 1; i++) {
		a = n / (int)pow(10, i);
		b = n % (int)pow(10, i);
		if ((a + b) * (a + b) == n) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int x, i;
	printf("Enter n (10<=n<1000000): ");
	scanf_s("%d", &x);
	printf("K-number within %d:\n", x);
	for (i = 10; i < x; i++) {
		if (isk(i)) {
			printf("%d=(%d+%d)^2\n", i, a, b);
		}
	}
	return 0;
}