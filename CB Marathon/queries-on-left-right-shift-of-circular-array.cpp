// queries - on - left - right - shift - of - circular - array.cpp
#include <iostream>
using namespace std;

// 4
// 1 3
// 3 0 2
// 2 1
// 3 1 4

void rightShift(int &net_rotation, int times, int n) {
	//we need to move net rotation in left direction
	net_rotation = (net_rotation - times) % n;
	return;
}
void leftShift(int &net_rotation, int times, int n) {
	//we need to move net rotation in right direction
	net_rotation = (net_rotation + times) % n;
	return;
}

int sumInRange(int *csum, int n, int L, int R, int net_rotation) {
	//calcultaion of exact/absolute values of left and right indices after rotation
	L = (L + net_rotation + n) % n;
	R = (R + net_rotation + n) % n;
	//if L is before or eq to R
	if (L <= R)
		return csum[R] - csum[L - 1];
	//else return
	return csum[n - 1] + csum[R] - csum[L - 1];
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);
	int q;
	cin >> q;
	int net_rotation = 0;

	int csum[n] = {0};
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			csum[i] = arr[i];
		}
		else {
			csum[i] = arr[i] + csum[i - 1];
		}
	}

	while (q--) {
		int type;
		cin >> type;
		int L, R;
		int x;
		switch (type) {
		case 1: cin >> x;
			rightShift(net_rotation, x, n);
			break;
		case 2: cin >> x;
			leftShift(net_rotation, x, n);
			break;
		case 3: cin >> L >> R;
			cout << sumInRange(csum, n, L, R, net_rotation) << endl;
			break;
		default : break;
		}
	}

	return 0;
}