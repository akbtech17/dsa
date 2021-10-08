// majorityElement.cpp
#include <iostream>
using namespace std;

//bruteforce
int findMajorityElement(int *arr, int n, int k) {
	int nByK = n / k;

	for (int i = 0; i < n; ++i)
	{
		int cnt = 1;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] == arr[i])cnt++;
		}
		if (cnt > nByK) return arr[i];
	}

	return -1;
}

//moore votings algorithm
//no extra space
//linear time
int findMajorityElement2(int *arr, int n, int k) {
	int cnt = 0;
	int nByK = n / k;
	int candidate ;
	for (int i = 0; i < n; ++i) {
		if (cnt == 0) {
			//if count is 0
			//mark curr element as
			//candidate for an answer
			candidate = arr[i];
		}
		if (arr[i] == candidate) cnt++;
		else cnt--;
	}
	//count the freq of candidate
	int freqOfCand = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == candidate) freqOfCand++;
	}
	if (freqOfCand > nByK) return candidate;
	return -1;
}


int main() {
	int arr[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int k = 2;
	// cout << findMajorityElement(arr, n, k) << endl;
	cout << findMajorityElement2(arr, n, k);
	return 0;
}