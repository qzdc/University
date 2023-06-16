#include "grad.h"
#include <iomanip>

using std::vector;			using std::setprecision;
using std::domain_error;   	using std::streamsize;
using std::cout;			using std::endl;
int main() {
	vector<Core*> stu;
	Core* record;
	char ch;
	std::ifstream fin ("grades2");
	std::string::size_type max = 0;

	while (fin >> ch) {
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(fin);
		max = std::max(max, record->name().size());
		stu.push_back(record);
	}

	std::sort(stu.begin(), stu.end(), compare);

	for (vector<Core*>::size_type i = 0;
		i != stu.size(); ++i) {

		cout << stu[i]->name()
			<< std::string(max + 1 - stu[i]->name().size(), ' ');
		try {
			double final_grade = stu[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
		delete stu[i];
	}
	return 0;
}