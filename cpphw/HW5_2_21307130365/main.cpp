#include"Queue.h"
#include<iostream>
#define N1 8
#define N2 25

using std::cout;

int main() {
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ��:\n";
	Queue q;
	int t = 0, i = 1, j = 1;
	while (!q.isfull()) {
		if (t % N1 == 0) {
			q.in(t);
			cout << t << "s: ��" << i++ << "�˽���.\n";
		}
		if (t % N2 == 0 && t > 0) {
			q.out();
			cout << "\t\t" << t << "s: ��" << j++ << "�˳���.\n";
		}
		t++;
	}
	cout << "\t\t�ô����Ŷ������Ѵﵽ50�ˣ��������\n" << "\t������Ա��" << q.head()->time
		<< "s���." << "\n\t��β��Ա��" << q.end()->time << "s���.";
	return 0;
}