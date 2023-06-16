#include "shapes.h"
#include <iomanip>

using std::vector;			using std::setprecision;
using std::streamsize;		using std::cout; 

int main() {
	std::ifstream fin("shapes");
	std::ofstream fout("result.csv");

	const char* tab[] = {"Triangle.", "Rectangle.","Circle."};
	vector<shape*> v;
	shape* record;
	char ch;
	int i = 0;
	while (fin >> ch) {
		if (ch == 'T')
			record = new tri;
		else if (ch == 'C')
			record = new cir;
		else
			record = new rec;
		record->read(fin);
		if (!record->isvalid()) {
			record->out();
			cout << "can't make a ";
			if (ch == 'T')
				cout << tab[0];
			if (ch == 'C')
				cout << tab[2];
			if (ch == 'R')
				cout << tab[1];
		}
		else {
			v.push_back(record);
			v[i++]->area();
		}
	}

	std::sort(v.begin(), v.end(), comp);

	cout << "\n\nArea\tPerimeter\n";
	fout << "Area,Perimeter\n";
	for (vector<shape*>::size_type i = 0;
		i != v.size(); ++i) {
		double area = v[i]->getarea(), peri = v[i]->perimeter();
		streamsize prec = cout.precision();
		cout << setprecision(3) << area << '\t'
			<< setprecision(3) << peri
			<< setprecision(prec) << '\n';
		fout << setprecision(3) << area << ','
			<< setprecision(3) << peri
			<< setprecision(prec) << '\n';
		delete v[i];
	}

	return 0;
}