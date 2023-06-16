#include<iostream>
#include<string>
//all test samples have passed

using std::cout;
using std::cin;
using std::endl;

int main() {
	int x, y;

	cout << "Enter the side length of a square: ";
	cin >> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cout << "* ";
		}
		cout << endl;
	}

	cout << "Enter the length and width of a rectangle: ";
	cin >> y >> x;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "* ";
		}
		cout << endl;
	}

	cout << "Enter the base length of a isosceles triangle(odd number): ";
	cin >> y;
	x = y / 2 + 1;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x - 1 - i; j++) 
			cout << "  ";
		for (int j = 0; j < i * 2 + 1; j++)
			cout << "* ";
		cout << endl;
	}

	return 0;
}