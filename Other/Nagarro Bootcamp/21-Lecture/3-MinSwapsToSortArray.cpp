// 3 - MinSwapsToSortArray.cpp
// check - https://ide.codingblocks.com/s/654403
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int countMinSwaps(int arr[], int n) {
	//make arr of pairs of elmenent with their given postions
	pair<int, int> *temp = new pair<int, int>[n];
	for (int i = 0; i < n; ++i) {
		temp[i] = make_pair(arr[i], i);
	}
	//sort them wrt to elements
	sort(temp, temp + n);

	//ab cycles find krni hai
	bool *isVis = new bool[n];
	memset(isVis, 0, n);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		//if current cell is vis, dont check na
		if (isVis[i] == true) continue;
		//if elelment was at same loc
		if (temp[i].second == i) continue;

		//start finding cycles
		if (isVis[i] == false) {
			int t = i;
			int no_of_el = 0;
			while (isVis[t] == false) {
				//mark isVis
				isVis[t] = true;
				//go to next step
				t = temp[t].second;
				no_of_el++;
			}
			if (t == i) {
				//ans mil gya - no of swap to sort cyclce = noe -1
				ans += no_of_el - 1;
			}
		}
	}
	return ans;
}

int main() {
	int arr[] = {7,16,14,17,6,9,5,3,18};
	int n = sizeof(arr) / sizeof(int);
	cout << countMinSwaps(arr, n);
	return 0;
}
