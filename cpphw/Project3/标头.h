#include <iostream>
#include <vector>
#include<string>



class employee {
public:
	employee(std::string string) :n(string) {};
	virtual int salary() = 0;
	virtual ~employee(){};
	std::string name() { return n; }
protected:
	std::string n;
};

class Manager :public employee {
public:
	Manager(std::string n, int ho, int bo) :
		employee(n), hours(ho), bonus(bo){};
	~Manager() {};
	int salary() { return hours * 200 + bonus; }
private:
	int hours, bonus;
};

class Programmer :public employee {
public:
	Programmer(std::string n, int ho, int ov) :
		employee(n), hours(ho), overtime(ov) {};
	~Programmer() {};
	int salary() { return hours * 200 + overtime * 300; }
private:
	int hours, overtime;
};

class Company {
public:
	void AddEmployee(employee* e) { ep.push_back(e); }
	void RemoveEmployee(std::string e) {
		for (int i = 0; i < ep.size(); i++) {
			if (e == ep[i]->name())
				ep.erase(ep.begin() + i);
		}
	}
	~Company() {
		for (int i = 0; i != ep.size(); i++) {
			delete ep[i];
		}
	}
	void Print() {
		for (int i = 0; i != ep.size(); i++) {
			std::cout << ep[i]->name() << ':' << ep[i]->salary() << '\n';
		}
	}
private:
	std::vector<employee*> ep;
};
