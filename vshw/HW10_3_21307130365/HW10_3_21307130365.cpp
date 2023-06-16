#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {//Í¨¹ı²âÊÔ
	int m, n = 1, t;
	int a[200];
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
	for (int j = n; j < n + m; j++) {
		*(p + j) = *(p + j - n);
	}
	for (int k = m; k < m + n; k++) {
		printf("%d ", *(p + k));
	}
	return 0;
}
