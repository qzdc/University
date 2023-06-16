#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n,base;
	cin >> n >> base;
	string tab = "0123456789ABCDEF";
	int x;
	vector<int> num;
	while(n) {
		x = n % base;
		n /= base;
		if (x < 0) {
			n++;
			x -= base;
		}
			
		num.push_back(x);
	}

	for (int i = num.size() - 1; i >= 0; i--)
		cout << tab[num[i]];

	return 0;
}