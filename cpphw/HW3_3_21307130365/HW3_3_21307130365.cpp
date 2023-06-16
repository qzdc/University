#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
#include"HW3_3_21307130365.h"
#define N 10

using std::cout;
using std::string;
using std::vector;

int main() {
	srand((unsigned)time(NULL));
	vector<int> li;
	for (int i = 0; i < N; i++) {
		li.push_back(rand() % 100);
	}
	vector<int>::iterator bi = li.begin();
	vector<int>::iterator ei = li.end();
	cout << "the integer list:\n";
	output(bi, ei);
	cout << "the sum of the integer list:" << accumulate(bi, ei, 0);
	cout << "\nthe max element in the integer list: " << *max_element(bi, ei);
	cout << "\nthe min element in the integer list: " << *min_element(bi, ei);

	vector<double> ld;
	for (int i = 0; i < N; i++) {
		ld.push_back(1.0 * rand() / rand());
	}
	vector<double>::iterator bd = ld.begin();
	vector<double>::iterator ed = ld.end();
	cout << "\n\nthe double list:\n";
	output(bd, ed);
	cout << "the sum of the double list:" << accumulate(bd, ed, 0.0);
	cout << "\nthe max element in the double list: " << *max_element(bd, ed);
	cout << "\nthe min element in the double list: " << *min_element(bd, ed);

	vector<string> ls;
	string tab = "abcdefghijklmnopqrstuvwxyz";
	string word;
	string blank;
	for (int i = 0; i < N; i++) {
		word.clear();
		int j = rand() % 9 + 1;
		for (int k = 0; k < j; k++)
			word += tab[rand() % 26];
		ls.push_back(word);
	}
	vector<string>::iterator bs = ls.begin();
	vector<string>::iterator es = ls.end();
	cout << "\n\nthe string list:\n";
	output(bs, es);
	cout << "the concatenation of the string list:" << accumulate(bs, es, blank);
	cout << "\nthe max string in the string list: " << *max_element(bs, es);
	cout << "\nthe min string in the string list: " << *min_element(bs, es);

	return 0;
}