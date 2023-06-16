#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {//Í¨¹ıÑùÀı²âÊÔ
	int m, n, t;
	int a[105];
	int* p = &a[0];
	srand(time(NULL));
	printf("Enter n (<100): ");
	scanf_s("%d", &n);
	printf("Randomly generate %d non negative integers within 100:\n", n);
	for (int i = 0; i < n; i++) {
		*(p + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", *(p + i));
	}
	printf("\nEnter m(<%d): ", n);
	scanf_s("%d", &m);
	printf("After moving:\n");
	for (int i = 0; i < m; i++) {
		t = *p;
		for (int j = 0; j < n - 1; j++) {
			*(p + j) = *(p + j + 1);
		}
		*(p + n - 1) = t;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", *(p + i));
	}
	return 0;
}