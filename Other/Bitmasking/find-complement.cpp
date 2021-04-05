// find - complement.cpp
#include <iostream>
#include <cmath>
using namespace std;


void findComplement(int &num) {
	///extract number of bits
	int nbits = floor(log2(num)) + 1;


	num = ((1 << nbits) - 1) ^ num;
	return ;
}

int main() {
	int num;
	cin >> num;

	findComplement(num);

	cout << num;

	return 0;
}