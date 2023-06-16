#include<stdio.h>
#include<string.h>//已通过样例测试
int main() {
	int  l = 0, l0 = 0, s = 0, s0 = 0;
	char a[105], b[105], c[105];
	printf("Enter 3 strings(length < 100):\n");
	gets_s(a);
	gets_s(b);
	gets_s(c);
	for (int i = 0; a[i]; i++) {
		for (int j = 0; b[j]; j++) {
			for (int k = 0; c[k]; k++) {
				if (a[i] == b[j] && a[i] == c[k]) {
					s0 = i;
					for (l0 = 0; a[i + l0] == b[j + l0] &&
						a[i + l0] == c[k + l0] && 
						a[i + l0] && b[j + l0] && c[k + l0]; l0++);
					if (l0 > l) {
						l = l0;
						s = s0;
						//l0，s0是暂存的公共字符串长度，开始位置；
						//l，s是最长的公共字符串长度，开始位置；
					}
				}
			}
		}
	}
	if (l) {
		printf("\nTheir longest common substring is:\n");
		for (int i = 0; i < l; i++) {
			printf("%c", a[s + i]);
		}
	}
	else {
		printf("\nThere is no common substring!");
	}
	return 0;
}