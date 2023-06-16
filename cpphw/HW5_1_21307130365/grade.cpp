#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <cmath>

using std::domain_error;  using std::vector;


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw.begin(),hw.end()));
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

int letter_grade(double n) {
	if (n < 100 && n > 90 || fabs(n - 100.0) < 1e-6 || fabs(n - 90.0) < 1e-6)
		return 0;
	else if (n > 85 || fabs(n - 85.0) < 1e-6)
		return 1;
	else if (n > 82 || fabs(n - 82.0) < 1e-6)
		return 2;
	else if (n > 78 || fabs(n - 78.0) < 1e-6)
		return 3;
	else if (n > 75 || fabs(n - 75.0) < 1e-6)
		return 4;
	else if (n > 71 || fabs(n - 71.0) < 1e-6)
		return 5;
	else if (n > 66 || fabs(n - 66.0) < 1e-6)
		return 6;
	else if (n > 62 || fabs(n - 62.0) < 1e-6)
		return 7;
	else if (n > 60 || fabs(n - 60.0) < 1e-6)
		return 8;
	else 
		return 9;

}
