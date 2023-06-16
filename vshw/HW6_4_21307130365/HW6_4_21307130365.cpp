#include<stdio.h>
int main()
{
	int a[30][30];
	int n, i, j , djx ,zhi=1 ,sign;//对角线
	printf("Enter n (n<=30):");
	scanf_s("%d", &n);
	for (djx = 1, sign = 1; 1;) {
		if (sign == 1) {
			for (i = 0; i < djx ; i++) {
				j = djx - i - 1;
				a[i][j] = zhi;
				zhi++;
			}
			sign *= -1;
			djx++;
		}
		if (djx - 1 == n)
			break;
		if (sign == -1) {
			for (j = 0; j < djx; j++) {
				i = djx - j - 1;
				a[i][j] = zhi;
				zhi++;
			}
			sign *= -1;
			djx++;
		}
		if (djx - 1 == n)
			break;
	}//上半个
	while(1) {
		if (sign == 1) {
			for (i = djx - n; i < n; i++) {
				j = djx - i - 1;
				a[i][j] = zhi;
				zhi++;
			}
			sign *= -1;
			djx++;
		}
		if (djx - 1 == n * 2 - 1)
			break;
		if (sign == -1) {
			for (j = djx - n; j < n ; j++) {
				i = djx - j - 1;
				a[i][j] = zhi;
				zhi++;
			}
			sign *= -1;
			djx++;
		}
		if (djx - 1 == n * 2 - 1)
			break;
	}//下半个
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return 0;
}