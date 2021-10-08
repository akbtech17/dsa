// is - palindrome.cpp
#include <iostream>
#define MX 100000
using namespace std;

bool isPalindrome(char* str) {
	int s = 0;
	int e = 0;

	while (str[e + 1] != '\0') e++;

	while (s <= e) {
		if (str[s] != str[e]) return false;
		s++;
		e--;
	}
	return true;
}

int main() {
	char str[MX];
	cin.getline(str, MX);

	if (isPalindrome(str)) cout << "true";
	else cout << "false";
	return 0;
}