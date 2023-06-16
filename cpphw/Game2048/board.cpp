#include"borad.h"

void board::ini() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = 0;
		}
	}
	srand((unsigned)time(NULL));
	int i1 = rand() % 4, j1 = rand() % 4;
	int i2 = rand() % 4, j2 = rand() % 4;
	while (i1 == i2 && j1 == j2); {
		i2 = rand() % 4;
		j2 = rand() % 4;
	}
	a[i1][j1] = 2;
	a[i2][j2] = 2;
}
//上下左右——1234
void board::print() const {
	std::string frame = (4, "|-----");
	frame += '|';
	std::string vacc(5, ' ');
	for (int i = 0; i < 9; i++) {
		if (i % 2) {
			int j = i / 2;
			for (int k = 0; k < 4; k++) {
				std::cout << '|';
				if (a[i][j])
					std::cout << ' ' << a[i][j];
				else
					std::cout << vacc;
			}
			std::cout << '|';
		}
		else
			std::cout << frame;
	}
}

void board::place() {
	srand((unsigned)time(NULL));
	int i = rand() % 4, j = rand() % 4;
	while (a[i][j] != 0) {
		i = rand() % 4;
		j = rand() % 4;
	}
	a[i][j] = rand() % 5 ? 4 : 2;
}

void board::reverse(int i) {
	int t;
	if (i) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				t = a[j][k];
				a[j][k] = a[j][3 - k];
				a[j][3 - k] = t;
			}
		}

	}
	else {
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 2; j++) {
				t = a[j][k];
				a[j][k] = a[3 - j][k];
				a[3 - j][k] = t;
			}
		}
	}
}
//i=1,左右；i=0;上下
void board::move(int i) {
	if (i % 2) {
		if (i == 1) {
			for (int k = 0; k < 4; k++) {
				for (int j = 0; j < 4; j++) {
					if (a[j][k] == 0) {
						for (int l = j; l < 3; l++)
							a[l][k] = a[l + 1][k];
						a[4][k] = 0;
					}
				}
			}
		}
		if (i == 3) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (a[j][k] == 0) {
						for (int l = k; l < 3; l++)
							a[j][l] = a[j][l + 1];
						a[j][4] = 0;
					}
				}
			}
		}
		combine(i);
	}
	else {
		reverse(i / 2 - 1);
		move(i - 1);
		reverse(i / 2 - 1);
	}
}

void board::combine(int i) {
	if (i == 1) {
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 3; j++) {
				if (a[j][k] == a[j + 1][k]) {
					s += a[j][k];
					a[j][k] *= 2;
					for (int l = j + 1; l < 3; l++)
						a[l][k] = a[l + 1][k];
					a[4][k] = 0;
				}
			}
		}
	}
	if (i == 3) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				if (a[j][k] == a[j][k + 1]) {
					s += a[j][k];
					a[j][k] *= 2;
					for (int l = k + 1; l < 3; l++)
						a[j][l] = a[j][l + 1];
					a[j][4] = 0;
				}
			}
		}
	}
}

bool board::isfull() const {
	bool k = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 0)
				k = false;
		}
	}
	return k;
}

bool board::isavi() const {
	if (!isfull())
		return true;
	for (int k = 0; k < 4; k++) {
		for (int j = 0; j < 3; j++) {
			if (a[j][k] == a[j + 1][k])
				return true;
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 3; k++) {
			if (a[j][k] == a[j][k + 1])
				return true;
		}
	}
	return false;
}


