// 2-DegreeOfAnArray.cpp

// Given a non-empty array of non-negative integers nums, 
// the degree of this array is defined as the maximum frequency 
// of any one of its elements.

// Your task is to find the smallest possible length of 
// a (contiguous) subarray of nums, that has the same degree as nums.

// Bruteforce
// for every subarray, check their degree if equal to degree of org arr
// consider their min length
// for N length array we have N(N+2)/2 subarrays
// for N length, we take N time in
// TC => O(N^3)

// Approach - TC - O(N), SC - O(N)
// all possible candidates for ans, must have all the 
// occurences of mostly occured
// elements in it
// it make sure that we have degree of subarray = org array
// now we need to find the min length subarray out of it
// map<element, freq ,begining idx, last idx>
// jiski fre  sabse jyada hogi, unki length ka min humara ans hojayga


#include<bits/stdc++.h>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
	map<int,pair<int,pair<int,int>>> mp;    
	int n = nums.size();
	for(int i=0;i<n;i++) {
		if(mp.count(nums[i]) == 0) {
			mp.insert({nums[i],{1,{i,i}}});
		}
		else {
			mp[nums[i]].first++;
			mp[nums[i]].second.second = i;
		}
	} 
	int fre = -1;
	for(auto p : mp) {
		fre = max(p.second.first,fre);
	}  
	int len = INT_MAX;
	for(auto p : mp) {
		if(p.second.first == fre) {
			int clen = p.second.second.second-p.second.second.first+1;
			len = min(clen,len);
		}
	}
	return len;
}

int main() {
	vector<int> v({1,2,2,3,1,4,2});
	vector<int> v2({1,2,2,3,1});
	cout<<findShortestSubArray(v)<<endl;
	cout<<findShortestSubArray(v2)<<endl;

	return 0;
}

