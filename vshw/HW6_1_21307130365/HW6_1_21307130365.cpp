#include<stdio.h>
#include<math.h>
int main()
{
	double pi;
	long i, flag, n = 1;
	for (i = 1, flag = 1, pi = 0.0; 1; i++) {
		pi = pi + flag * 4.0 / (2 * i - 1);
		flag *= -1;
		if (((int)(1000000 * pi - 3140000) == 0) && pi > 3.14 && n == 1) {
			printf("After %d interactions,3.14 is got.\n", i);
			n = 2;
		}
		if ((int)(1000000 * pi - 3141000) == 0 && pi > 3.141 && n == 2) {
			printf("After %d interactions,3.141 is got.\n", i);
			n = 3;
		}
		if ((int)(1000000 * pi - 3141500) == 0 && pi > 3.1415 && n == 3) {
			printf("After %d interactions,3.1415 is got.\n", i);
			n = 4;
		}
		if ((int)(1000000 * pi - 3141590) == 0 && pi > 3.14159 && n == 4) {
			printf("After %d interactions,3.14159 is got.\n", i);
			break;
		}
	}
	return 0;

}