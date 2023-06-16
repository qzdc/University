#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
//已通过测试样例
void create_array(int* a, int n) {
	srand(time(NULL));
	int* p = a;
	for (int i = 0; i < n; i++) {
		*(p + i) = rand() % 10;
	}
}
void output_array(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", *(a + i));
	}
	printf("\n");
}
int copy_diff(int* a, int n, int* b) {
	int bl[N] = { *a };//blacklist
	//*b = *a;
	int nbl = 0, f, nb = 0;
	for (int i = 0; i < n; i++) {
		f = 1;
		for (int j = 0; j < nbl; j++) {
			if (*(a + i) == bl[j]) {
				f = 0;
			}
		}
		if (f) {
			*(b) = *(a + i);
			bl[nbl] = *b;
			b++;
			nb++;
			nbl++;
		}
	}
	return nb;
}
int main()
{
	int a[N], b[N], n;

	printf("Enter n(<=100): ");
	scanf("%d", &n);

	create_array(a, n);
	puts("The original array:");
	output_array(a, n);

	n = copy_diff(a, n, b);
	puts("The array copied without duplicate values:");
	output_array(b, n);

	return 0;
}