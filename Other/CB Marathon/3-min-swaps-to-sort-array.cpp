// 3 - min - swaps - to - sort - array.cpp
#include <iostream>
#include <algorithm>
using namespace std;


int findMinSwaps(int* arr, int n) {
	int min_swap = 0;
	pair<int, int> p[1000];
	//created pair of array and its org indices
	for (int i = 0; i < n; ++i)	{
		p[i] = make_pair(arr[i], i);
	}
	//sort the pair arr - default on the basic of first value
	sort(p, p + n);
	// for (int i = 0; i < n; ++i)	{
	// 	cout << p[i].first << " " << p[i].second << endl;
	// }
	bool isvis[n] = {0};
	for (int i = 0; i < n; ++i)
	{
		int noe = 0;
		int idx = i;
		//if the curr element is sorted or curr indx is visited
		if (p[i].second == i or isvis[i] == true) continue;
		//check if it is not visited
		while (isvis[idx] == false) {
			//no of el increment
			noe++;
			isvis[idx] = true; //mark as vis
			idx = p[idx].second; //update the next index on which it is possible to go next
		}
		//if the cycle have any elements
		if (noe > 0) min_swap += (noe - 1);
	}
	return min_swap;
}

int main() {
	int arr[] = {1, 2, 5, 4, 3};
	int n = sizeof(arr) / sizeof(n);
	cout << findMinSwaps(arr, n);

	return 0;
}