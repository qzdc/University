#include<stdio.h>
#include<string.h>//Í¨¹ýÑùÀý²âÊÔ
int main()
{
	char s[105] = { '\0' };
	char* p = s, * q = s, * r = s;
	int flag;
	int i = 0, j = 0, k;
	printf("Enter a string with extra white spaces:\n");
	gets_s(s);
	if (*p == ' ') {
		for (; *(p + j) == ' '; j++);
		for (; *(p + i); i++) {
			*(p + i) = *(p + i + j);
		}
	}
	for (i = 1; *(p + i); i++) {
		if (*(p + i) == ' ') {
			for (j = i; *(p + j) == ' '; j++);
			for (k = 0; *(p + k + i); k++) {
				*(p + i + k + 1) = *(p + k + j);
			}
		}
	}
	while(*(p + i - 1) == ' '){
		*(p + i - 1) = '\0';
	}
	printf("The string after removing extra whitespaces:\n");
	puts(s);
}