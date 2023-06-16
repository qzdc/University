#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include <fstream>
#include "Vec.h"

class Student_info {
private:
	std::string n;
	double midterm, final;
	Vec<double> homework;
public:
	Student_info() :midterm(0), final(0) {};
	explicit Student_info(std::ifstream& in) { read(in); }
	std::string name() const { return n; }
	std::ifstream& read(std::ifstream&);
	double grade() const;
	bool valid() const { return !homework.empty(); }
};

bool compare(const Student_info&, const Student_info&);
//std::istream& read(std::istream&, Student_info&);
std::ifstream& read_hw(std::ifstream&, Vec<double>&);
#endif