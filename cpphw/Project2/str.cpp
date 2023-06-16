#include "Str.h"

std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0, n = s.size(); i < n; i++)
		os << s[i];
	return os;
}
std::istream& operator>>(std::istream& is, Str& s) {
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
Str operator+(const Str& s1, const Str& s2) {
	Str r = s1;
	r += s2;
	return r;
}

bool comp(const Str& a, const Str& b) {
	Str::size_type i = 0;
	for (Str::size_type na = a.size(), nb = b.size();
		i < na && i < nb && a[i] == b[i]; i++);
	return a[i] < b[i];
}

bool isequ(const Str& a, const Str& b) {
	int f = 1;
	if (a.size() != b.size()) {
		return 0;
	}
	Str::size_type size = a.size();
	for (Str::size_type i = 0; i < size; i++)
		if (a[i] != b[i])
			f = 0;
	return f;
}