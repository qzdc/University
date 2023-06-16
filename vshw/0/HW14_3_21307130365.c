#include<stdio.h>
#include<stdlib.h>
#include<math.h>//all test samples have passed
//use a negative int power to end ,please don't use ctrl Z/D  :(
struct f {
	int po;
	double co;
	struct f* n;
};
struct f* copy(struct f*p) {
	struct f*h, *p1, *p2;
	p1 = (struct  f*)(malloc(sizeof(struct f)));
	h = p1;
	p = p->n;
	while (p) {
		p2 = (struct  f*)(malloc(sizeof(struct f)));
		p2->po = p->po;
		p2->co = p->co;
		p2->n = NULL;
		p1->n = p2;
		p1 = p1->n;
		p = p->n;
	}
	return h;
};
struct f* get() {
	struct f* p1, * p2, * p, * h;
	int po;
	double c;
	h = (struct f*)malloc(sizeof(struct f));
	h->n = NULL;
	printf("Power (enter ctrl + Z / D for end): ");
	scanf_s("%d", &po);
	while (po >= 0) {
		printf("Coefficient of power %d: ", po);
		scanf_s("%lf", &c);
		p = (struct f*)malloc(sizeof(struct f));
		p->po = po;
		p->co = c;
		p2 = h;
		p1 = h->n;
		while (p1 && po < p1->po) {
			p2 = p1;
			p1 = p1->n;
		}
		p2->n = p;
		p->n = p1;
		printf("Power (enter ctrl + Z / D for end) :");
		scanf_s("%d", &po);
	}
	return h;
}
struct f* add(struct f* l, struct f* k) {
	struct f* p0, * p, * lpt, * kpt;
	p0 = l;
	lpt = l->n;
	kpt = k->n;
	while (kpt) {
		if (lpt == NULL || lpt->po < kpt->po) {
			p = (struct f*)malloc(sizeof(struct f));
			p->po = kpt->po;
			p->co = kpt->co;
			p->n = lpt;
			p0->n = p;
			p0 = p;
			kpt = kpt->n;
		}
		else if (lpt->po == kpt->po) {
			lpt->co += kpt->co;
			if (fabs(lpt->co) < 1e-6) {
				p0->n = lpt->n;
				free(lpt);
			} else
				p0 = p0->n;
			lpt = p0->n;
			kpt = kpt->n;
		}
		else {
			p0 = p0->n;
			lpt = p0->n;
		}
	}
	return l;
}
void out(struct f* f) {
	f = f->n;
	if (f->po > 1){
		if(fabs(f->co - 1) < 1e-6)
			printf("x^%d", f->po);
		else if(fabs(f->co + 1) < 1e-6)
			printf("-x^%d", f->po);
		else
			printf("%gx^%d", f->co, f->po);
		
	}
	else if (f->po == 1){
		if(fabs(f->co - 1) < 1e-6)
			printf("x");
		if(fabs(f->co + 1) < 1e-6)
			printf("-x");
		else
			printf("%gx", f->co);
	}
	else
		printf("%g", f->co);
	f = f->n;
	while (f) {
		if (f->po > 1){
			if(fabs(f->co - 1) < 1e-6)
				printf("+x^%d", f->po);
			else if(fabs(f->co + 1) < 1e-6)
				printf("-x^%d", f->po);
			else
				printf("%+gx^%d", f->co, f->po);
			
		}
		else if (f->po == 1){
			if(fabs(f->co - 1) < 1e-6)
				printf("+x");
			if(fabs(f->co + 1) < 1e-6)
				printf("-x");
			else
				printf("%+gx", f->co);
		}
		else
			printf("%+g", f->co);
		f = f->n;
	}
}
void fre(struct f *h){
	struct f *p;
	while(h){
		p=h;
		h=h->n;
		free(p);
	}
}
int main() {
	struct f* f1, * f2, * f3, * f;
	printf("\t\tPolynimial summation\n");
	printf("\tEnter the power and coefficient if the 1st polynomial\n");
	f1 = get();
	printf("\tEnter the power and coefficient if the 2nd polynomial\n");
	f = copy(f1);
	f2 = get();
	f3 = add(f1, f2);
	if(f){
		printf("\n(");
		out(f);
		printf(")");
	}
	else
		printf("0");
	printf("+");
	if(f2){
		printf("(");
		out(f2);
		printf(")");
	}
	else
		printf("0");
	printf("=");
	if(f3->n){
		printf("(");
		out(f3);
		printf(")");
	}
	else
		printf("0");
	printf("\n");
	fre(f);
	fre(f1);
	fre(f2);
	fre(f3);
	return 0;
}
