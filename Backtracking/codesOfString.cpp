// codesOfString.cpp
#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

void printCodes(string str, int i = 0, string ans = "") {
	if (i == str.length()) {
		v.push_back(ans);
		return;
	}
	//extract curr digit
	int dig = str[i] - '0';
	char ch = 'a' + (dig - 1);
	printCodes(str, i + 1, ans + ch);
	//extract curr number
	if (i + 1 < str.length()) {
		int num = stoi(str.substr(i, 2));
		if (num <= 26) {
			char ch = 'a' + (num - 1);
			printCodes(str, i + 2, ans + ch);
		}
	}
	return ;
}

int main() {
	string s;
	cin >> s;

	printCodes(s);
	cout << "[";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << "]";

	return 0;
}