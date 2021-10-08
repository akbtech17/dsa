#include <iostream>
#include <vector>
#include <map>
#define mci map<char,int>
#define vi vector<int>
using namespace std;

int minSteps(string s, string t) {
	mci mp1, mp2;
	for (auto ch : s) mp1[ch]++;
	for (auto ch : t) mp2[ch]++;
	int ans = 0;
	for (auto p : t) {
		int cch = p.first;
		int ccnt = p.second;

		//agar current char
	}
}

int main() {
	cout << minSteps("bab", "aba");

	return 0;
}