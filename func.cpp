#include "Func.h"
#include <exception>
#include <filesystem>
#include <iostream>
#include <algorithm>
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
vector<pair<string, vector<int>>> inputDataCSVFile(ifstream& fin) {
	int count;
	fin >> count;

	vector<pair<string, vector<int>>> ans(count);
	for (int i = 0; i < count; i++) {
		getline(fin, ans[i].first, ',');
		for (int j = 0; j < 20; j++) {
			int temp;
			fin >> temp;
			ans[i].second.push_back(temp);
			fin.get();
		}
	}
	return ans;
}
vector<int> findFirst10inCollomn(vector<int> v) {
	vector<int> ans(10);
	sort(v.begin(), v.end());
	for (int i = 0; i < 10; i++) {
		ans[i] = v[v.size() - 11 + i];
	}
	return ans;
}

void AddingPoints(vector<pair<string, vector<int>>>& v, vector<int> temp, vector<int>& PointList) {

}

vector<int> Top( vector<pair<string, vector<int>>> v) {
	vector<int> PointList(v.size());
	for (int i = 0; i < 20; i++) {
		vector<int> temp;
		for (int j = 0; j < v.size(); j++) {
			temp.push_back(v[j].second[i]);
		}
		AddingPoints(v, temp, PointList);

	}
}