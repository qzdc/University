// source file for 'Student_info'-related functions
#include "Student_info.h"

using std::ifstream;  using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

ifstream& Student_info::read(ifstream& in)
{
	// read and store the student's name and midterm and final exam grades
	in >> n >> midterm >> final;

	read_hw(in, homework);  // read and store all the student's homework grades
	return in;
}

// read homework grades from an input stream into a 'vector<double>'
ifstream& read_hw(ifstream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}