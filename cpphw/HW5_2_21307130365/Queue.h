#ifndef Guard_Queue
#define Guard_Queue

#include<cstdlib>
#include<iostream>
struct elemt {
	elemt* next;
	int time;
	elemt() :time(0), next(NULL) {};
};
class Queue {
public:
	elemt* head() const { return h; }
	elemt* end() const { return e; }
	int lenth() const { return l; }
	Queue() : e(NULL), h(NULL), l(0) {};
	void in(int);
	void out();
	void output() const;
	bool isvac() const { return !l; }
	bool isfull() const { return l >= 50; }
private:
	elemt* h;
	elemt* e;
	int l;
};

#endif