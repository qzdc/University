#include<stdio.h>
//Í¨¹ı²âÊÔ
int a[200] = { 1,1 };
void multi(int i) {
	int j;
	for (j = 1; j <= a[0]; j++) {
		a[j] *= i;
	}
	for (j = 1; j <= a[0]; j++) {
		if ((a[j] / 10) % 10) {
			a[j + 1] += (a[j] / 10) % 10;
		}
		if ((a[j] / 100) % 10) {
			a[j + 2] += (a[j] / 100) % 10;
		}
		if (j == a[0]) {
			for (int k = j; k <= j + 3; k++) {
				if (a[k] != 0) {
					a[0] = k;
				}
			}
		}
		a[j] = a[j] % 10;
	}
}

int main()
{
	int n, i;
	printf("Enter n: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		multi(i);
	}
	printf("%d! = ", n);
	for (i = a[0]; i != 0; i--) {
		printf("%d", a[i]);
	}
	printf("\nIt's a %d-digit mumber.", a[0]);
	return 0;
}