// 12StringToInteger.cpp
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int stringToInt(char* str, int n) {
	//base case
	if (n == 0) return 0;
	//recursive case
	int curr_dig = str[n - 1] - '0';
	int smaller_num = stringToInt(str, n - 1);
	return smaller_num * 10 + curr_dig;
	// return ans;
}

int main() {
	char str[] = "1";
	int n = sizeof(str) - 1;
	// PrintArr(a, n);
	cout << stringToInt(str, n);
	// PrintArr(a, n);
	return 0;
}
