#include "Str.h"
#include <algorithm>

struct elemt {
	Str word;
	int frec;
};

bool compare(const elemt a, const elemt b) {
	return comp(a.word, b.word);
}

using std::cin;
using std::cout;
using std::sort;

int main() {
	Vec<elemt> sent;
	Str temp;
	Str::size_type maxlen = 0;
	cout << "Enter some text: ";
	while (cin >> temp) {
		if (temp.size() > maxlen)
			maxlen = temp.size();
		elemt newelemt = { temp, 1 };
		sent.push_back(newelemt);
	}
	maxlen++;

	sort(sent.begin(), sent.end(), compare);

	Vec<elemt>::size_type size = sent.size();
	Vec<elemt> target;
	for (Vec<elemt>::size_type i = 0; i < size; i++) {
		int times = 1;
		while (isequ(sent[i].word, sent[i + 1].word) && i != size) {
			i++;
			times++;
		}
		elemt newelemt = { sent[i].word, times };
		target.push_back(newelemt);
	}

	size = target.size();
	for (Vec<elemt>::size_type i = 0; i < size; i++) {
		Str blank(maxlen - target[i].word.size(), ' ');
		cout << target[i].word << blank << target[i].frec << '\n';
	}
	
	return 0;
}