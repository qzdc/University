#include<list>
#include"student_info.h"

typedef std::list<stdif>::iterator listi;
using std::list;

list<stdif> extract_fails(list<stdif>& stu) {
	list<stdif> fail;
	listi i = stu.begin();
	while (i != stu.end()) {
		if ((*i).zong < 60.0) {
			fail.push_back(*i);
			i = stu.erase(i);
		}
		else
			i++;
	}
	fail.sort(compare);
	stu.sort(compare);
	return fail;
}