#include<stdio.h>
int main()
{
	float loan, pay,yrate,mrate,f,s,t;
	printf("Enter amount of loan:");
	scanf_s("%f",&loan);
	printf("Enter interest rate:");
	scanf_s("%f", &yrate);
	printf("Enter monthly payment:");
	scanf_s("%f", &pay);
	mrate = yrate / 12.0;
	f = loan * (1+0.01 * mrate) - pay;
	s = f * (1 + 0.01 * mrate) - pay;
	t = s * (1 + 0.01 * mrate) - pay;
	printf("Banlance remaining after 1st payment:  $%8.2f\n", f);
	printf("Banlance remaining after 2nd payment:  $%8.2f\n", s);
	printf("Banlance remaining after 3rd payment:  $%8.2f\n", t);
	return 0;
}