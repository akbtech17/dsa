// 4 - CheckInterleavedStringForCommonChars.cpp
// https://www.geeksforgeeks.org/find-if-a-string-is-interleaved-of-two-other-strings-dp-33/#:~:text=C%20is%20said%20to%20be,in%20individual%20strings%20is%20preserved.
#include <iostream>
#include <cstring>
using namespace std;

bool checkRecurse(string a, string b, string s, int i = 0, int j = 0, int k  = 0) {
	//base case - if all strings are empty
	if (i == a.size() and j == b.size() and k == s.size()) {
		return true;
	}
	//if string is empty
	if (k == s.size()) return false;
	//there can be two possiblites
	bool isTrue = false;
	//a string char is included
	if (s[k] == a[i]) {
		isTrue = isTrue or checkRecurse(a, b, s, i + 1, j, k + 1);
	}
	//b string char in included
	if (s[k] == b[j]) {
		isTrue = isTrue or checkRecurse(a, b, s, i, j + 1, k + 1);
	}

	return isTrue;
}

int main() {
	if (checkRecurse("XXY", "XXZ", "XXXXZY")) cout << "true\n";
	else cout << "false\n";
	// if (checkRecurse("AB", "CD", "ACBG")) cout << "true\n";
	// else cout << "false\n";
	return 0;
}
