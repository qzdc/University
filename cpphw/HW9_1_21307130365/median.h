#ifndef GUARD_median_h
#define GUARD_median_h

// 'median.h'
#include <stdexcept> 
#include <algorithm>
#include <vector>
#include <iterator>
double median(std::vector<double>);
template <class T>
typename std::iterator_traits<T>::value_type median(const T b,const  T e){
	T n = b;
	typedef typename std::iterator_traits<T>::value_type ele;
	std::vector<ele> v;
	typedef std::vector<ele>::size_type vsz;
	while (n != e) {
		v.push_back(*n);
		n++;
	}
	vsz size = v.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	std::sort(v.begin(), v.end());
	vsz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}


#endif