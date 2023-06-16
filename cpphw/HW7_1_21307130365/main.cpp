#include"Str.h"


//using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

	cout << "please enter you first name: " ;
	Str name;
	cin >> name;
	cout << "please enter the number of the blanks surrounding the greeting: ";
	int l;
	cin >> l;

	Str greet = "Hello, " + name + "!";
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

	cout << "逐个字符输出greeting(字符之间以空格分隔)：\n";
	Str::size_type n = greet.size();
	for (int i = 0; i < n; i++)
		cout << greet[i] << ' ';
	return 0;
}