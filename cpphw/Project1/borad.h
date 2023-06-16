#ifndef guard_board
#define guard_board

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include <memory>

class board {
public:
	board() { ini(); }
	void ini();
	int score() const { return s; }
	void print() const;
	void reverse(int);
	void place();
	int move(int);
	void combine(int);
	bool isfull() const;
	bool isavi() const;
	void clear();
private:
	int a[4][4];
	int s;
	std::allocator<int> alloc;
};

int getwidth(int);

#endif
