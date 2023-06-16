#include<stdio.h>
#include<stdlib.h>
#include<time.h>//all test samples have passed
struct intNode {
	int a;
	struct intNode* n;
};
struct intNode* initLink() {
	struct intNode *h, *p1, *p2;
	p1 = (struct  intNode*)(malloc(sizeof(struct intNode)));
	h = p1;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		p2 = (struct  intNode*)(malloc(sizeof(struct intNode)));
		p2->a = rand() % 100;
		p2->n = NULL;
		p1->n = p2;
		p1 = p2;
	}
	return h;
};
void outputLink(struct intNode*p) {
	p = p->n;
	while (p) {
		printf("%4d", p->a);
		p = p->n;
	}
	printf("\n");
};
struct intNode* copy(struct intNode*p) {
	struct intNode*h, *p1, *p2;
	p1 = (struct  intNode*)(malloc(sizeof(struct intNode)));
	h = p1;
	p = p->n;
	while (p) {
		p2 = (struct  intNode*)(malloc(sizeof(struct intNode)));
		p2->a = p->a;
		p2->n = NULL;
		p1->n = p2;
		p1 = p1->n;
		p = p->n;
	}
	return h;
};
struct intNode* copyReversed(struct intNode*p) {
	struct intNode* h, *p1, *p2, *p3;
	h = copy(p);
	p1 = NULL;
	p2 = h->n;
	while (p2) {
		p3 = p2->n;
		p2->n = p1;
		p1 = p2;
		p2 = p3;
	}
	h->n = p1;
	return h;
};
struct intNode* copySorted(struct intNode*p) {
	struct intNode*p1, *p2, *h, *pp, *h0;
	h0 = (struct  intNode*)(malloc(sizeof(struct intNode)));
	p = p->n;
	h = NULL;
	while (p) {
		pp = h;
		p1 = (struct  intNode*)(malloc(sizeof(struct intNode)));
		p1->a = p->a;
		p1->n = NULL;
		p2 = h;
		while (p2 != NULL && p2->a < p->a) {
			pp = p2;
			p2 = p2->n;
		}
		if (p2 == h) {
			h = p1;
		}
		else
			pp->n = p1;
		p1->n = p2;
		p = p->n;
	}
	h0->n = h;
	h = h0;
	return h;
}
void freeLink(struct intNode*h){
	struct intNode*p;
	while(h){
		p=h;
		h=h->n;
		free(p);
	}
}
int main() {
	struct intNode *h[4];
	int i;

	h[0] = initLink();
	h[1] = copy(h[0]);
	h[2] = copyReversed(h[0]);
	h[3] = copySorted(h[0]);

	char *prompt[] = {"The random list", "The copy of the 1st list",
	                  "The reversed copy of the 1st list", "The sorted copy of the 1st list"
	                 };
	for (i = 0; i < 4; i++) {
		printf("%s: \n", prompt[i]);
		outputLink(h[i]);
	}

	for (i = 0; i < 4; i++)
			freeLink(h[i]);
	return 0;
}
