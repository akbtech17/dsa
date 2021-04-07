// 2 - PrintAllInterleavingOfTwoStrings.cpp
// https://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/
#include <iostream>
#include <cstring>
using namespace std;

void printAllInterleavings(string s1, string s2, int i = 0 , int j = 0, string ans = "") {
	//base case
	if (i == s1.size() and j == s2.size()) {
		cout << ans << endl;
		return;
	}

	//recursive case
	//string 1 char can be included
	if (i < s1.size()) {
		printAllInterleavings(s1, s2, i + 1, j, ans + s1[i]);
	}
	//string 2 char can be included
	if (j < s2.size()) {
		printAllInterleavings(s1, s2, i, j + 1, ans + s2[j]);
	}
	return;
}

int main() {
	printAllInterleavings("AB", "CD");
	return 0;
}