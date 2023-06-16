#include "Queue.h"

void Queue::in(int t) {
	elemt* n = new elemt[1];
	if (isvac()) {
		h = n;
		(*n).next = NULL;
		(*n).time = t;
		e = n;
	}
	else {
		e->next = n;
		(*n).next = NULL;
		(*n).time = t;
		e = n;
	}
	l++;
}
void Queue::out() {
	elemt* n = h->next;
	delete[] h;
	h = n;
	l--;
}
void Queue::output() const{
	elemt* p = h;
	std::cout << '\n';
	for (int i = 0; i < l; i++) {
		std::cout << (*p).time << '\t';
		if ((i + 1) % 10 == 0)
			std::cout << '\n';
		p = (*p).next;
	}
}

