#include "Func.h"
#include <exception>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
vector<ifstream> FindCSV(string path) {
	string extension = ".csv";
	vector<ifstream> arr;
	try 
	{
		for (auto& p : fs::directory_iterator(path)) // Для всех файлов в папке
		{
			if (!fs::is_regular_file(p.status()))
				continue; // Пропускаем, если это не простой файл, а папка или что-то другое

			string name = p.path().filename().string();
			bool match = name.ends_with(extension);
			//bool match = !name.compare(name.size() - extension.size(), extension.size(), extension);
			if (!match)
				continue;
			arr.push_back(ifstream(p));
		}
	}
	catch (exception& e)
	{
		cout << "Error: " << e.what() << '\n';
	}
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
	for (int i = 0; i < ans.size(); i++) {
		cout <<i<<endl <<ans[i].first << ' ';
		for (auto j : ans[i].second) {
			cout << j << ' ';
		}
		cout << endl;
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
void output(vector<pair<int, int>> v) {
	cout << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;;
	
	}
}
vector<pair<string,int>> Top( vector<pair<string, vector<int>>> v) {
	vector<pair<int,int>> PointList(v.size());
	vector<pair<string, int>> ans(10);
	for (int i = 0; i < PointList.size(); i++)
	{
		PointList[i] = {i,0};
	}
	output(PointList);
	for (int i = 0; i < 20; i++) {
		vector<pair<int,int>> temp;
		for (int j = 0; j < v.size(); j++) {
			temp.push_back({ j, v[j].second[i] });
		}
		output(temp);
		temp = findFirst10inCollomn(temp);
		output(temp);
		AddingPoints(v, temp, PointList);
		output(PointList);
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