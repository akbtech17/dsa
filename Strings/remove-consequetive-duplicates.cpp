// remove - consequetive - duplicates.cpp

// Take as input S, a string.
// Write a function that removes all consecutive duplicates.
// Print the value returned.

#include <iostream>
#include <ctype.h>
#define MX 100000
using namespace std;

int lenStr(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

void printRemoveDuplicates(char* str) {
	int n = lenStr(str);
	int curr_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cout << str[i];
		while (str[i + 1] != '\0' and  str[i] == str[i + 1]) i++;
	}
}

char* removeDuplicates(char* str) {
	int ans_idx = 0;
	char prev_char = str[0];
	for (int i = 1; str[i] != '\0'; ++i) {
		if (prev_char != str[i]) {
			prev_char = str[i];
			str[++ans_idx] = str[i];
		}
	}
	str[++ans_idx] = '\0';
	return str;
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	// printRemoveDuplicates(str);
	cout << removeDuplicates(str);
	return 0;
}