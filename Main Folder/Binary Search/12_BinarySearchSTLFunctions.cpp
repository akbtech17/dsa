// 12_BinarySearchSTLFunctions.cpp
// https://www.geeksforgeeks.org/binary-search-functions-in-c-stl-binary_search-lower_bound-and-upper_bound/
// https://ide.codingblocks.com/s/639530

// TC - O(LogN)
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> &nums, int key) {
	// binary_search(start_ptr, end_ptr, num)
	// return type - bool(true/false)
	return binary_search(nums.begin(), nums.end(), key);
}

int lowerBound(vector<int> &nums, int key) {
	// lower_bound(start_ptr, end_ptr, num)
	// return the ptr to the first element == key or the first el > key
 	return lower_bound(nums.begin(),nums.end(),key)-nums.begin();
}

int upperBound(vector<int> &nums, int key) {
	// upper_bound(start_ptr, end_ptr, num)
	// return the ptr to the last element == key or the first el > key
	return upper_bound(nums.begin(),nums.end(),key)-nums.begin();
}

int main() {
	vector<int> v1({1,2,4,5,6,6,6,6,7});
	cout<<isPresent(v1,6)<<endl;
	cout<<isPresent(v1,0)<<endl;

	cout<<lowerBound(v1,6)<<endl;
	cout<<lowerBound(v1,3)<<endl;

	cout<<upperBound(v1,6)<<endl;
	cout<<upperBound(v1,3)<<endl;

	return 0;
}