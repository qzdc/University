#include<stdio.h>
#include<string.h>//all test samples have passed
FILE* fp;
int main() {
	char c, ap, a, next;
	char n[50];
	int i = 1;
	printf("Enter a file name: ");
	scanf("%s%*C", n);
	fp = fopen(n, "w");
	printf("Add a line number before each line? (Y/N): ");
	scanf("%c%*C", &c);
	printf("Enter some text (ending with a blank line):\n");
	if (c == 'y' || c == 'Y') {
		next = getchar();
		fprintf(fp, "%d. %c", i++, next);
		while (1) {
			a = next;
			if((next = getchar()) == '\n' && a == '\n'){
				break;
			}
			if(a == '\n'){
				fprintf(fp, "%d. ", i++);
			}
			fprintf(fp, "%c", next);
		}
	}
	else if (c == 'n' || c == 'N') {
		ap = '\n';
		a = getchar();
		while (1) {
			fprintf(fp, "%c", a);
			ap = a;
			if((a = getchar()) == '\n' && ap == '\n'){
				break;
			}
		}
	}
	fclose(fp);
	return 0;
}
