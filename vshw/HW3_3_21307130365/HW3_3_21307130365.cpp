#include<stdio.h>
#include<math.h>
int main()
{
	/*
	S1������������
	S2�����ɶ���ñ߳�
	S3���������ߺʹ��ڵ������ж��Ƿ񹹳�������,������������������Ρ��������ǣ�����
	S4���ж��Ƿ�������ǣ������ж��Ƿ�ȱߡ��ǣ�������ȱߡ����������������������������
	S5���ж��Ƿ�ֱ�ǣ��ǣ������ֱ�ǡ�������
	S6������������Ρ�������
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