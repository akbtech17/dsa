// finding - cb - numbers.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool isCBNumber(string str) {
	ll num = stol(str);
	// 	0 and 1 are not a CB number.
	if (num == 0 or num == 1) return false;
	// 2,3,5,7,11,13,17,19,23,29 are CB numbers.
	int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int n = sizeof(arr) / sizeof(int);
	bool isDiv = false;
	for (int i = 0; i < n; ++i) {
		if (num % arr[i] == 0) isDiv = true;
		if (num == arr[i]) return true;
	}
	// Any number not divisible by the numbers in
	// point 2( Given above) are also CB numbers.
	if (!isDiv) return true;
	return false;
}

bool mycomp(pair<int, int> p1, pair<int, int> p2) {
	return (p1.second - p1.first) < (p2.second - p2.first);
}

int findMaxCBNumbers(string str, int n) {
	int ans = 0;
	vector<pair<int, int>> possible_ans;
	//generate all possible substrings
	for (int i = 0; i < n ; ++i) {
		for (int j = i; j < n ; ++j) {
			string temp;
			for (int k = i; k <= j; ++k) {
				temp.push_back(str[k]);
			}
			if (isCBNumber(temp)) {
				possible_ans.push_back({i, j});
			}
		}
	}

	sort(possible_ans.begin(), possible_ans.end(), mycomp);
	int mark[17] = {0};
	for (auto p : possible_ans) {
		if (mark[p.first] == 0 and mark[p.second] == 0) {
			ans++;
			for (int i = p.first; i <= p.second; ++i)
				mark[i] = 1;
		}
	}

	return ans;
}

int main() {
	int n;
	string str;

	cin >> n >> str;

	cout << findMaxCBNumbers(str, n);

	return 0;
}