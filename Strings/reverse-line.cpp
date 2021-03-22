// reverse - line.cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseLine(string str) {
	string ans;

	for (int i = str.length() - 1; i >= 0;) {
		if (str[i] != ' ') {
			//extract the word
			string word;
			while (i >= 0 and str[i] != ' ') {
				word.push_back(str[i--]);
			}
			reverse(word.begin(), word.end());
			ans.append(word);
		}
		else {
			ans.push_back(str[i]);
			i--;
		}
	}
	return ans;
}

int main() {
	string str;
	getline(cin, str);

	cout << reverseLine(str);

	return 0;
}