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
void freeLink(struct intNode*h){
	struct intNode*p;
	while(h){
		p=h;
		h=h->n;
		free(p);
	}
}
void delMin(struct intNode*h){
	struct intNode *p, *p0, *pp, *pp0;
	p=h->n;
	p0=p;
	pp = h;
	pp0=pp;
	while(p){
		if(p->a < p0->a){
			p0 = p;
			pp0 = pp;
		}
		pp=pp->n;
		p=p->n;
	}
	pp0->n=p0->n;
}
int main(){
	struct intNode *h;
	h=initLink();
	printf("The linked list is:\n");
	outputLink(h);
	delMin(h);
	printf("The linked list after deleting the minimum value is:\n");
	outputLink(h);
	freeLink(h);
}
