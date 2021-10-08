// 2 - StringWithZeroOrOneSpace.cpp
#include <iostream>
#include <cstring>
using namespace std;

void printStrings(string s, int i = 0, string str = "") {
	//base case - if i exceedds the len of string
	if (s.size() == 0) return;
	if (i == s.length() - 1) {
		//print the subset
		str += s[i];
		cout << str << endl;
		return;
	}
	//recrsive case - for every char - two choices
	//add char
	str += s[i];
	//dont include space
	printStrings(s, i + 1, str);
	//include space after
	printStrings(s, i + 1, str + ' ');
	return;
}

int main() {
	printStrings("abc");
	return 0;
}