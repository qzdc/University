#include"Queue.h"
#include<iostream>
#define N1 8
#define N2 25

using std::cout;

int main() {
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟:\n";
	Queue<int> q;
	int t = 0, i = 1, j = 1;
	while (1) {
		if (t % N1 == 0) {
			if (q.enQueue(t)) {
				cout << t << "s: 第" << i++ << "人进队.\n";
				break;
			}
			cout << t << "s: 第" << i++ << "人进队.\n";
		}
		if (t % N2 == 0 && t > 0) {
			q.deQueue();
			cout << "\t\t" << t << "s: 第" << j++ << "人出队.\n";
		}
		t++;
	}
	cout << "\t\t该窗口排队人数已达到50人！请分流！\n" << "\t队首人员于" << q.front()
		<< "s入队." << "\n\t队尾人员于" << q.back() << "s入队.";


	Queue<int> q1(q), q2; //假设q是原队列
	q1.output();
	q2 = q1;
	q2.output();
	return 0;
}