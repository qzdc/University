#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <stdexcept> 
#include <algorithm>
double median(std::vector<double>);
template<class T>
typename T::value_type median(T b, T e) {
	T n = b;
	typedef typename T::value_type ele;
	std::vector<ele> v;
	typedef typename std::vector<ele>::size_type vsz;
	while (n != e) {
		v.push_back(*n);
		n++;
	}
	vsz size = v.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	sort(v.begin(), v.end());
	vsz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<typename T>
T median(T* begin, T* end) {
	typedef std::vector<T>::size_type vec_sz;
	std::vector<T> vec;
	T* p = begin;
	while (p != end) {
		vec.push_back(*p);
		p++;
	}
	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

#endif