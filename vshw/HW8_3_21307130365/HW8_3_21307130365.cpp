#include<stdio.h>
int d;
void gcd(int a, int b) {
	static int c = 1;
	if (a == b) {
		printf("Recursive layer %d: a = %d, b = %d\n", c, a, b);
		d = a;
	}
	if (a > b) {
		printf("Recursive layer %d: a = %d, b = %d\n", c, a, b);
		c++;
		gcd(a - b, b);
	}
	if (a < b) {
		printf("Recursive layer %d: a = %d, b = %d\n", c, a, b);
		c++;
		gcd(a, b - a);
	}
}
int main() {
	int a, b, c;
	printf("Enter 2 integers:\n");
	scanf_s("%d%d", &a, &b);
	gcd(a, b);
	printf("The greatest common divisor of %d and %d is %d.", a, b, d);
}