// string - compression.cpp

// Take as input S, a string.
// Write a function that does basic string compression.
// Print the value returned.
// E.g. for input “aaabbccds”
// print out a3b2c2d1s1.

#include <iostream>
#include <string>
#define MX 10000
using namespace std;

void printCompressedString(char* str) {
	for (int itr = 0; str[itr] != '\0'; itr++) {
		//mark the count
		int count = 1;
		//print the curr character
		cout << str[itr];
		while (str[itr + 1] != '\0' and str[itr] == str[itr + 1])
			count++, itr++;
		//print the count
		cout << count;
	}
}



//return the compressed string
string compressTheString(string str) {
	string ans;
	for (int i = 0; i < str.length(); ++i) {
		if (i == 0) {
			ans.push_back(str[i]);
			continue;
		}
		if (str[i] == str[i - 1]) {
			int count = 1;
			while (i < str.length() and str[i] == str[i - 1]) {
				count++;
				i++;
			}
			ans.append(to_string(count));
			i--;
		}
		else {
			ans.push_back(str[i]);
		}
	}
	return ans;
}

int main() {
	// char str[MX];
	string str;
	getline(cin, str);
	// printCompressedString(str);
	cout << compressTheString(str);

	return 0;
}