// is - odd - even.cpp
#include <iostream>
using namespace std;

bool isOdd(int num) {
	//check the last bit if its 1, the number is odd
	int lastBit = num & 1;
	if (lastBit == 1) return true;
	return false;
}

int main() {
	int num;
	cin >> num;

	if (isOdd(num)) cout << "odd";
	else cout << "even";

	return 0;
}