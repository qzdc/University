#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"HW13_2_21307130365.h"
//All test samples have passed
int main() {
	printf("\t\t\t/* Shuffling Cards Progarm */\n\n");
	printf("The initial cards are:\n");
	initCards();
	outputCards();
	shuffle();
	printf("The shuffled cards are:\n");
	outputCards();
	return 0;
}

