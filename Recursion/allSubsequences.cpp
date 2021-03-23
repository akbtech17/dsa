// allSubsequences.cpp
#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

// vector<string> v;

void printAllSubsequences(string str, int i, string ans, vector<string> &v) {
	//base case
	if (i == str.length()) {
		v.push_back(ans);
		return;
	}
	//recursive case
	printAllSubsequences(str, i + 1, ans + str[i], v);
	printAllSubsequences(str, i + 1, ans, v);

	return;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		vector<string> v;
		printAllSubsequences(str, 0, "", v);
		sort(v.begin(), v.end());
		for (auto el : v) cout << el << endl;
		cout << endl;
	}
	return 0;
}