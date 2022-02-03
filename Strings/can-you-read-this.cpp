// can - you - read - this.cpp
#include <iostream>
#define MX 100000
using namespace std;

void printInReadableForm(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		cout << str[i];
		if (str[i + 1] != '\0' and str[i + 1] >= 'A' and str[i + 1] <= 'Z') cout << endl;
	}
	return;
}

int main() {
	char str[MX];
	cin.getline(str, MX);

	printInReadableForm(str);

	return 0;
}