#include<iostream>
#include"HW4_2_21307130365.h"

using std::cout;
using std::cin;

int main() {
	cout << "�������������ڣ������գ��Կո�ָ���\n";
	Date d1(cin);
	if (!d1.valid()) {
		cout << "invalid day";
		return 0;
	}
	Date d2(cin); 
	if (!d2.valid()) {
		cout << "invalid day";
		return 0;
	}
	
	cout << "����һ��";
	d1.dout();
	cout << "���ڶ���";
	d2.dout();
	cout << "���������������Ϊ��" << interval(d1, d2);
	Date d;
	d = d1.ripp();
	cout << "\n������һ����һ��Ϊ��";
	d.dout();
	d = d1.yuepp();
	cout << "������һ����һ��Ϊ��";
	d.dout();
	d = d1.nianpp();
	cout << "������һ����һ��Ϊ��";
	d.dout();
	return 0;
}

int interval(Date& d1, Date& d2) {
	int t = 0;
	Date d3, d4;
	if (d1.nian() > d2.nian()) {
		d3 = d2;
		d4 = d1;
	}
	else if (d1.nian() < d2.nian()) {
		d3 = d1;
		d4 = d2;
	}
	else {
		if (d1.yue() > d2.yue()) {
			d3 = d2;
			d4 = d1;
		}
		else if (d1.yue() < d2.yue()) {
			d3 = d1;
			d4 = d2;
		}
		else {
			if (d1.ri() > d2.ri()) {
				d3 = d2;
				d4 = d1;
			}
			else if (d1.ri() < d2.ri()) {
				d3 = d1;
				d4 = d2;
			}
		}
	}

	int n3 = d3.nian(), n4 = d4.nian();
	int y3 = d3.yue(), y4 = d4.yue();
	while (n3 != n4) {
		int i = n3 % 400 == 0 || n3 % 100 != 0 && n3 % 4 == 0 ? 1 : 0;
		while (y3 <= 12) {
			t += a[i][y3 - 1];
			y3++;
		}
		y3 = 1;
		n3++;
	}
	int i = n3 % 400 == 0 || n3 % 100 != 0 && n3 % 4 == 0 ? 1 : 0;
	while (y3 != y4) {
		t += a[i][y3 - 1];
		y3++;
	}
	t = t + d4.ri() - d3.ri();
	return t;
}
