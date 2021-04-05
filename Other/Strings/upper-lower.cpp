// upper - lower.cpp
#include <iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;

	if (ch >= 'A' and ch <= 'Z') cout << "UPPERCASE";
	else if (ch >= 'a' and ch <= 'b') cout << "lowercase";
	else cout << "Invalid";
	return 0;
}