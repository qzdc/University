#include<stdio.h>
#include<math.h>
int main()
{
	double a,x,sum;
	int i;
	printf("Enter x:");
	scanf("%lf", &x);
	if (x > 0) {
		for (i = 1, sum = 1.0, a = 1.0; 1; i++) {
			a = a * x / i;
			if (fabs(a) <= 1e-10)
				break;
			sum += a;
		}
		printf("e^(%g)=%-.15g", x, sum);
	}
	else {
		x *= -1;
		for (i = 1, sum = 1.0, a = 1.0; 1; i++) {
			a = a * x / i;
			if (fabs(a) <= 1e-10)
				break;
			sum += a;
		}
		sum = 1 / sum;
		x = -x;
		printf("e^(%g)=%-.15g", x, sum);
	}
	return 0;
}
