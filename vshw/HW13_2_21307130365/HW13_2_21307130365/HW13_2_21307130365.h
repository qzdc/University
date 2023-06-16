void initCards();
void outputCards();
void shuffle();
struct c {
	char s[15];
	char f[10];
} card[52];
struct c *p = card;
char *suits[] = {"Spades", "Hearts", "Diammonds", "Clubs"};
char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
	"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
void initCards() {
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			strcpy(p[k].s, suits[i]);
			strcpy(p[k].f, faces[j]);
			k++;
		}
	}
}
void outputCards() {
	for (int i = 0; i < 52; i++) {
		printf("%s", p[i].s);
		for (int j = 0; j < 11 - strlen(p[i].s); j++) {
			printf(" ");
		}
		printf("%s", p[i].f);
		for (int j = 0; j < 6 - strlen(p[i].f); j++) {
			printf(" ");
		}
		printf("|");
		if ((i + 1) % 6 == 0) {
			printf("\n");
		}
	}
	printf("\n\n");
}
void shuffle() {
	srand(time(NULL));
	for (int k = 0; k < 52; k++) {
		int t = rand() % 52;
		struct c a;
		strcpy(a.f, p[k].f);
		strcpy(a.s, p[k].s);
		strcpy(p[k].f, p[t].f);
		strcpy(p[k].s, p[t].s);
		strcpy(p[t].f, a.f);
		strcpy(p[t].s, a.s);
	}
}
