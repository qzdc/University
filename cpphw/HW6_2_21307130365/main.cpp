#include"Queue.h"
#include<iostream>
#define N1 8
#define N2 25

using std::cout;

int main() {
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ��:\n";
	Queue<int> q;
	int t = 0, i = 1, j = 1;
	while (1) {
		if (t % N1 == 0) {
			if (q.enQueue(t)) {
				cout << t << "s: ��" << i++ << "�˽���.\n";
				break;
			}
			cout << t << "s: ��" << i++ << "�˽���.\n";
		}
		if (t % N2 == 0 && t > 0) {
			q.deQueue();
			cout << "\t\t" << t << "s: ��" << j++ << "�˳���.\n";
		}
		t++;
	}
	cout << "\t\t�ô����Ŷ������Ѵﵽ50�ˣ��������\n" << "\t������Ա��" << q.front()
		<< "s���." << "\n\t��β��Ա��" << q.back() << "s���.";


	Queue<int> q1(q), q2; //����q��ԭ����
	q1.output();
	q2 = q1;
	q2.output();
	return 0;
}