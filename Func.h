#pragma once
#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
vector<ifstream> FindCSV(string);
vector<pair<string, vector<int>>> inputDataCSVFile(ifstream&);
vector<int> Top(vector<pair<string, vector<int>>>);
void AddingPoints(vector<pair<string, vector<int>>>&, vector<int>, vector<int>&);
vector<int> findFirst10inCollomn(vector<int>);
#endif // !FUNC_H
