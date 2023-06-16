#include "handle.h"

std::ifstream& student_info::read(std::ifstream& in)
{
	delete cp;
	char ch;
	Core newcore;
	in >> ch;
	if (ch == 'U')
		cp = new Core(in);
	else
		cp = new Grad(in);
	return in;
}

student_info::student_info(const student_info& s):cp(0) {
	if (s.cp) cp = s.cp->clone();
}

student_info& student_info::operator=(const student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else cp = 0;
	}
	return *this;
}