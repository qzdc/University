#include<stdio.h>
#include<math.h>
int main()
{
	/*
	S1：输入三坐标
	S2：勾股定理得边长
	S3：三次两边和大于第三边判断是否构成三角形,否，输出“不构成三角形”结束；是，继续
	S4：判断是否等腰，是，继续判断是否等边。是，输出“等边”，继续，否，输出“等腰”，继续
	S5：判断是否直角，是，输出“直角”，继续
	S6：输出“三角形”，结束
	*/
	float x1, y1, x2, y2, x3, y3, a, b, c;
	printf("Enter 3 couples of coordinates: ");
	scanf_s("(%f,%f) (%f,%f) (%f,%f)", &x1, &y1, &x2, &y2, &x3, &y3);
	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	if (a + b <= c || b + c <= a || a + c <= b)
		printf("Can not make a triangle");
	else {
		if (fabs(a - b) < 1e-6 || fabs(c - b) < 1e-6 || fabs(a - c) < 1e-6) {
			if (fabs(a - b) < 1e-6 && fabs(c - b) < 1e-6 && fabs(a - c) < 1e-6)
				printf("Equilateral ");
			else printf("Isosceles ");
		}
		if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(c * c + b * b - a * a) < 1e-6)
			printf("Right ");
		printf("triangle");
	}
	return 0;
}