// 1 - MinMaxUsingDivideNConquer.cpp
// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <iostream>
using namespace std;

pair<int, int> findMinMax(int arr[] , int s, int e) {
	pair<int, int> mm;
	//base case
	if (s == e) {
		mm.first = arr[s];
		mm.second = arr[s];
		return mm;
	}
	else if (e == s + 1) {
		if (arr[s] > arr[e])  {mm.first = arr[e]; mm.second = arr[s]; }
		else {mm.first = arr[s]; mm.second = arr[e];}
		return mm;
	}

	//size is greater than 2
	int mid = (s + e) / 2;

	pair<int, int> p1 = findMinMax(arr, s, mid);
	pair<int, int> p2 = findMinMax(arr, mid + 1, e);

	mm.first = p1.first < p2.first ? p1.first : p2.first;
	mm.second = p1.second > p2.second ? p1.second : p2.second;

	return mm;
}

int main() {
	int arr[] = { 1000, 11, 445, 1, 330, 3000};
	int n  = sizeof(arr) / sizeof(int);

	pair<int, int> mm = findMinMax(arr, 0, n - 1);

	cout << "min : " << mm.first << " max : " << mm.second;
	return 0;
}