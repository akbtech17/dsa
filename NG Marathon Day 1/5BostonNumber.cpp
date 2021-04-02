// 5BostonNumber.cpp
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll CountDigitSum(int num) {
	ll sum = 0;
	while (num > 0) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

ll CountPFDigits(int num) {
	ll sum = 0;
	//cancelling num from 2
	while (num % 2 == 0) {
		sum += 2;
		num /= 2;
	}

	//n must be odd after this point
	//so consider finding odd factors
	for (int i = 3; i <= sqrt(num); i += 2)	{
		// for (int i = 3; i*i<=num; i+=2)	{
		int dig_sum = CountDigitSum(i);
		while (num % i == 0) {
			sum += dig_sum;
			num /= i;
		}
	}

	//if num is prime number greater than 2,
	//than it have not been converted 1 by above steps
	if (num > 2) {
		sum += CountDigitSum(num);
	}
	return sum;
}

bool isBostonNumber(int num) {
	//find sum of its digits
	ll sumDigits = CountDigitSum(num);
	//find sum of dig of PF
	ll sumPFDigits = CountPFDigits(num);

	if (sumDigits == sumPFDigits) return true;
	return false;
}

int main() {
	int num = 378;
	if (isBostonNumber(num)) cout << 1;
	else cout << 0;

	return 0;
}