#include<stdio.h>
#include<string.h>
void  output_header()
{
	int i, i1, i2, im;
	char str1[105] = { "Conversion between decimal system and" };
	char str2[105] = { "binary/octal/hex system (1~256)" };
	i2 = strlen(str2);
	i1 = strlen(str1);
	i1 > i2 ? im = i1 + 4 : im = i2 + 4;
	for (i = 1; i <= im / 2 + 1; i++)
		printf("* ");
	printf("\n*");
	for (i = 1; i <= im - 2; i++)
		printf(" ");
	if((im - 1) % 2)
		printf(" ");
	printf("*\n* %s ", str1);
	if((im - 1) % 2)
		printf(" ");
	printf("*\n* %s", str2);
	if((im - 1) % 2)
		printf(" ");
	for (i = 0; i < im - i2 - 3; i++)
		printf(" ");
	printf("*\n*");
	for (i = 1; i <= im - 2; i++)
		printf(" ");
	if((im - 1) % 2)
		printf(" ");
	printf("*\n");
	for (i = 1; i <= im / 2 + 1; i++)
		printf("* ");
	printf("\n\n Decimal    Binary   Octal     Hex\n");
	return;
}


void convert(int i, int jz, int weishu)
{
	int j;
	char a[12] = { '0' };
	for (j = 0; i != 0; i /= jz) {
		a[j] = i % jz + '0';
		j++;
	}
	for (j = 0; j < weishu; j++) {
		if (a[j] > '9' && a[j] < '9' + 7) {
			a[j] = a[j] - '9' + 'A' - 1;
		}
	}


	for (j = weishu - 1; j >= 0; j--) {
		printf("%c", a[j] >= '0' ? a[j] : ' ');
	}
}


int main()
{
	int i;
	output_header();
	for (i = 1; i <= 256; i++) {
		printf("%8d", i);
		convert(i, 2, 10);  // 输出i的二进制表示, 第3个参数表示输出宽度
		convert(i, 8, 8);
		convert(i, 16, 8);
		printf("\n");
	}

	return 0;
}
