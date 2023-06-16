#ifndef guard_handle
#define guard_handle

#include "grad.h"
#include <stdexcept> 

class student_info {
public:
	student_info() : cp(0) {};
	student_info(std::ifstream& is) { read (is); }
	~student_info() { delete cp; }
	std::ifstream& read(std::ifstream&);

	student_info& operator=(const student_info&);
	student_info(const student_info&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}
	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const student_info s1,const student_info s2) {
		return s1.name() < s2.name();
	}
private:
	Core* cp;
};

#endif
