#ifndef guard_info
#define guard_info

#include<vector>
#include<iostream>
#include<string>

struct stdif {
	std::string name;
	double mid, fin;
	std::vector<double> homework;
	double zong;
};

bool compare(const stdif&, const stdif&);
std::istream& read(std::istream&, stdif&);
std::istream& readhw(std::istream&, std::vector<double>&);

#endif