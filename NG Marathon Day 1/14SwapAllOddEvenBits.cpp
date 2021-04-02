// 14SwapAllOddEvenBits.cpp
#include <iostream>
#include <cmath>
using namespace std;

int swapBits(int num) {
	int bit_map[64] = {0};
	int pos = 0;
	while (num > 0) {
		if ((num & 1) == 1) bit_map[pos] = 1;
		else bit_map[pos] = 0;
		pos++;
		num >>= 1;
	}
	// for (int i = 0; i < pos; ++i) {
	// 	cout << bit_map[i];
	// }
	// cout << endl;
	for (int i = 0; i < pos; i += 2) {
		swap(bit_map[i], bit_map[i + 1]);
	}
	// for (int i = 0; i <= pos; ++i) {
	// 	cout << bit_map[i];
	// }
	// cout << endl;

	int ans = 0;
	for (int i = 0; i <= pos; ++i) {
		ans += bit_map[i] * pow(2, i);
	}

	return ans;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		cout << swapBits(num) << endl;
	}

	return 0;
}