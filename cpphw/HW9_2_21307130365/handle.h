#ifndef guard_handle
#define guard_handle

#include "shape.h"

class Handle {
	friend std::ifstream& readinfo(std::ifstream&, std::vector<Handle>&);
	friend bool compare(const Handle&, const Handle&);
public:
	Handle() :p(0) {};
	~Handle() { delete p; }
	Handle(std::ifstream& in):p(0) { read(in); }
	std::ifstream& read(std::ifstream&);

	double area() const { return p->getarea(); }
	double perimeter() const { return p->perimeter(); }

	Handle (const Handle& h) : p(0) {
		if (h.p) p = h.p->clone();
	}
	Handle& operator=(const Handle&);

	void clear() { delete p; }

	static bool comp(const Handle& a,const Handle& b){
		return a.p->getarea() < b.p->getarea();
	}
private:
	shape* p;
};

inline bool compare(const Handle& a, const Handle& b) {
	return Handle::comp(a, b);
}
void cal_output(std::vector<Handle>&);
#endif