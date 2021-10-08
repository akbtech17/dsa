// 7 - CheckIsomorphicStrings.cpp
// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool areIsomorphic(string str1, string str2) {
	//if strings are empty
	if (str1.size() == 0 and str2.size() == 0) return true;
	if (str1.size() != str2.size()) return false;

	map<char, char> mp1;
	map<char, char> mp2;
	int i = 0;
	int j = 0;

	while (i < str1.size()) {
		//check
		if (mp1.count(str1[i]) != 0) {
			if (mp1[str1[i]] != str2[j]) return false;
		}
		else {
			mp1.insert({str1[i], str2[j]});
		}
		if (mp2.count(str2[j]) != 0) {
			if (mp2[str2[j]] != str1[i]) return false;
		}
		else {
			mp2.insert({str2[j], str1[i]});
		}
		i++;
		j++;
	}
	return true;
}

int main() {
	cout << areIsomorphic("aab", "xxy") << endl;
	cout << areIsomorphic("xudzhi", "ftakcz") << endl;

	return 0;
}

