#ifndef guard_core
#define guard_core


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include "median.h"

class Core {
	friend class student_info;
public:
	Core() :midterm(0), final(0) {};
	explicit Core(std::ifstream& is) { read(is); }
	~Core() {};

	std::string name() const { return n; }
	virtual std::ifstream& read(std::ifstream&);
	virtual double grade() const;
protected:
	virtual Core* clone() const { return new Core(*this); }
	std::ifstream& read_common(std::ifstream&);
	std::vector<double> homework;
	double midterm, final;
private:
	std::string n;
};

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::ifstream& read_hw(std::ifstream&, std::vector<double>&);

#endif
