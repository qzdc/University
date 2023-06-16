#define _CRT_SECURE_NO_WARNINGS
#ifndef guard_game
#define guard_game
#include"borad.h"

class Game2048 {
public:
	Game2048() { ini(); };
	void ini();
	int dir(char) const;
	int score() const{ return b.score(); }
	void move(int i) { b.move(i); }
	void place() { b.place(); }
	void print() { b.print(); }
	board gameboard() { return b; }
	tm start() { return s; }
	tm end() { return e; }
private:
	board b;
	tm s, e;
};

#endif
