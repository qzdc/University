#include "БъЭЗ.h"

int main() {
	Company cp;
	cp.AddEmployee(new Manager("Wang", 20, 500));
	cp.AddEmployee(new Programmer("Chen", 20, 10));
	cp.AddEmployee(new Programmer("Zhao", 30, 0));
	cp.RemoveEmployee("Chen");
	cp.AddEmployee(new Programmer("Lin", 15, 5));
	cp.Print();
	return 0;
}