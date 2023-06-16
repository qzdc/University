#include "grad.h"

using std::ifstream;

ifstream& Grad::read(ifstream& in) {
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	return std::min(Core::grade(), thesis);
}

bool compare(const Core* c1, const Core* c2) {
	return c1->name() < c2->name();
};