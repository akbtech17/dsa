// reverse - a - word - in - a - line.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWordInLine(string str) {
	string ans;

	for (int i = 0; i < str.length();) {
		if (str[i] != ' ') {
			//extract the word
			string word;
			while (i < str.length() and str[i] != ' ') {
				word.push_back(str[i++]);
			}
			reverse(word.begin(), word.end());
			ans.append(word);
		}
		else {
			ans.push_back(str[i]);
			i++;
		}
	}

	return ans;
}


int main() {
	string str;
	getline(cin, str);

	cout << reverseWordInLine(str);

	return 0;
}