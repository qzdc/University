//#include"borad.h"
#include"Game.h"

using std::cout;
using std::cin;

int main() {
	cout << "Welcome to the game of 2048!\n";
	Game2048 game;
	game.print();
	char c;
	while (game.gameboard().isavi()) {
		cin >> c;
		int d = game.dir(c);
		if (d == 5) {
			break;
		}
		else if (d) {
			game.move(d);
			game.place();
			game.print();
			cout << '\n' << game.score();

		}
	}
}