// 2 - all - possible - subarrays - with - product - k.cpp/
#include <iostream>
using namespace std;

int numberOfPossibleSubWithProdLessThanK(int* arr, int n, int k) {
	int s = 0;
	int e = 0;

	int ans = 0;
	int prod = 1;

	while (e < n) {
		//calculations
		prod *= arr[e];
		//reducing the size of the window
		while (prod >= k) {
			prod /= arr[s++];
		}
		ans += e - s + 1;
		e++;
	}
	return ans;
}

int main() {
	// int n;
	int arr[] = {1, 2, 3, 4};
	int n  = sizeof(arr) / sizeof(n);
	int k = 8;

	cout << "no of possible subarrays with prod less than k are " << numberOfPossibleSubWithProdLessThanK(arr, n, k);
	return 0;
}