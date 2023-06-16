#include<iostream>
#include"HW3_2_21307130365.h"
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
#include<string>

using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::string;

int main() {
	vector<int> v1, v2, vt;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 13; i++) {
		v1.push_back(rand() % 21);//[0,20]
	}
	for (int i = 0; i < 13; i++) {
		v2.push_back(rand() % 21);//[0,20]
	}
	vt = v1;
	vector<int>::iterator b1 = v1.begin();
	vector<int>::iterator e1 = v1.end();
	vector<int>::iterator b2 = v2.begin();
	vector<int>::iterator e2 = v2.end();
	vector<int>::iterator b3 = vt.begin();
	vector<int>::iterator e3 = findcom(b1, e1, b2, e2, b3);
	cout << "Random integer vector 1:\n";
	out(b1, e1);
	cout << "\nRandom integer vector 1:\n";
	out(b2, e2);
	cout << "\nVector in common:\n";
	out(b3, e3);

	cout << "\nEnter some words for string list 1:\n";
	list<string> l1, l2, lt;
	string s;
	while (cin >> s) {
		l1.push_back(s);
	}
	cin.clear();
	cout << "Enter some words for string list 2:\n";
	while (cin >> s) {
		l2.push_back(s);
	}
	cin.clear();
	lt = l1;
	list<string>::iterator lb1 = l1.begin();
	list<string>::iterator le1 = l1.end();
	list<string>::iterator lb2 = l2.begin();
	list<string>::iterator le2 = l2.end();
	list<string>::iterator lb3 = lt.begin();
	list<string>::iterator le3 = findcom(lb1, le1, lb2, le2, lb3);
	cout << "List in common:\n";
	out(lb3, le3);

	return 0;
}