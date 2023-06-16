#include"Game.h"

void Game2048::ini() {
	board b;
	time_t it = time(NULL);
	tm* sp = &s, * ep = &e;
	sp = std::localtime(&it);
	ep = std::localtime(&it);
}

int Game2048::dir(char c) const {
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	if (c == 'w')
		return 1;
	if (c == 's')
		return 2;
	if (c == 'a')
		return 3;
	if (c == 'd')
		return 4;
	if (c == 'q')
		return 5;
	return 0;
}