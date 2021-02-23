// rainwater - harvesting.cpp
#include <iostream>
#define MX 100000
using namespace std;

int waterTrapped(int* buildings, int n) {
	int right[MX] = {0}, left[MX] = {0};
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
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int water = min(left[i], right[i]) - buildings[i];
		if (water > 0) ans += water;
	}
	return ans;
}

int main() {
	int buildings[MX] = {0};
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> buildings[i];

	cout << waterTrapped(buildings, n);

	return 0;
}