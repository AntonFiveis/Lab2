#pragma once
#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;
vector<ifstream> FindCSV(string);
void inputDataCSVFile(ifstream&, vector<pair<string, vector<int>>>&);
vector<pair<string,int>> Top(vector<pair<string, vector<int>>>);
void AddingPoints(vector<pair<string, vector<int>>>&, vector<int>, vector<int>&);
vector < pair<int,int> > findFirst10inCollomn(vector<pair<int, int>>);
void InsertSort(vector<pair<int, int>>&);
#endif // !FUNC_H
