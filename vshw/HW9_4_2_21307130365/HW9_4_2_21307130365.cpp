#include<stdio.h>
#include<math.h>//Í¨¹ý²âÊÔ
void ni(int n) {
	static int rl = 1, pm = n;
	printf("Recursion Lever %d, parameter n = %d\n",rl, pm);
	if (n / 10 == 0) {
		printf("%d \n", n);
		printf("Recursion Lever %d return.\n", rl--);
	}
	else {
		rl++;
		pm /= 10;
		printf("%d \n", n % 10);
		ni(n / 10);
		printf("Recursion Lever %d return.\n", rl--);
	}
}
void zheng(int n) {
	int t, weishu =0, out;
	static int cishu = 1; 
	static int rl = 1, pm = n;
	for (t = n; t/10 != 0; t /= 10, weishu++);
	if (cishu == weishu + 1) {
		printf("Recursion Lever %d, parameter n = %d\n", cishu, pm);
	}
	else {
		printf("Recursion Lever %d, parameter n = %d\n", cishu, pm);
		pm /= 10;
		cishu++;
		zheng(n);
	}
	out = (int)(n / pow(10, cishu - 1)) % 10;
	printf("%d \n", out);
	printf("Recursion Lever %d return.\n", cishu--);
}
int main() {
	int n;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	printf("Output in normol order:\n");
	zheng(n);
	printf("\nOutput in reverse order:\n");
	ni(n);
}
