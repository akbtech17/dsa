// bitwisePalindrome.cpp
#include <iostream>
using namespace std;

bool isPalindrome(long long num) {
	int bits[64] = {0};
	int len = 0;
	while (num > 0) {
		int curr_bit = (num & 1);
		bits[len++] = curr_bit;
		num = num >> 1;
	}

	int s = 0;
	int e = len - 1;

	while (s <= e) {
		if (bits[s] != bits[e]) return false;
		s++;
		e--;
	}

	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long num;
		cin >> num;
		if (isPalindrome(num)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}