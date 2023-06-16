#include<stdio.h>
int main()
{
	int a[101]={0};
	int i, j, k, l, temp ,sign;
	char input;
	printf("Enter an integer n (1 <= n < 10^100):");
	for (i = 0; 1; i++) {
		input = getchar();
		if (input == '\n')
			break;
		a[i] = input - '0';
	}
	//输入数组，且保证最后一位是数字
	for (j = 0 ,k = 0; j < i; j++) {
		if (a[j] >= a[j + 1]) {
			k++;
		}
	}//判断是否有更大数
	if (k == i )
		printf("No larger intege rexists!\n");
	else {
		for (j = 0,  l = 0; j < i;j++) {
			for (sign = 0, l = j + 1; l < i; l++) {
				if (a[l] > a[j])
					sign += 1;
			}
			if (sign == 0)
				break;
		}
		//下标j的后面没有比他大的
		for (l = a[j - 1] + 1 ,sign = 0;l<=9; l++,k++) {
			for (k = j;k < i; k++)
				if (a[k] == l) {
					sign = 1;
					break;
				}
			if (sign == 1)
				break;
		}//j-1以后找比其大的数的最小值的下标k
		temp = a[k];
		a[k] = a[j - 1];
		a[j - 1] = temp;//换换

		for (l = j; j < i-1 ; j++)
			for (k = l; k < i-1 ; k++)
				if (a[k] > a[k + 1]) {
					temp = a[k];
					a[k] = a[k + 1];
					a[k + 1] = temp;
				}//对下标j以后升序排列
		printf("The larger smallest integer is: ");
		for (j = 0; j < i; j++)
			printf("%d", a[j]); 
	}
	return 0;
}
