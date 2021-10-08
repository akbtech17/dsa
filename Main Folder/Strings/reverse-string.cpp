// reverse - string.cpp
// permutation.cpp
#include <iostream>
#define MX 10000
using namespace std;

void reverseString(char *str, int len) {
	int s = 0;
	int e = len - 1;

	while (s < e) {
		swap(str[s], str[e]);
		s++;
		e--;
	}

	return;
}


int main() {
	char str[MX];
	cin.getline(str, MX);
	int len = 0;
	while (str[len] != '\0') len++;
	reverseString(str, len);
	cout << str;
	return 0;
}