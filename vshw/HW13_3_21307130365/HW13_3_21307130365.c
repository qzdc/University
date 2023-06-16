#include<stdio.h>
#include<stdlib.h>
#include<time.h>//all test samples have passed
int main() {
	int n, a[11] = {0};
	printf("Enter the number of students: ");
	scanf("%d", &n);
	int *p = (int*)(calloc(n, sizeof(int)));
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 51 + 50;
	}
	for (int i = 0; i < n; i++) {
		a[p[i] / 10]++;
	}
	a[9] += a[10];
	a[5] = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];

	printf("Randomly generate the grades of %d students:\n", n);
	for (int i = 0; i < n; i++) {
		printf("%-4d", p[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\nThe statistics of each score segment:");
	printf("\n[0,60): %d人", a[5]);
	printf("\n[60, 70): %d人", a[6]);
	printf("\n[70, 80): %d人", a[7]);
	printf("\n[80, 90): %d人", a[8]);
	printf("\n[90, 100]: %d人", a[9]);
	free(p);
	return 0;
}
