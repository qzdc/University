#include "Farey.h"//all test samples have passed
int main()
{
	int num, n, d, r;
	struct Farey* head, * tail;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	head = initNode(0, 1);
	tail = initNode(1, 1);
	head->next = tail;

	for (d = num; d > 0; d--)	//枚举分母 
		for (n = 1; n < d; n++) {		//分子从1开始，小于分母
			r = gcd(d, n);
			insert(head, n / r, d / r);
		}

	outputFarey(head, num);
	freeFarey(head);

	return 0;
}


struct Farey* initNode(int n, int d) {
	struct Farey* p;
	p = (struct Farey*)malloc(len);
	p->next = NULL;
	p->d = d;
	p->n = n;
	p->v = 1.0 * n / d;
	return p;
}

void outputFarey(struct Farey* h, int num) {
	struct Farey* p;
	printf("Farey sequemce F(%d):\n", num);
	int i = 1;
	for (p = h; p; i++, p = p->next) {
		printf("%d/%d  ", p->n, p->d);
		if (!(i % 10))
			printf("\n");
	}
}

int gcd(int n, int d) {
	while (n != d) {
		if (n > d)
			n -= d;
		else
			d -= n;
	}
	return n;
}

void insert(struct Farey* h, int n, int d) {
	struct Farey* p, * p1, * p2;
	p = (struct Farey*)malloc(len);
	p->next = NULL;
	p->d = d;
	p->n = n;
	p->v = 1.0 * n / d;
	for (p1 = h, p2 = h->next; p->v > p2->v && p2;
		p1 = p1->next, p2 = p2->next);
	if (p->v < p2->v) {
		p1->next = p;
		p->next = p2;
	}
}

void freeFarey(struct Farey* h) {
	struct Farey* p = h;
	while (h) {
		p = h;
		h = h->next;
		free(p);
	}
}

