#include<stdio.h>
#include<stdlib.h>

struct p{
	int b;
	int k;
//	p* l;
	p* n;
};

p* in(int *pn, int *pk){
	scanf("%d %d", pn, pk);
	p* p1, *p2, *h;
	h=p1=(p*)malloc(sizeof(p));
	for(int i=0;i<*pn;i++){
		p2=(p*)malloc(sizeof(p));
		p2->b=i+1;
		scanf("%d", &p2->k);
		p2->n=NULL;
	//	p2->l=p1;
		p1=p1->n=p2;
	}
	p2->n=h->n;
//	h->n->l=p2;
	return h->n;
}

p* kick(p* p2, int *pk){
//	p*p1=p2->l;
	p*p1;
	while(p1->n->b!=p2->b){
		p1=p1->n;
	}
	for(int i = 0;i<*pk-1;i++){
		p1=p1->n;
		p2=p2->n;
	}
	p1->n=p2->n;
//	p2->n->l=p1;
	*pk=p2->k;
	return p2->n;
}

void out(p* pe){
	printf("Ê£ÏÂ%dºÅ", pe->b);
}

int main(){
	int n, k;
	p*pe=in(&n, &k);
	for(int i=1;i<k;i++){
		pe=kick(pe, &k);

	}
	out(pe);
	return 0;
}
