// discoverPeakNumber.cpp
#include <iostream>
using namespace std;

bool havePeakElement(int* arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (i == 0) {
			if (i + 1 < n and arr[i]>arr[i + 1]) return true;
		}
		else if (i == n - 1) {
			if (i - 1 >= 0  and arr[i] > arr[i - 1]) return true;
		}
		else {
			if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1]) return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (havePeakElement(arr, n)) cout << "true";
	else cout << "false";

	return 0;
}