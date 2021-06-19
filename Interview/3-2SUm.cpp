// 3-2SUm.cpp
// 2sum.cpp
#include <iostream>
#include <algorithm>
#define MX 1000
using namespace std;


//approach 1 - bruteforce
//tc n square
//sc const
void printAllPairs(int arr[], int n, int target) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] == target - arr[i]) {
				if (arr[i] < arr[j]) cout << arr[i] << " and " << arr[j] << endl;
				else cout << arr[j] << " and " << arr[i] << endl;
			}
		}
	}

	return;
}

//approach 2 - 2pointer
//tc n
//sc const
void printAllPairs2(int arr[], int n, int target) {
	sort(arr, arr + n);
	int s = 0;
	int e = 0;

	while (s < e) {
		if (arr[s] + arr[e] == target) {
			cout << arr[s] << " and " << arr[e] << endl;
			s++;
		}
		else if (arr[s] + arr[e] < target) s++;
		else e--;
	}
	return;
}

int  main() {
	int n;
	cin >> n;
	int arr[MX] = {0};
	for (int i = 0; i < n; i++) cin >> arr[i];
	int target;
	cin >> target;
	printAllPairs(arr, n, target);
	printAllPairs2(arr, n, target);
	return 0;
}