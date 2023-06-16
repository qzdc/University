#include "shape.h"

bool tri::isvalid() const {
	if (a < 0 || b < 0 || c < 0)
		return false;
	if (a + b <= c || a + c <= b || b + c <= a)
		return false;
	return true;
}

double cir::pi = 3.1415926;
