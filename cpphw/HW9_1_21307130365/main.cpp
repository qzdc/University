#include "handle.h"
#include <iomanip>

using std::vector;			using std::setprecision;
using std::domain_error;   	using std::streamsize;
using std::cout;			using std::endl;
int main() {
	vector<student_info> stu;
	student_info record;
	std::ifstream fin ("grades2");
	std::string::size_type max = 0;

	while (record.read(fin)) {
		max = std::max(max, record.name().size());
		stu.push_back(record);
	}

	std::sort(stu.begin(), stu.end(), student_info::compare);

	for (vector<student_info>::size_type i = 0;
		i != stu.size(); ++i) {

		try {
			cout << stu[i].name()
			<< std::string(max + 1 - stu[i].name().size(), ' ');
		}
		catch (domain_error e) {
			cout << e.what();
		}
		try {
			double final_grade = stu[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
		
	}
	return 0;
}