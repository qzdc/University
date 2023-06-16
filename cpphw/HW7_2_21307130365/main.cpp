#include "Str.h"
#include <algorithm>

struct elemt {
	Str word;
	int frec;
};
bool compare(const elemt& a, const elemt& b);
bool comp(const Str& a, const Str& b);

using std::cin;
using std::cout;
using std::sort;

int main() {
	Vec<elemt> sent;
	Str temp;
	while (cin >> temp) {
		elemt newelemt = { temp, 1 };
		sent.push_back(newelemt);
	}
	//const elemt* b = words.begin(), * e = words.end();
	sort(sent.begin(), sent.end(), compare);
	return 0;
}

bool compare(elemt& a, elemt& b) {
	return comp(a.word, b.word);
}

bool comp(const Str& a, const Str& b) {
	Str::size_type i = 0;
	for (Str::size_type na = a.size(), nb = b.size();
		i < na && i < nb && a[i] == b[i]; i++);
	return a[i] < b[i];
}