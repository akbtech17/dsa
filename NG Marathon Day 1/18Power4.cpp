// 18Power4.cpp
#include <iostream>
using namespace std;

bool isPower4(int num) {

	for (int i = 0; i < 2; i++) {
		if (num <= 0) return false;
		if ((num & 1) == 1) return false;
		num >>= 1;
	}
	if (num <= 0) return false;
	return true;
}

int main() {
	int num;
	cin >> num;
	if (isPower4(num)) cout << "True";
	else cout << "False";

	return 0;
}