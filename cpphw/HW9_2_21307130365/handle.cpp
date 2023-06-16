#include "handle.h"
#include <iomanip>

using std::vector;
using std::cout;
using std::streamsize;
using std::setprecision;

std::ifstream& Handle::read(std::ifstream& fin) {
	char ch;
	const char* tab[] = { "Triangle.", "Rectangle.","Circle." };
	delete p;
	int i = 0;
	if (fin >> ch)
		i = 1;
	if (ch == 'T')
		p = new tri;
	else if (ch == 'C')
		p = new cir;
	else
		p = new rec;
	p->read(fin);
	if (!p->isvalid() && i) {
		p->out();
		std::cout << "can't make a ";
		if (ch == 'T')
			std::cout << tab[0];
		if (ch == 'C')
			std::cout << tab[2];
		if (ch == 'R')
			std::cout << tab[1];
	}
	else p->area(); 
	return fin;
}
std::ifstream& readinfo(std::ifstream& fin, vector<Handle>& v) {
	const char* tab[] = { "Triangle.", "Rectangle.","Circle." };
	Handle record;
	int i = 0;

	while (record.read(fin)) {
		if (record.p->isvalid())
			v.push_back(record);
	}
	
	return fin;
}
void cal_output(vector<Handle>& v) {

	std::ofstream fout("result.csv");
	cout << "\n\nArea\tPerimeter\n";
	fout << "Area,Perimeter\n";
	for (vector<Handle>::size_type i = 0;
		i != v.size(); ++i) {
		double area = v[i].area(), peri = v[i].perimeter();
		streamsize prec = cout.precision();
		cout << setprecision(3) << area << '\t'
			<< setprecision(3) << peri
			<< setprecision(prec) << '\n';
		fout << setprecision(3) << area << ','
			<< setprecision(3) << peri
			<< setprecision(prec) << '\n';
	}
}

Handle& Handle::operator=(const Handle& h) {
	if (&h != this) {
		delete p;
		if (h.p) p = h.p->clone();
		else p = 0;
	}
	return *this;
}