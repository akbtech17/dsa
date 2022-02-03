// leaders - in - an - arr.cpp
#include <iostream>
#include <ctype.h>
#include <climits>
#define MX 100000
using namespace std;


void printLeader(int* arr, int n) {
	if (n == 0) return ;
	int mx = INT_MIN;
	for (int i = n - 1; i >= 0 ; --i)
	{
		if (i == n - 1) {
			mx = arr[i];
			cout << arr[i] << " ";
			continue;
		}
		if (arr[i] >= mx) {
			cout << arr[i] << " ";
			mx = max(arr[i], mx);
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	int arr[100000] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	printLeader(arr, n);
	return 0;
}