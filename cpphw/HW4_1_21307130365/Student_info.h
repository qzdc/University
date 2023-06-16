#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

class Student_info {
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
public:
	Student_info() :midterm(0), final(0) {};
	std::string name() const { return n; }
	std::istream& read(std::istream&);
	double grade() const;
	bool valid() const { return !homework.empty(); }
};

bool compare(const Student_info&, const Student_info&);
//std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif