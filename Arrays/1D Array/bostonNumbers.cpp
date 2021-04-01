// bostonNumbers.cpp
#include<iostream>
#include <cmath>
#define ll long long
using namespace std;

ll sumDigits(ll num) {
	ll ans = 0;
	while (num > 0) {
		ans += (num % 10);
		num /= 10;
	}
	return ans;
}

ll sumOfPFacts(ll num) {
	ll sum = 0;
	while (num % 2 == 0) {
		sum += 2;
		num /= 2;
	}
	for (int i = 3; i <= sqrt(num); i += 2) {
		while (num % i == 0) {
			sum += sumDigits(i);
			num /= i;
		}
	}
	if (num > 2) {
		sum += sumDigits(num);
	}
	return sum;
}



bool isBoston(ll num) {
	ll sum_of_digs = sumDigits(num);
	ll sum_of_pfacts = sumOfPFacts(num);
	// cout << endl << sum_of_digs << " " << sum_of_pfacts << endl;
	if (sum_of_digs == sum_of_pfacts) return true;
	return false;
}

int main() {
	ll num;
	cin >> num;

	if (isBoston(num)) cout << 1;
	else cout << 0;

	return 0;
}