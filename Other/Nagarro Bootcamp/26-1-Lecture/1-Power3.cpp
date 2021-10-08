// 1 - Power3.cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfThree(int num) {
	float floatLog = log(num) / log(3);
	if (floatLog == int(floatLog)) return true;
	return false;
}

bool isPowerOfThree2(int num) {
	//mx power of 3 which can be stored in INT_MAX
	int largest_power_of_3 = pow(3, 19);
	if (largest_power_of_3 % num == 0) return true;
	return false;
}

int main() {
	cout << isPowerOfThree(9) << endl;
	cout << isPowerOfThree2(9) << endl;
	return 0;
}