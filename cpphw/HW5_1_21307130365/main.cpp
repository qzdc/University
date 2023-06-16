#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;   	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	std::ifstream in("grades");
	std::ofstream out("final");

	while (record.read(in)) {
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {

		// write the name, padded on the right to 'maxlen+1' characters
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		out << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');
		// compute and write the grade
		try {
			double grade = students[i].grade();
			cout << tab[letter_grade(grade)];
			out << tab[letter_grade(grade)];
		} catch (domain_error e) {
			cout << e.what();
			out << e.what();
		}
		cout << endl;
		out << endl;
	}

	int a[11];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 11; i++) {
		a[i] = (rand() % 100);
	}
	cout << "\n\nthe following is the result of testing median function on array\n"
		<< "the random array is:\n";
	for (int i = 0; i < 11; i++) {
		cout << a[i] << ' ';
	}
	cout << "\nthe median of the array is: " << median(a, a + 11)
		<< "\nafter median function called, the array is unchanged:\n";
	for (int i = 0; i < 11; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}

