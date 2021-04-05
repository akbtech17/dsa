// character - type.cpp
#include <iostream>
using namespace std;

char charType(char ch) {
	if (ch >= 'a' and ch <= 'z') return 'L';
	else if (ch >= 'A' and ch <= 'Z') return 'U';
	return 'I';
}

int main() {
	char ch;
	cin >> ch;

	cout << charType(ch);

	return 0;
}