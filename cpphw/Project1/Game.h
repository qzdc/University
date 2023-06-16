#define _CRT_SECURE_NO_WARNINGS
#ifndef guard_game
#define guard_game
#include"borad.h"

class Game2048 {
public:
	Game2048() { ini(); };
	~Game2048() { b.clear(); }
	void ini();
	int dir(char) const;
	int score() const{ return b.score(); }
	int move(int i) { return b.move(i); }
	void place() { b.place(); }
	void print() const{ b.print(); }
	bool isfull() { return b.isfull(); }
	void endtime();
	board gameboard() const{ return b; }
	tm start() const{ return s; }
	tm end() const{ return e; }
private:
	board b;
	tm s, e;
};

#endif
