#include"median.h"

double median(std::vector<double> vec) {
	typedef std::vector<double>::size_type vecsz;
	vecsz size = vec.size();
	if (size == 0)
		throw std::domain_error("student has done no homework");
	sort(vec.begin(), vec.end());
	vecsz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}