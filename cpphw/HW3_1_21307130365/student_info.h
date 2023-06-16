#ifndef guard_info
#define guard_info

#include<list>
#include<iostream>
#include<string>

struct stdif {
	std::string name;
	double mid, fin;
	std::list<double> homework;
	double zong;
};

bool compare(const stdif&, const stdif&);
std::istream& read(std::istream&, stdif&);
std::istream& readhw(std::istream&, std::list<double>&);
std::list<stdif> extract_fails(std::list<stdif>&);

#endif