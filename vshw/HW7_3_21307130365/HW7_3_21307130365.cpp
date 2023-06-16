#include<stdio.h>
void kaishiyuedu(int n)
{
	int shang[100], yushu[100];
	int  i = 0, j, k, len, flag = 0, pos, p1 = 0, p2 = 0;
	shang[i] = 10 / n;
	yushu[i] = 10 % n;
	for (i = 1, j = 10; 1; i++) {
		j = yushu[i - 1] * 10;
		shang[i] = j / n;
		yushu[i] = j % n;
		j *= 10;//模拟除法过程赋值 
		if (yushu[i] == 0) {
			flag = 1;
			if (shang[i] == 0)
				i--;
			pos = i;
			break;//不循环有限 
		}
		for (k = 0; k < i; k++) {
			if ( yushu[k] == yushu[i] && shang[i] == shang[k]) {
				flag = 2;
				p1 = k;
				p2 = i;
				break;//循环 
			}
		}
		if (flag == 2)
			break;
	}
	printf("1/%d=0.", n);//输出
	if (flag == 1) {
		for (i = 0; i <= pos; i++)
			printf("%d", shang[i]); 
	}
	if (flag == 2) {
		for (i = p2; i > p1; i--)
			shang[i ] = shang[i - 1];
		shang[p1] = '(' - '0';
		for (i = 0; i <= p2 ; i++)
			printf("%c", shang[i] + '0');
		printf(")");
	}
	printf("\n");
}


int main() {
	for (int i = 2; i <= 100; i++)
		kaishiyuedu(i);
	return 0;
}

