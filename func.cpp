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
		for (auto& p : fs::directory_iterator(path)) // ��� ���� ������ � �����
		{
			if (!fs::is_regular_file(p.status()))
				continue; // ����������, ���� ��� �� ������� ����, � ����� ��� ���-�� ������

			string name = p.path().filename().string();
			bool match = name.ends_with(extension);
			//bool match = !name.compare(name.size() - extension.size(), extension.size(), extension);
			if (!match)
				continue;
			arr.push_back(ifstream(p));

			cout << name << '\n';
		}
	}
	catch (exception& e)
	{
		cout << "Error: " << e.what() << '\n';
	}
	return arr;
}
vector < pair<string, vector<int>>> inputDataCSVFile(ifstream& fin) {
	int count;
	fin >> count;

	vector<pair<string, vector<int>>> ans(count);
	for (int i = 0; i < count; i++) {
		getline(fin, ans[i].first, ',');
		for (int j = 0; j < 20; j++) {
			fin >> ans[i].second[j];
			fin.get();
		}
	}
	return ans;
}