#include "handle.h"
using std::vector;
using std::ifstream;

int main() {
	ifstream infile("shapes");
	vector<Handle> shapes;
	readinfo(infile, shapes);
	sort(shapes.begin(), shapes.end(), compare);
	cal_output(shapes);
	return 0;
}