#include<stdio.h>
#include<string.h>
int main()
{
	char a[105] = { '1' };
	char b[105] = { '1' };
	int i, j, l1, l2, s1, s2, e1, e2, kaishi;
	int l = 0;
	printf("Enter 2 strings (length < 100):\n");
	gets_s(a);
	gets_s(b);
	l1 = strlen(a);
	l2 = strlen(b);
	for (i = 0; i < l1; i++) {
		for (int k = 0; k < l2 - 1; k++) {
			for (j = k; j < l2; j++) {
				if (a[i] == b[j]) {
					e1 = s1 = i;
					e2 = s2 = j;
					while (a[e1] == b[e2] && e1 <= l1 && e2 <= l2) {
						e1++;
						e2++;
					}
					if (l < e1 - s1 + 1) {
						l = e1 - s1 + 1;
						kaishi = s1;
					}
				}
				if (a[i] != b[j])
					break;
			}
		}
	}
	if (l) {
		printf("The longest common substring is:\n");
		for (i = 0; i < l - 1; i++) {
			printf("%c", a[kaishi]);
			kaishi++;
		}
	}
	else printf("There is no common character.");
	return 0;
}
