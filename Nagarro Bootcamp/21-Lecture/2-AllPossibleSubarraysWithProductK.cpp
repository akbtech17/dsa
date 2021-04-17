// 2 - AllPossibleSubarraysWithProductK.cpp

#include <iostream>
#include <algorithm>
using namespace std;

int countSubarrays(int arr[], int n, int k) {
	//sort - is mandatory
	sort(arr, arr + n);

	int s = 0;
	int e = 0;
	int prod = 1;
	int ans = 0;

	while (e < n) {
		//include calculations
		prod *= arr[e];
		if (prod >= k) {
			//remove calculations
			while (prod >= k and s < e) {
				prod /= arr[s++];
			}
		}
		//yha pe prod<k hoga
		//toh subarrays add krdo
		ans += e - s + 1;
		e++;
	}

	return ans;
}

int main() {
	int arr[] = {1, 2, 3, 4}, k = 8;
	int n = sizeof(arr) / sizeof(int);
	cout << countSubarrays(arr, n, k);

	return 0;
}