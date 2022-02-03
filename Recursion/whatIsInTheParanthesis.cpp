// whatIsInTheParanthesis.cpp
#include <iostream>
#include <string>
using namespace std;

string findInsideP(string str, int i = 0, bool isOpen = false) {
	if (i == ')' or i == str.length()) return "";
	if (str[i] == '(' ) return findInsideP(str, i + 1, true);
	if (isOpen == false) return findInsideP(str, i + 1, isOpen);

	string ans = "";
	if (isOpen == true and str[i] != ')')
	{
		ans += str[i];
		ans.append(findInsideP(str, i + 1, isOpen));
	}
	return ans;
}

int main() {
	string str;
	cin >> str;
	cout << findInsideP(str);
	return 0;
}