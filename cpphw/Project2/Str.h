#ifndef guard_string
#define guard_string

#include "Vec.h"
#include<iostream>

class Str {
	friend std::istream& operator>>(std::istream&, Str&);
public:
	typedef Vec<char>::size_type size_type;
	Str() :data() {};
	Str(size_type n, char c) :data(n, c) {};
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}
	template <class IN>
	Str(IN b, IN e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const{ return data[i]; }
	const size_type size() const { return data.size(); }

	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

private:
	Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
std::istream& operator>>(std::istream&, Str&);
Str operator+(const Str&, const Str&);
bool comp(const Str&, const Str&);
bool isequ(const Str&, const Str&);

#endif