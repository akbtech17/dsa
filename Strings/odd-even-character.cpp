// odd - even - character.cpp

// Take as input S, a string.
// Write a function that replaces every
// odd character with the character having
// just higher ascii code and every even character
// with the character having just lower ascii code.
// Print the value returned.

#include <iostream>
#define MX 100000
using namespace std;

char* oddEvenChar(char* str) {
	for (int i = 1; str[i - 1] != '\0'; ++i) {
		if ((i % 2) != 0)
			str[i - 1] += 1;
		else
			str[i - 1] -= 1;
	}
	return str;
}

int main() {
	char str[MX];
	cin.getline(str, MX);

	cout << oddEvenChar(str);

	return 0;
}