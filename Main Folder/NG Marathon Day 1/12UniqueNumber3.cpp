// 12UniqueNumber3.cpp
#include <iostream>
#include <cmath>
using namespace std;

int findUN3(int arr[] , int n) {
	int bit_map[64] = {0};

	//fill bitmap
	for (int i = 0; i < n; ++i)
	{
		int num = arr[i];
		int pos = 0;
		while (num > 0) {
			if ((num & 1) == 1) {
				bit_map[pos]++;
			}
			num >>= 1;
			pos++;
		}
		//print bit_map

	}

	int ans = 0;
	for (int i = 0; i < 64; ++i) {
		bit_map[i] = bit_map[i] % 3;
		ans += (bit_map[i] * pow(2, i));
	}
	return ans;
}

int main() {
	int n = 7;
	int arr[100005] = {1, 1, 1, 2, 2, 2, 3};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << findUN3(arr, n);
	return 0;
}