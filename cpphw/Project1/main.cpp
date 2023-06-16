#include"Game.h"

using std::cout;
using std::cin;

int main() {
	cout << "Welcome to the game of 2048!\n";
	Game2048 game;
	game.print();
	cout << "\nYour score: " << game.score()
		<< "\n(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
	char c;
	while (game.gameboard().isavi()) {
		cin >> c;
		int d = game.dir(c);
		if (d == 5) {
			break;
		}
		else if (d) {
			if(!game.move(d) && game.isfull())
				break;
			game.place();
			game.print();
			cout << "\nYour score: " << game.score()
				<< "\n(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
		}
		else {
			cout << "(¡ü:u) (¡ý:d) (¡û:l) (¡ú:r) (quit:q): ";
		}
	}
	tm starttime = game.start();
	game.endtime();
	tm endtime = game.end();
	cout << "Game Over";
	time_t s = mktime(&starttime), e = mktime(&endtime);
	double duration = std::difftime(e, s);

	std::string stime(std::asctime(&starttime));
	stime[stime.size() - 1] = ',';
	std::ofstream file("game2048.csv", std::ofstream::app);
	file << stime << duration << ',' << game.score() << '\n';

	return 0;
}