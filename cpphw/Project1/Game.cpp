#include"Game.h"

void Game2048::ini() {
	board b;
	time_t it = time(NULL);
	tm* time = std::localtime(&it);
	s = *time;
	e = *time;
}

int Game2048::dir(char c) const {
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	if (c == 'u')
		return 1;
	if (c == 'd')
		return 2;
	if (c == 'l')
		return 3;
	if (c == 'r')
		return 4;
	if (c == 'q')
		return 5;
	return 0;
}

void Game2048::endtime() {
	time_t it = time(NULL);
	tm* ep = std::localtime(&it);
	e = *ep;
}

