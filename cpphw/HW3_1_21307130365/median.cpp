#include"median.h"
#include"student_info.h"
#include"grade.h"

double median(std::list<double> vec) {
	typedef std::list<double>::size_type vecsz;
	typedef std::list<double>::iterator listi;
	vecsz size = vec.size();
	vec.sort();
	listi i = vec.begin();
	if (size == 0)
		return 0;
	int mid = size / 2;
	for (int j = 0; j < mid; j++)
		i++;
	listi j = i;
	j--;
	return size % 2 == 0 ? (*i + *j) / 2 : *i;
}