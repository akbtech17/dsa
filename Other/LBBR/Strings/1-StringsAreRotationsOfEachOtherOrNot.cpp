// 1 - StringsAreRotationsOfEachOtherOrNot.cpp
#include <iostream>
#include <string>
using namespace std;

bool isStringRotationOfEachOther(string s1, string s2) {
	//check if size are different
	if (s1.size() != s2.size()) return false;

	string temp = s1 + s1;
	return (temp.find(s2) != string::npos);
}

int main() {
	cout << isStringRotationOfEachOther("ABCD", "CDAB") << endl;
	cout << isStringRotationOfEachOther("ABCD", "ACBD") << endl;

	return 0;
}