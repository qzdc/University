#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::istream;
using std::domain_error;

struct sent {
	int x;
	string word;
};
typedef vector<sent> ::size_type vecsz;

string::size_type kick(string& s) {
	string::size_type l = s.size();
	for (int i = 0; i < l; i++) {
		char a = s[i];
		if (a <= 'z' && a >= 'a' || a <= 'Z' && a >= 'A');
		else {
			for (int j = i; j < l; j++) {
				s[j] = s[j + 1];
			}
			l--;
			i--;
		}
	}
	return l;
}

istream& inwords(istream& in, vector<sent>& s) {
	if (in) {
		s.clear();
		sent a;
		string w;
		while (cin >> w) {
			/*if (kick(w)) {
				a.word = w;
				a.x = 1;
				s.push_back(a);
			}*/
			a.word = w;
			a.x = 1;
			s.push_back(a);
		}
	}
	in.clear();
	if (s.size() == 0) {
		throw domain_error("empty");
	}
	return in;
}

void lower(string& a) {
	string::size_type l = a.size();
	for (int i = 0; i < l; i++) {
		if (a[i] <= 'Z' && a[i] >= 'A')
			a[i] += 'a' - 'A';
	}
}

bool compare(const sent& a, const sent& b) {
	string aw = a.word, bw = b.word;
	lower(aw);
	lower(bw);
	return aw < bw;
}

vecsz frec(vector<sent>& p) {
	//vector<sent> p;
	vecsz l = p.size();
	//p = s;
	sort(p.begin(), p.end(), compare);
	for (int i = 0; i < l - 1; i++) {
		for (int j = i + 1; j < l; j++) {
			string aw = p[i].word, bw = p[j].word;
			lower(aw);
			lower(bw);
			if (aw == bw) {
				p[i].x++;
				for (int k = j; k < l - 1; k++) {
					p[k] = p[k + 1];
				}
				l--;
			}
			else break;
		}
	}
	return l;
}

void pri(vector<sent>& s, vecsz& l) {
	vecsz n = 0;
	for (int i = 0; i < l; i++)
		n += s[i].x;
	cout << "number of the words: " << n << endl;
	string::size_type max = 0;
	for (int i = 0; i < l; i++) {
		if (s[i].word.size() > max)
			max = s[i].word.size();
	}
	for (int i = 0; i < l; i++) {
		string blank(max - s[i].word.size() + 1, ' ');
		cout << s[i].word << blank << s[i].x <<endl;
	}
}

int main() {
	vector<sent> s;
	cout << "Enter some English words: \n";
	try {
		inwords(cin, s);
		vecsz l = frec(s);
		pri(s, l);
	}
	catch (domain_error) {
		cout << "No words entered. Please try again!";
		return 1;
	}
	return 0;
}
