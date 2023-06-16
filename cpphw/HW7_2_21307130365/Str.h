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

inline std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0, n = s.size(); i < n; i++)
		os << s[i];
	return os;
}
inline std::istream& operator>>(std::istream& is, Str& s) {
	s.data.clear();
	char c;
	while (is.get(c) && isspace(c));

	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));
		if (is)
			is.unget();
	}

	return is;
}
inline Str operator+(const Str& s1, const Str& s2) {
	Str r = s1;
	r += s2;
	return r;
}

inline bool compare(const Str& a, const Str& b) {
	Str::size_type i = 0;
	for (Str::size_type na = a.size(), nb = b.size();
		i < na && i < nb && a[i] == b[i]; i++);
	return a[i] < b[i];
}

#endif