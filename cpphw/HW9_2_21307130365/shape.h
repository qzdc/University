#ifndef guard_shape
#define guard_shape

#include <vector>
#include <iostream>
#include <fstream>
#include<algorithm>

class shape {
	friend class Handle;
public:
	shape() :s(0) {};
	virtual ~shape() { };

	virtual void area() {}
	virtual double perimeter() const = 0;
	double getarea()const { return s; }
	virtual bool isvalid() const = 0;
	virtual std::ifstream& read(std::ifstream&) = 0;
	virtual void out() const = 0;
protected:
	virtual shape* clone() const = 0;
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
	bool isvalid() const;

	std::ifstream& read(std::ifstream& fin) {
		fin >> a >> b >> c;
		return fin;
	}
	void out() const {
		std::cout << a << ", " << b << ", " << c << ' ';
	}
	tri* clone()const { return new tri(*this); }
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
	rec* clone()const { return new rec(*this); }
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
	cir* clone()const { return new cir(*this); }
private:
	double a;
	static double pi;
};

#endif
