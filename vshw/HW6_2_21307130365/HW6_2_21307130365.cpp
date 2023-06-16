#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int a, n ,m;
	printf("Enter a positive integer n (1 <= n <= 2147483647):");
	scanf_s("%d", &n);
	printf("%d =", n);
	m = n;
	for (a = 2; a <= n && a<=pow(m,0.5); a++) {
		while (n != a) {
			if (n % a == 0) {
				printf(" %d *", a);
				n = n / a;
			}
			else break;
		}
	}
	printf(" %d\n", n);
	return 0;
}