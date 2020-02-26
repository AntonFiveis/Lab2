#include <iostream>
#include "Func.h"
using namespace std;
int main() {
	vector<ifstream> files = FindCSV("csv/");


	for (auto& i : files) {
		i.close();
	}
	return 0;
}