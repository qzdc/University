#include<stdio.h>
#include<math.h>
int main()
{
	int i, j1, j2, k, er, ba;
	int a[9], b[3];
	for (i = 1; i <= 21; i++)
		printf("* ");
	printf("\n*\t\t\t\t\t*\n");
	printf("* Conversion between decimal system and *\n");
	printf("* binary/octal system (1~256)           *\n");
	printf("*\t\t\t\t\t*\n");
	for (i = 1; i <= 21; i++)
		printf("* ");
	printf("\n\nDecimal\t    Binary\tOctal\n");
	for (i = 1; i <= 256; i++)
	{
		for (j1 = 0, k = i, er = 0; k > 0; j1++){
			a[j1] = k % 2;
			k /= 2;
			er += a[j1] * pow(10, j1);
		}
		for (j2 = 0, k = i, ba = 0; k > 0; j2++) {
			b[j2] = k % 8;
			k /= 8;
			ba += b[j2] * pow(10, j2);
		}
		printf("%6d\t", i);
		printf("%9d", er);
		printf("\t");
		printf( "%3d", ba);
		printf("\n");
	}
	return 0;
}
