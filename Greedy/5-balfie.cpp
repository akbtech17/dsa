#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#define vi vector<int>
#define pi pair<int,int>
#define mi map<int,int>
#define mp make_pair
#define pb push_back
#define int long long

using namespace std;


int isPossibleToShiftJobs(int arr[], int n) {
	int req_job = 0;
	for (int i = 0; i < n; i++) req_job += arr[i];
	req_job /= n;

}

int32_t main() {
	int n;
	cin >> n;
	int arr[100000];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << isPossibleToShiftJobs(arr, n);
	return 0;
}