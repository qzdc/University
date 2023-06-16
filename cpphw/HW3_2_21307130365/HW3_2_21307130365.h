#include<algorithm>
template<class T>
T findcom(T b1, T e1, T b2, T e2, T b3) {
	T temp;
	while (b1 != e1) {
		temp = std::find(b2, e2, *b1);
		if (temp != e2) {
			*b3++ = *temp;
		}
		b1++;
	}
	return b3;
}

template<class T>
void out(T b, T e) {
	while (b != e) {
		std::cout << *b++ << "  ";
	}
}