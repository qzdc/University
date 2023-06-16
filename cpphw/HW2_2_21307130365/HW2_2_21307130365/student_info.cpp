#include"student_info.h"

std::istream& read(std::istream& in, stdif& std) {
	in >> std.name >> std.mid >> std.fin;
	readhw(in, std.homework);
	return in;
}

std::istream& readhw(std::istream& in, std::vector<double>& hw) {
	if (in) {
		hw.clear();
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

bool compare(const stdif& a, const stdif& b) {
	return a.zong > b.zong;
}