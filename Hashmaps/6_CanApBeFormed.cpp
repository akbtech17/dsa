// 6_CanApBeFormed.cpp
// Question Link - 
// Solution Link - 
#include <bits/stdc++.h>
using namespace std;

// A1: Using 2 Loops
// TC: O(N^2)
// SC: O(1)

// A3: Using HMap
// TC: O(NLogN)
// SC: O(1)

// A3: Using HMap
// TC: O(N)
// SC: O(N)

bool canAPBeFormed(int *arr, int n) {
	int smallest, second_smallest;
	smallest = second_smallest = INT_MAX;

	for(int i=0; i<n; i++) {
		if(arr[i]<smallest) {
			second_smallest = smallest;
			smallest = arr[i];
		}
	}
}

int main() {

}