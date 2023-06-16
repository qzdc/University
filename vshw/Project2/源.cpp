#include<stdio.h>
/*100-day program*/
int main() {
	int a[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31} };
	int judge = 0;
	int year, mon, day;
	int d1, d2, i, j;
	printf("please enter the baby's birthday:\n");
	scanf_s("%d-%d-%d", &year, &mon, &day);
	i = year % 400 == 0 || year % 100 != 0 && year % 4 == 0 ? 1 : 0;
	d1 = d2 = 0;
	for (j = 0; j < mon - 1; j++) {
		d1 += a[i][j];
	}
	d1 += day;

	d2 = d1 + 100;

	if (d2 < 365 + i) {
		for (j = 0; d2 > 0; j++) {
			d2 -= a[i][j];
		}
		mon = j;
		day = a[i][j-1] + d2;
	}
	else {
		d2 -= 365 + i;
		year++;
		for (j = 0; d2 > 0; j++) {
			d2 -= a[i][j];
		}
		mon = j;
		day = a[i][j-1] + d2;
	}

	printf("the baby's 100-day date is:\n%d-%d-%d", year, mon, day);

	return 0;

}