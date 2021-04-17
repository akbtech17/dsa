// 3 - PrintAllSubsetSum.cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void printAllSubsetSum(int arr[] , int n, int i , int sum , bool *isVis) {
	//base case - if 0 elements
	if (i == n) {
		cout << "{";
		for (int k = 0; k < n; ++k) {
			if (isVis[k]) cout << arr[k] << ", ";
		}
		cout << "}";
		cout << " = " << sum << endl;
		return;
	}
	//recrsive case - for every ith number - two choices
	//dont include in sum
	printAllSubsetSum(arr , n, i + 1 , sum, isVis);
	//include in sum
	isVis[i] = true;
	printAllSubsetSum(arr , n, i + 1, sum + arr[i], isVis);
	//bactrack
	isVis[i] = false;
	return;
}


void printSubsetSum2(int arr[] , int n) {
	int no_of_subsets = (1 << n);//1<<n is 2 to the power n
	for (int num = 0; num < no_of_subsets; ++num) {
		int loc = 0;
		int sum = 0;
		int temp = num;
		cout << "{";
		while (temp > 0) {
			// extract the loc th bit
			int loc_th_bit = temp & (1) > 0 ? 1 : 0;
			if (loc_th_bit) {
				//include loc_th_temp
				sum += arr[loc];
				cout << arr[loc] << ", ";
			}
			temp = temp >> 1;
			loc++;
		}
		cout << "} = ";
		cout << sum << endl;
	}
	return;
}

int main() {
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(int);
	bool isVis[100] = {0};
	printAllSubsetSum(arr, n, 0, 0, isVis);
	printSubsetSum2(arr, n);
	return 0;
}