#ifndef guard_board
#define guard_board

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>

class board {
public:
	board() { ini(); }
	void ini();
	int score() const { return s; }
	void print() const;
	void reverse(int);
	void place();
	void move(int);
	void combine(int);
	bool isfull() const;
	bool isavi() const;
private:
	int a[4][4];
	int s;
};


#endif
