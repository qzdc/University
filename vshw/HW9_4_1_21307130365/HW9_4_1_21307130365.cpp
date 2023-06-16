#include<stdio.h>
#include<math.h>
void ni(int n) {
	if (n / 10 == 0) {
		printf("%d ", n);
	}
	else {
		printf("%d ", n % 10);
		ni(n / 10);
	}
}
void zheng(int n) {
	int t, weishu = 0, out;
	static int cishu = 1;
	for (t = n; t / 10 != 0; t /= 10, weishu++);
	if (cishu == weishu + 1) {
		printf("%d ", n % 10);
	}
	else {
		out = (int)(n / pow(10, weishu + 1 - cishu)) % 10;
		printf("%d ", out);
		cishu++;
		zheng(n);
	}
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
