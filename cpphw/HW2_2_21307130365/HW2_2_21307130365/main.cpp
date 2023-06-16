#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<ios>
#include"student_info.h"
#include"median.h"
#include"grade.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::streamsize;
using std::setprecision;

int main() {
	vector<stdif> student;
	stdif record;
	string::size_type maxl = 0;
	while(read(cin, record)) {
		maxl = max(maxl, record.name.size());
		student.push_back(record);
	}
	int meizuozuoye = 0;
	for (vector<stdif>::size_type i = 0; i != student.size(); i++) {
		try {
			student[i].zong = grade(student[i]);
		}
		catch (std::domain_error e) {
			string blank(maxl - student[i].name.size() + 1, ' ');
			cout << student[i].name << blank << 
				e.what() << std::endl;
			meizuozuoye++;
		}
	}

	sort(student.begin(), student.end(), compare);

	for (vector<stdif>::size_type i = 0;
		i != student.size() - meizuozuoye; i++) {
		try {
			string blank(maxl - student[i].name.size() + 1, ' ');
			cout << student[i].name << blank;
			streamsize prec = cout.precision();
			cout << setprecision(3) << student[i].zong << 
				setprecision(prec);
		}
		catch (std::domain_error e) {
			continue;
		}
		cout << std::endl;
	}

	return 0;
}

