// rainwater - harvesting.cpp
#include <iostream>
#define MX 100000
#define ll long long
using namespace std;

ll waterTrapped(int* buildings, int n) {
	int right[n] = {0}, left[n] = {0};
	int curr_mx = 0;
	for (int i = 0; i < n; ++i)
	{
		left[i] = curr_mx;
		curr_mx = max(curr_mx, buildings[i]);
	}
	curr_mx = 0;
	for (int i = n - 1; i >= 0 ; --i)
	{
		right[i] = curr_mx;
		curr_mx = max(curr_mx, buildings[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int water = min(left[i], right[i]) - buildings[i];
		if (water > 0) ans += water;
	}
	return ans;
}

int main() {

	int n;
	cin >> n;
	int buildings[n] = {0};
	for (int i = 0; i < n; ++i) cin >> buildings[i];

	cout << waterTrapped(buildings, n);

	return 0;
}