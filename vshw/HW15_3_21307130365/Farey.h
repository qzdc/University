#define _CRT_SECURE_NO_WARNINGS
#define len sizeof(struct Farey)
#include<stdio.h>
#include<stdlib.h>//all test samples have passed
struct Farey {
	int n;
	int d;
	double v;
	struct Farey* next;
};

struct Farey* initNode(int, int);
int gcd(int, int);
void insert(struct Farey*, int, int);
void outputFarey(struct Farey*, int);
void freeFarey(struct Farey*);