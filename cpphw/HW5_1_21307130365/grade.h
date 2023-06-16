#ifndef GUARD_grade_h
#define GUARD_grade_h

// 'grade.h'
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
int letter_grade(double);
static const char* const tab[] = { "A", "A-", "B+", 
	"B", "B-", "C+", "C", "C-", "D", "F" };

#endif

