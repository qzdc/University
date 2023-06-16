#include<stdio.h>
int main() {
	int a[35][35] = { 0 };
	int n, i, j, str, end, x = 1;
	printf("Enter n (0<n<=30): ");
	scanf_s("%d", &n);
	end = n;
	for (str = 0;end - str >= 1; str++) {
		end = n - str - 1;
		for (i = j = str; j <= end; j++)
			a[i][j] = x++;
		for (j = end, i = str + 1; i <= end; i++)
			a[i][j] = x++;
		for (i = end, j = end - 1; j >= str; j--)
			a[i][j] = x++;
		for (j = str, i = end - 1; i >= str + 1; i--)
			a[i][j] = x++;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++){
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
