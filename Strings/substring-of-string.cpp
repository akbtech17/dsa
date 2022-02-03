// substring - of - string.cpp
#include <iostream>
#define MX 10000
using namespace std;


void printSubstring(char *str, int len) {
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			for (int k = i; k <= j; ++k)
			{
				cout << str[k];
			}
			cout << endl;
		}
	}
	return;
}


int main() {
	char str[MX];
	cin.getline(str, MX);
	int len = 0;
	while (str[len] != '\0') len++;
	printSubstring(str, len);
	return 0;
}