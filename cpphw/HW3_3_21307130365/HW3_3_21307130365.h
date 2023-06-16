template<class T, class X>
X accumulate(T b, T e, X x) {
	while (b != e) {
		x += *b;
		b++;
	}
	return x;
}

template<class T>
T max_element(T b, T e) {
	T max=b;
	while (b != e) {
		if (*b > *max )
			max = b;
		b++;
	}
	return max;
}

template<class T>
T min_element(T b, T e) {
	T min = b;
	while (b != e) {
		if (*b < *min)
			min = b;
		b++;
	}
	return min;
}


template<class T>
void output(T b, T e) {
	while (b != e) {
		std::cout << *b << " ";
		b++;
	}
	std::cout << std::endl;
}