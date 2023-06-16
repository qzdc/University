#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;

typedef vector<int>::size_type vecsz;

//b加至a
void plus(vector<int>& a, const vector<int>& b) {
	vecsz la = a.size(), lb = b.size();
	if (a[la - 1] != 0) {
		a.push_back(0);
		la++;
	}
	for (int j = 0; j < lb; j++) {
		if (a[la - 1] != 0) {
			a.push_back(0);
			la++;
		}
		int jin = 0;
		for (int x = la - 1; x < j; x++) {
			a.push_back(0);
			la++;
		}
		a[j] += b[j];
		if (a[j] > 9) {
			jin = a[j] / 10;
			for (int i = j + 1; jin > 0; i++) {
				if (a[la - 1] != 0) {
					a.push_back(0);
					la++;
				}
				a[i] += jin;
				a[i - 1] = a[i - 1] % 10;
				jin = a[i] / 10;
			}
		}
	}
}
//b乘以a，结果变为a
void mul(vector<int>& a, const vector<int>& b) {
	vector<int> c;
	c.push_back(0);
	vecsz la = a.size(), lb = b.size(),lc = c.size();
	if (c[lc - 1] != 0) {
		c.push_back(0);
		lc++;
	}
	for (int j = 0; j < lb; j++) {
		for (int i = 0; i < la; i++) {
			if (c[lc - 1] != 0) {
				c.push_back(0);
				lc++;
			}
			for (int x = lc - 1; x < i + j; x++) {
				c.push_back(0);
				lc++;
			}
			c[i + j] += a[i] * b[j];
			int jin = c[i + j] / 10;
			for (int k = i + 1 + j; jin > 0; k++) {
				lc = c.size();
				if (c[lc - 1] != 0) {
					c.push_back(0);
					lc++;
				}
				c[k] += jin;
				c[k - 1] = c[k - 1] % 10;
				jin = c[k] / 10;
			}
		}
	}
	a = c;
}

int main() {
	vector<int> num, a, b;
	int n;
	cout << "enter n(1<=n<=50): ";
	cin >> n;
	a.push_back(1);
	num.push_back(0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			b.clear();
			b.push_back(j % 10);
			if (j / 10)
				b.push_back(j / 10);
			mul(a, b);
		}
		plus(num, a);
		a.clear();
		a.push_back(1);
	}

	cout << "1!";
	for (int i = 2; i <= n; i++)
		cout << '+' << i << '!';
	cout << '=';
	int l;
	for (l = num.size() - 1; num[l] == 0; l--);
	for (int i = l; i >= 0; i--)
		cout << num[i];
	return 0;
}