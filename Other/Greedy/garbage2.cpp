#include <iostream>
#include <algorithm>
#include <limits.h>
#include <math.h>
#define ll long long
using namespace std;

bool isInverse(ll num) {
	int cpos = 1;
	ll temp = num;
	int arr[100000] = {0};
	while (temp) {
		arr[cpos] = temp % 10;
		cpos++;
		temp /= 10;
	}

	for (int i = 1; i < cpos; ++i)
	{
		// cout << arr[i];
		if (arr[arr[i]] != i) return false;
	}

	return true;
}

int32_t main()
{
	int t;
	cin >> t;
	while (t--) {
		ll num;
		cin >> num;
		if (isInverse(num)) cout << "true\n";
		else cout << "false\n";
	}
	return 0;
}