#include<stdio.h>//Í¨¹ı²âÊÔ
int f(int nian, int yue)
{
	return yue < 3 ? nian - 1 : nian;
}
int g(int yue)
{
	return yue < 3 ? yue + 13 : yue + 1;
}
int N(int nian, int yue, int ri)
{
	int x;
	x = 1461 * f(nian, yue) / 4 + 153 * g(yue) / 5 + ri;
	return x;
}
int d(int N) {
	return (N - 621049) % 7;
}
int main()
{
	int ts[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},
					    {31,29,31,30,31,30,31,31,30,31,30,31} };
	char a[12][4] = { "Jan","Feb","Mar","Apr","May","Jun",
					  "Jul","Aug","Sep","Oct","Nov","Dec" };
	char b[7][4] = { "Sun","Mon","Tue","Wed",
					 "Thu","Fri","Sat" };
	int nian, yue, ri = 1, leap, i, zhou, NN, D;
	printf("Please enter the year: ");
	scanf_s("%d", &nian);
	printf("The calendar for  is:\n", nian);
	leap = nian % 4 == 0 && nian % 100 || nian % 400 == 0;
	for (i = 0; i < 12; i++) {
		printf("\n\n");
		yue = i + 1;
		for (int j = 0; j < 3; j++) {
			printf("%c", a[i][j]);
		}
		printf(", %d\n", nian);
		for (int k = 0; k < 7; k++) {
			printf("  ");
			for (int l = 0; l < 3; l++) {
				printf("%c", b[k][l]);
			}
		}
		printf("\n");
		NN = N(nian, yue, ri);
		D = d(NN);
		for (int l = 0; l < D; l++) {
			printf("     ");
		}
		for (int l = 1; l <= ts[leap][i]; l++) {
			printf("%5d", l);
			if ((l + D) % 7 == 0) {
				printf("\n");
			}
		}
		printf("\n");
	}
}