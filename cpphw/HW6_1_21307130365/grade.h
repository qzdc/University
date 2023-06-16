#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include "Vec.h"

double grade(double, double, double);
double grade(double, double, const Vec<double>&);
int letter_grade(double);
static const char* const tab[] = { "A", "A-", "B+", 
	"B", "B-", "C+", "C", "C-", "D", "F" };

#endif

