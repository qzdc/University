#include<stdio.h>//已通过样例测试
int isk(int n, int* p1, int* p2) {
	int sum, i, weishu, d = 10;
	while (n / d) {
		*p1 = n / d;
		*p2 = n % d;
		if ((*p1 + *p2) * (*p1 + *p2) == n) {
			return 1;
		}
		d *= 10;
	}
	return 0;
}
int main() {
	int a, b;
	int x, i;
	printf("Enter n ([10,1000000]): ");
	scanf_s("%d", &x);
	printf("K-number within %d:\n", x);
	for (i = 10; i < x; i++) {
		if (isk(i, &a, &b)) {
			printf("%d=(%d+%d)^2\n", i, a, b);
		}
	}
	return 0;
}