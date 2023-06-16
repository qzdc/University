#include<stdio.h>
#include<math.h>
int main()
{
	int a,i,j,weishu,b=0,c=0;
	printf("Enter an integer:");
	scanf("%d",&a);
	for(i=1;a/pow(10,i)>=1;i++);
	weishu=i;
	for(;i>0;i--){
		b=a%10;
		c+=pow(10,i-1)*b;
		a/=10;
	}
	printf("The reversal is:");
	printf("%d",c);
	return 0;
}
