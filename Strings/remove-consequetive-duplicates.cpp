// remove - consequetive - duplicates.cpp
#include <iostream>
#include <ctype.h>
#define MX 100000
using namespace std;

int lenStr(char* str) {
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

void removeDuplicates(char* str) {
	int n = lenStr(str);


	int curr_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cout << str[i];
		while (str[i + 1] != '\0' and  str[i] == str[i + 1]) i++;
	}
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	// for (int i = 0; str[i] != '\0'; ++i) {
	// 	str[i] = tolower(str[i]);
	// }
	removeDuplicates(str);
	// cout << str;
	return 0;
}