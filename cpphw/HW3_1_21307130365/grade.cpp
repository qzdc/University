#include"grade.h"
#include"median.h"

double grade(double mid, double fin, std::list<double>& hw) {
	return grade(mid, fin, median(hw));
}
double grade(stdif& std) {
	return grade(std.mid, std.fin, std.homework);
}

