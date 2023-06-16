#include "core.h"

using std::vector; 
using std::domain_error;

std::ifstream& Core::read(std::ifstream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

std::ifstream& Core::read_common(std::ifstream& in) {
	in >> n >> midterm >> final;
	return in;
}

std::ifstream& read_hw(std::ifstream& in, vector<double>& hw) {
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw.begin(), hw.end()));
}

double Core::grade() const
{
	return ::grade(midterm, final, homework);
}
