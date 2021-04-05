// 13FindComplement.cpp
#include <iostream>
#include <cmath>
using namespace std;

int FindComplement(int num) {
	int bit_map[32] = {0};
	int pos = 0;
	while (num > 0) {
		if ((num & 1) == 1) bit_map[pos] = 0;
		else bit_map[pos] = 1;
		pos++;
		num >>= 1;
	}

	int ans = 0;
	for (int i = 0; i < pos; ++i) {
		ans += bit_map[i] * pow(2, i);
	}

	return ans;
}


int main() {
	int num = 5;
	cin >> num;
	cout << FindComplement(num);
}