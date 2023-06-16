#include<iostream>

using std::cin;
using std::cout;

int main() {
	int n, m, a, x, p, y;
	cin >> a >> n >> m >> x;
	p = 0;

	int a1 = 1, a2 = 0, a3, a4 = 1, y1 = 0, y2 = 1, y3, y4 = 0;	
	for (int i = 0; i < n - 3; i++) {
		a4 += a1;
		y4 += y1;
		a3 = a2 + a1;
		a1 = a2;
		a2 = a3;
		y3 = y1 + y2;
		y1 = y2;
		y2 = y3; 
	}


	y = (m - a4 * a) / y4;

	
	if (x == 1) {
		cout << a;
	}
	else if (x == 2) {
		cout << p;
	}
	else {
		a1 = 1, a2 = 0, a3, a4 = 1, y1 = 0, y2 = 1, y3, y4 = 0;
		for (int i = 0; i < x - 2; i++) {
			a4 += a1;
			y4 += y1;
			a3 = a2 + a1;
			a1 = a2;
			a2 = a3;
			y3 = y1 + y2;
			y1 = y2;
			y2 = y3;
		}
		p = a4 * a + y4 * y;
	}
	cout << p;

	return 0;

}