// toggle - case.cpp
#include <iostream>
#define MX 100000
using namespace std;

//using xor opertator
void toggleCase1(char* str) {
	for (int itr = 0; str[itr] != '\0'; itr++) {
		str[itr] ^= 32;
	}
	return;
}

//using ascii values
void toggleCase2(char* str) {
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 'a' - 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + 'A' - 'a';
	}
	return;
}

int main() {
	char str[MX];
	cin.getline(str, MX);
	// toggleCase1(str);
	toggleCase2(str);
	cout << str;
	return 0;
}