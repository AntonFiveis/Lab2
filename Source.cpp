#include <iostream>
#include "Func.h"
int main() {
	vector<ifstream> InFiles = FindCSV("csv/");
	for (int i = 0; i < InFiles.size(); i++) {
		ofstream outFile("results" + to_string(i) + ".csv");
		auto temp = inputDataCSVFile(InFiles[i]);
		Analis(outFile, temp);
		outFile.close();
	}

	for (int i = 0; i < InFiles.size();i++) {
		InFiles[i].close();
	}
	return 0;
}