#ifndef guard_grad
#define guard_grad

#include "core.h"

class Grad :public Core {
public:
	Grad() : thesis(0) {};
	Grad(std::ifstream& in) { read(in); }
	double grade()const;
	std::ifstream& read(std::ifstream&);
	virtual Grad* clone() const { return new Grad(*this); }
private:
	double thesis;
};

bool compare(const Core*, const Core*);

#endif
