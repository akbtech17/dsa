// 1 - Subsets.cpp
#include <iostream>
#include <cstring>
using namespace std;

void printSubsets(string s, int i = 0, string subset = "") {
	//base case - if i exceedds the len of string
	if (i == s.length()) {
		//print the subset
		cout << subset << " ";
		return;
	}

	//recrsive case - for every char - two choices
	//dont include
	printSubsets(s, i + 1, subset);
	//include
	printSubsets(s, i + 1, subset + s[i]);
	return;
}

int main() {
	printSubsets("abc");
	return 0;
}