#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main() {
	string a, b, c, t;
	cout << "Enter 3 English words: ";
	cin >> a >> b >> c;
	
	if (a.compare(b) > 0) {
		t = a;
		a = b;
		b = t;
	}
	if (b.compare(c) > 0) {
		t = b;
		b = c;
		c = t;
	}
	if (a.compare(b) > 0) {
		t = a;
		a = b;
		b = t;
	}

	cout << a << ' ' << b << ' ' << c;
	return 0;
}