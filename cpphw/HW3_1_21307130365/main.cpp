#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<list>
#include<algorithm>
#include<string>
#include<ios>
#include"student_info.h"
#include"median.h"
#include"grade.h"

using std::string;
using std::list;
using std::cin;
using std::cout;
using std::max;
using std::streamsize;
using std::setprecision;

int main() {
	list<stdif> student;
	stdif record;
	string::size_type maxl = 0;
	typedef std::list<stdif>::iterator listi;
	while (read(cin, record)) {
		maxl = max(maxl, record.name.size());
		student.push_back(record);
	}

	for (listi j = student.begin(); j != student.end(); j++)
		(*j).zong = grade(*j);

	list<stdif> fail = extract_fails(student);
	listi fi = fail.begin();
	listi ip = student.begin();

	cout << "passing student records:\n";
	while (ip != student.end()) {
		string blank(maxl - (*ip).name.size() + 1, ' ');
		cout << (*ip).name << blank;
		streamsize prec = cout.precision();
		cout << setprecision(3) << (*ip).zong <<
			setprecision(prec) << std::endl;
		ip++;
	}

	cout << "failing student records:\n";
	while (fi != fail.end()) {
		string blank(maxl - (*fi).name.size() + 1, ' ');
		cout << (*fi).name << blank;
		streamsize prec = cout.precision();
		cout << setprecision(3) << (*fi).zong <<
			setprecision(prec) << std::endl;
		fi++;
	}

	return 0;
}

