#include<stdio.h>
#include<math.h>
int main()
{
	float high = 3.0, low = 0.0, m, fh, fl, fm;
	printf("[low,high]\t\tmid\t\tf_low\t\tf_high\t\tf_mid\n");
	while (fabs(high - low) > pow(10, -6)) {
		m = (high + low) / 2.0;
		fh = high * high * high - high * high - 1;
		fl = low * low * low - low * low - 1;
		fm = m * m * m - m * m - 1;
		printf("[%f,%f]\t%f\t%f\t%f\t%f\n", low, high, m, fl, fh, fm);
		fm* fl >= 0 ? low = m : high = m;
	}
	printf("函数f(x)=x^3-x^2-1在区间[0,3]上的实根为%f", m);
	return 0;
}