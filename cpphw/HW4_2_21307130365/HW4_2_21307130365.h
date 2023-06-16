#include<iostream>
class Date {
private:
	int n, y, r;
public:
	Date() :n(0), y(0), r(0) {};
	Date(int, int, int);
	Date(std::istream&);
	int nian()const { return n; }
	int yue()const { return y; }
	int ri()const { return r; }
	void dout() const;
	Date ripp() const;
	Date yuepp() const;
	Date nianpp() const;
	int isrun() const {
		return n % 400 == 0 || n % 100 != 0 && n % 4 == 0 ? 1 : 0;
	};
	int valid() const;
};

int interval(Date&, Date&);

int a[][12]= { {31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31} };

Date::Date(int nian, int yue, int ri) {
	n = nian;
	y = yue;
	r = ri;
}
Date::Date(std::istream& is) {
	std::cin >> n >> y >> r;
}
void Date::dout() const {
	std::cout << n << "Äê" << y << "ÔÂ" << r << "ÈÕ\n";
}
Date Date::ripp() const{
	int i = isrun();
	int r0 = r, y0 = y, n0 = n;
	r0++;
	if (r0 > a[i][y - 1]) {
		r0 = 1;
		y0++;
		if (y0 > 12) {
			y0 = 1;
			n0++;
		}
	}
	Date ret(n0, y0, r0);
	return ret;
}

Date Date::yuepp() const{
	int i = isrun();
	int r0 = r, y0 = y, n0 = n;
	y0++;
	if (r0 > a[i][y0 - 1]) {
		r0 = a[i][y0 - 1];
	}
	if (y0 > 12) {
		y0 = 1;
		n0++;
	}
	Date ret(n0, y0, r0);
	return ret;
}

Date Date::nianpp() const{
	int r0 = r, y0 = y, n0 = n;
	n0++;
	int i = n0 % 400 == 0 || n0 % 100 != 0 && n0 % 4 == 0 ? 1 : 0;
	if (r0 > a[i][y0 - 1]) {
		r0 = a[i][y0 - 1];
		if (y0 > 12) {
			y0 = 1;
			n0++;
		}
	}
	Date ret(n0, y0, r0);
	return ret;
}

int Date::valid() const {
	int i = isrun();
	return y < 13 && y > 0 && n > 0 && r > 0 && r <= a[i][y - 1] ? 1 : 0;
}