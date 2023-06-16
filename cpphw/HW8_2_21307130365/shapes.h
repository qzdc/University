#include <vector>
#include <iostream>
#include <fstream>
#include<algorithm>
#define pi 3.1415926
//每个派生类的函数体都比较简单，就都在类的内部实现了。
class shape {
public:
	shape() :s(0) {};
	~shape() {};
	virtual void area() = 0;
	virtual double perimeter() const = 0;
	virtual bool isvalid() const = 0;
	virtual std::ifstream& read(std::ifstream&) = 0;
	virtual void out() const = 0;
	virtual double getarea()const { return s; }
protected:
	double s;
};

inline bool comp(shape* a, shape* b) {
	return a->getarea() < b->getarea();
}

class tri :public shape {
public:
	tri() :a(0), b(0), c(0) {};
	explicit tri(std::ifstream& fin) {
		fin >> a >> b >> c;
	}
	void area() {
		double l = (a + b + c) / 2.0;
		s = std::sqrt(l * (l - a) * (l - b) * (l - c));
	}
	double perimeter() const {
		return 1.0 * a + b + c;
	}
	bool isvalid() const {
		if (a < 0 || b < 0 || c < 0)
			return false;
		if (a + b <= c || a + c <= b || b + c <= a)
			return false;
		return true;
	}

	std::ifstream& read(std::ifstream& fin) {
		fin >> a >> b >> c;
		return fin;
	}
	void out() const {
		std::cout << a << ", " << b << ", " << c << ' ';
	}
private:
	double a, b, c;
};

class rec :public shape {
public:
	rec() :a(0), b(0) {};
	explicit rec(std::ifstream& fin) {
		fin >> a >> b;
	}
	void area()  {
		s = 1.0 * a * b;
	}
	double perimeter() const {
		return 2.0 * a + 2.0 * b;
	}
	bool isvalid() const {
		return a > 0 && b > 0;
	}

	std::ifstream& read(std::ifstream& fin) {
		fin >> a >> b;
		return fin;
	}
	void out() const {
		std::cout << a << ", " << b <<' ';
	}
private:
	double a, b;
};

class cir :public shape {
public:
	cir() :a(0) {};
	explicit cir(std::ifstream& fin) {
		fin >> a;
	}
	void area() {
		s = pi * a * a;
	}
	double perimeter() const {
		return 2.0 * pi * a;
	}
	bool isvalid() const {
		return a > 0;
	}

	std::ifstream& read(std::ifstream& fin) {
		fin >> a;
		return fin;
	}
	void out() const {
		std::cout << a << " ";
	}
private:
	double a;
};
