#include <iostream>
#include "Func.h"
int main() {
	vector<ifstream> InFiles = FindCSV("csv/");
	ofstream outFile("results.csv");
	vector<pair<string, vector<int>>> results;
	vector<pair<string, int>> TopList;
	for (int i = 0; i < InFiles.size(); i++) {
		inputDataCSVFile(InFiles[i],results);
	}
	TopList = Top(results);

	for (int i = 0; i < 10; i++) {
		outFile << i + 1 << ", " << TopList[9 - i].first << ", " << TopList[9 - i].second << endl;
	}

	for (int i = 0; i < InFiles.size();i++) {
		InFiles[i].close();
	}
	outFile.close();
	return 0;
}