#include <iostream>
#include "Func.h"
int main() {
	vector<ifstream> InFiles = FindCSV("csv/");
	ofstream outFile("results.csv");
	vector<pair<string, vector<int>>> results;
	int n = 0;
	for (int i = 0; i < InFiles.size(); i++) {
		
		inputDataCSVFile(InFiles[i],results,n);
		//Analis(outFile, temp);
	}

	for (int i = 0; i < InFiles.size();i++) {
		InFiles[i].close();
	}
	return 0;
}