// 2-SortTheArrayQuadraticEquation.cpp

// https://www.geeksforgeeks.org/sort-array-applying-given-equation/

// We have an integer array that is sorted in ascending order. 
// We also have 3 integers A, B and C. We need to apply A*x*x + B*x + C for 
// each element x in the array and sort the modified array. 

#include<bits/stdc++.h>
using namespace std;

int transform(int x, int a, int b, int c) {
	return a*x*x + b*x + c;
}

vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
	int i = 0;
	int j = nums.size()-1;

	vector<int>out(nums.size());

	if(a>=0) {
		// i have +ve parabola, fill from right to left
		int k = out.size()-1;
		while(i<=j) {
			if(transform(nums[i],a,b,c)>transform(nums[j],a,b,c)) {
				out[k] = transform(nums[i],a,b,c);
				i++;
			}
			else {
				out[k] = transform(nums[j],a,b,c);
				j--;
			}
			k--;
		}
	}
	else {
		// i have -ve parabola, fill from eft to right
		int k = 0;
		while(i<=j) {
			if(transform(nums[i],a,b,c)<transform(nums[j],a,b,c)) {
				out[k] = transform(nums[i],a,b,c);
				i++;
			}
			else {
				out[k] = transform(nums[j],a,b,c);
				j--;
			}
			k++;
		}
	}

	return out;
}

int main() {
	vector<int>nums({-4,-2,2,4});
	vector<int> v1 = sortTransformedArray(nums,1,3,5);
	vector<int> v2 = sortTransformedArray(nums,-1,3,5);

	for(auto el : v1) cout<<el<<" ";
	cout<<endl;
	for(auto el : v2) cout<<el<<" ";

	return 0;
}