#define N 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//有重复版，已通过样例测试
int main()
{
	int a[N], b[N], n = N;
	int* p[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++){
		a[i] = (unsigned)rand() % 10;
	}
	p[0]=a;
	for (int i = 1; i < n; i++) {
		p[i] = p[i-1]+1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++)
		if (*p[j] > *p[j + 1]) {
			int* t = p[j];
			p[j] = p[j + 1];
			p[j + 1] = t;
		}
	}
	b[p[0] - &a[0]] = 1;
	for (int i = 1, j = 2; i < n; i++) {
		if (*p[i - 1] != *p[i]) {
			b[p[i] - &a[0]] = j++;
		}
		else {
			b[p[i] - &a[0]] = b[p[i - 1] - &a[0]];
		}
	}
	printf("Randomly generate %d postive integers within 10:\n", n);
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
	}
	printf("\nTheir sequence numbers in ascending order:\n");
	for (int i = 0; i < n; i++) {
		printf("%4d", b[i]);
	}
	printf("\n");
	return 0;
}
