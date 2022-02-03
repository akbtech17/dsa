// square - root - to - precision.cpp
#include <iostream>
#define ll long long
#define MX 100000
using namespace std;

float squareRootToPrecision(ll num, int p) {
	int s = 0;
	int e = num;
	float ans = 0.0;
	while (s <= e) {
		int m = (s + e) / 2;
		if ((m * m) == num) {
			ans = m;
			break;
		}
		else if ((m * m) > num) {
			e = m - 1;
		}
		else {
			ans = m;
			s = m + 1;
		}
	}

	//floating point
	float inc = 0.1;
	while (p--) {
		while (ans * ans <= num) {
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
	}

	return ans;
}



int main() {
	ll num;
	int p;
	cin >> num >> p;
	cout << squareRootToPrecision(num, p);

	return 0;
}
