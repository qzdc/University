#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct c {
	char s[15];
	char f[10];
} card[52];
struct c* p = card;
int main() {
	char* suits[] = { "Spades", "Hearts", "Diammonds", "Clubs" };
	char* faces[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
		"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
	};
	int s;
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			strcpy(p[k].s, suits[i]);
			strcpy(p[k].f, faces[j]);
			k++;
		}
	}
	return 0;
}
