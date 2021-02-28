// queries - left - right - shift - on - array.cpp
#include <iostream>
#define MX 100000
using namespace std;

void querytype1(int* netRotation, int k, int n) {
	//decreasing netRotation, RS
	(*netRotation) = ((*netRotation) - k) % n;
	return;
}

void querytype2(int* netRotation, int k, int n) {
	//increasing netRotation ,LS
	(*netRotation) = ((*netRotation) + k) % n;
	return;
}


void querytype3(int netRotation, int L, int R, int* csum, int n) {
	L = (L + netRotation + n) % n;
	R = (R + netRotation + n) % n;

	//if left is before Right
	if (L <= R) cout << csum[R + 1] - csum[L] << endl;
	//if Right is before Left
	else cout << csum[n] + csum[R + 1] - csum[L] << endl;

	return;
}

void wrapper(int *arr, int n ) {
	int csum[n + 1];
	csum[0] = 0;
	for (int i = 1; i <= n; i++) csum[i] = csum[i - 1] + arr[i];
	int netRotation = 0;

	querytype1(&netRotation, 3, n);
	querytype3(netRotation, 0, 2, csum, n);
	querytype2(&netRotation, 1, n);
	querytype3(netRotation, 1, 4, csum, n);

	return;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	wrapper(arr, n);

	return 0;
}