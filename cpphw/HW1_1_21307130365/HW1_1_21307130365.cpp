#include<iostream>
#include<string>
//all test samples have passed

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

	cout << "please enter you first name: " ;
	string name;
	cin >> name;
	cout << "please enter the number of the blanks surrounding the greeting: ";
	int l;
	cin >> l;

	string greet = "hello " + name + " !";
	int x0 = l * 2 + 3;
	int y0 = greet.size() + 2 * l + 2;

	cout << endl;
	for (int x = 0, y = 0; x < x0; ) {
		if (x == 0 || x == x0 - 1 || y == 0 || y == y0 - 1) {
			cout << "*";
			y++;
		}
		else if (x == l + 1 && y == l + 1) {
			cout << greet;
			y += greet.size();
		}
		else {
			cout << " ";
			y++;
		}

		if (y == y0) {
			cout << endl;
			x++;
			y = 0;
		}
	}

	return 0;
}