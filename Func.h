#pragma once
#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
vector<ifstream> FindCSV(string);
vector<pair<string, vector<int>>> inputDataCSVFile(ifstream&);
void Analis(ofstream&, vector<pair<string, vector<int>>>);
#endif // !FUNC_H
