// 4-RemoveDuplicates.cpp
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) {
	int n = nums.size();
	int len = 0;
	for(int itr=0;itr<n;itr++) {
		nums[len] = nums[itr];

		while(itr+1<n and nums[itr+1] == nums[itr]) 
			itr++;
		len++;
	}

	return len;
}

int main() {
	vector<int> v({1,2,3,3,3,4,4,5,5});

	int len = removeDuplicates(v);

	for(int i=0;i<len;i++) cout<<v[i]<<" ";

	return 0;
}