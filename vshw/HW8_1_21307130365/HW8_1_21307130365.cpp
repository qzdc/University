#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[105];
int n;
void cre() {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
void rank() {
	int t;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
int len() {
	int lens = 1, st = 0, end = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				st = i;
				end = j;
			}
			if (lens < end - st + 1)
				lens = end - st + 1;
			if (a[i] != a[j])
				break;
		}
	}
	return lens;
}
void out() {
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
		if ( i % 10 == 9 && i != n - 1)
			printf("\n");
	}
}
int main() {
	int lens;
	printf("Enter a positive integer n (n<=100): ");
	scanf_s("%d", &n);
	cre();
	printf("Randomly generate %d positive integers (<100):\n",n);
	out();
	printf("\nAfter sorting:\n");
	rank();
	lens = len();
	out();
	printf("\nThe length of the longest platform:%2d", lens);
	return 0;
}