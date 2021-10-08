// 3 - CheckIfGivenStringIsInterleavingOfTwoStrings.cpp
// Given - no common chars in str a and b
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

bool check(string a, string b, string s) {
	//check  - frequency of chars
	map<char, int> mp;
	for (int i = 0; i < a.size(); ++i) mp[a[i]]++;
	for (int i = 0; i < b.size(); ++i) mp[b[i]]++;
	for (int i = 0; i < s.size(); ++i) {
		mp[s[i]]--;
		if (mp[s[i]] == 0) mp.erase(s[i]);
	}
	if (mp.empty() == true) {
		//check subsequences
		int i = 0;
		int j = 0;
		for (int itr = 0; itr < s.size(); ++itr)
		{
			if (s[itr] == a[i]) {
				i++;
			}
			else if (s[itr] == b[j]) {
				j++;
			}
			else return false;
		}
		return true;
	}
	return false;
}

int main() {
	if (check("AB", "CD", "ACBD")) cout << "true\n";
	else cout << "false\n";
	if (check("AB", "CD", "ACBG")) cout << "true\n";
	else cout << "false\n";
	return 0;
}
