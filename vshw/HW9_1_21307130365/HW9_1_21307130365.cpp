#include<stdio.h>
//ÒÑÍ¨¹ý
int zimu(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	else
		return 0;
}
int main()
{
	char s[1005];
	int i, j, k, m, max = 0, num = 0;
	printf("Enter some text:\n");
	gets_s(s);
	for (i = 0; s[i] != '\0'; i++) {
		if (zimu(s[i])) {
			for (j = i+1; zimu(s[j]); j++);
			num++;
			m = j - i;
			if (m > max) {
				max = m;
				k = i;
			}
			i = j - 1;
		}
	}
	printf("There are %d words.\n", num);
	printf("The word of max length is: ");
	for (i = k; i < k + max; i++) {
		printf("%c", s[i]);
	}
	return 0;
}