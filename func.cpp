#include "Func.h"
#include <exception>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

string inputPath() {
	cout << "Enter path: ";
	string path;
	getline(cin, path);
	return path;
}

vector<ifstream> FindCSV() {
	string path = inputPath();
	string extension = ".csv";
	vector<ifstream> arr;
	bool ex;
	do {
		ex = false;
		try
		{
			for (auto& p : fs::directory_iterator(path)) // ��� ���� ������ � �����
			{
				if (!fs::is_regular_file(p.status()))
					continue; // ����������, ���� ��� �� ������� ����, � ����� ��� ���-�� ������

				string name = p.path().filename().string();
				bool match = name.ends_with(extension);
				if (!match)
					continue;
				arr.push_back(ifstream(p));
			}
		}
		catch (exception & e)
		{
			cout << "Error: " << e.what() << '\n';
			path = inputPath();
			ex = true;
		}

	} while (ex);
	return arr;
}
void inputDataCSVFile(ifstream& fin, vector<pair<string, vector<int>>>& ans) {
	int count;
	fin >> count;
	fin.get();
	for (int i = 0; i < count; i++) {
		string s;
		getline(fin, s, ',');
		ans.push_back({ s,{} });
		for (int j = 0; j < 20; j++) {
			int temp;
			fin >> temp;
			ans[ans.size()-1].second.push_back(temp);
			fin.get();
		}
	}

}
vector<pair<int,int>> findFirst10inCollomn(vector<pair<int,int>> v) {
	InsertSort(v);
	v.erase(v.begin(), v.end() - 10);
	return v;
}

void AddingPoints(vector<pair<string, vector<int>>> v, vector<pair<int,int>> temp, vector<pair<int, int>>& PointList) {
	vector<int> arr={ 1,2,3,4,5,6,7,8,10,12 };
	for (int j = 0; j < 10; j++) {
		PointList[temp[j].first].second += arr[j];
	}

}

vector<pair<string,int>> Top( vector<pair<string, vector<int>>> v) {
	vector<pair<int,int>> PointList(v.size());
	vector<pair<string, int>> ans(10);
	for (int i = 0; i < PointList.size(); i++)
	{
		PointList[i] = {i,0};
	}

	for (int i = 0; i < 20; i++) {
		vector<pair<int,int>> temp;
		for (int j = 0; j < v.size(); j++) {
			temp.push_back({ j, v[j].second[i] });
		}
		temp = findFirst10inCollomn(temp);
		AddingPoints(v, temp, PointList);
	}

	PointList=findFirst10inCollomn(PointList);
	for (int i = 0; i < 10; i++) {
		ans[i] = { v[PointList[i].first].first,PointList[i].second };
	}
	return ans;
}

void InsertSort(vector<pair<int,int>> &arr) {
	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0 && arr[j - 1].second > arr[j].second; j--) {
			pair<int,int> tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}