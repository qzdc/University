#include<stdio.h>
#include<time.h>
#include<stdlib.h>//ÒÑÍ¨¹ý²âÊÔ
int main() {
	int a[105][105] = { 0 };
	int i, j, temp, cishu, n;
	srand(time(NULL));
	printf("Enter the order of a square matrix([1, 100]): ");
	scanf_s("%d", &n);
	printf("Randomly generate an %d-order square matrix within 100:\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	cishu = n / 2;
	for (j = 0; j < cishu; j++) {
		for (i = 1 + j; i < n - 1 - j; i++) {
			temp = a[j][i];
			a[j][i] = a[n - 1 - i][j];
			a[n - 1 - i][j] = temp;
		}
		for (i = 1 + j; i < n - 1 - j; i++) {
			temp = a[n - 1 - j][i];
			a[n - 1 - j][i] = a[n - 1 - i][n - 1 -j];
			a[n - 1 - i][n - 1 - j] = temp;
		}
		for (i = 1 + j; i < n - 1 - j; i++) {
			temp = a[j][i];
			a[j][i] = a[n - 1 - j][n - 1 - i];
			a[n - 1 - j][n - 1 - i] = temp;
		}//ÖÃ»»Àâ¿é
		temp = a[j][j];
		a[j][j] = a[n - 1 - j][j];
		a[n - 1 - j][j] = temp;
		temp = a[j][n - 1 - j];
		a[j][n - 1 - j] = a[n - 1 - j][n - 1 - j];
		a[n - 1 - j][n - 1 - j] = temp;
		temp = a[j][j];
		a[j][j] = a[n - 1 - j][n - 1 - j];
		a[n - 1 - j][n - 1 - j] = temp;//ÖÃ»»½Ç¿é
	}
	printf("The square matrix after 90 degrees couterclockwise rotation:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}