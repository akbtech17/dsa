// 3-NGR-Circular-ConstSpace.cpp
// https://leetcode.com/problems/next-greater-element-ii/
// tc linear
// sc const
// using deque
#include<iostream>
#include<vector>
#include<deque>
using std::vector;
using std::cout;
using std::endl;
using std::deque; 

#define pb push_back
#define vi vector<int>


vector<int> nextGreaterElements(vector<int>& nums) {
  	
  	vi ngr(nums.size());
  	deque<int> stk;   
  	int n = nums.size(); 
  	
  	// first pass 
	// after the first pass
  	// 1-> we have in stk , 0th index as top and bottom most index as 
  	// 2-> the largest element
  	// 3-> top -> 0,.....,jth index(lasrgest element)
  	// 4-> we also know elements from , 0th idx to jth index have been computed
  	// 5-> in first pass, as they have the larget element jth idx always in their right

  	for(int i=n-1; i>=0; i--) {
  		while(stk.empty() == false and nums[stk.back()] <= nums[i]) 
  			stk.pop_back();
  		ngr[i] = stk.empty() ? -1 : stk.back();
		stk.push_back(i); 
  	}

  	int j = stk.front(); // idx of the lasrtgest element


  	// second pass 
  	// 1-> (j+1 idx to n-1 ) (somemight be also calculated)
  	// 2-> and their NGR lie in the left part,  
  	// 3-> also we have to check only 0th to jth idx, as we have to find the nearest
  	// 4-> j+1 idx to n-1 is already computed no need to again repush in stk

  	// for(auto el : stk) cout<<el<<" ";
  	// 	cout<<endl;

  	for(int i=n-1; i>j; i--) {
  		while(ngr[i] == -1 and stk.empty() == false and nums[stk.back()] <= nums[i]) {
       	// cout<<nums[i]<<"popped "<<stk.back()<<endl;
  			stk.pop_back();
  		}
  		if(ngr[i] == -1)
  			ngr[i] = stk.empty() ? -1 : stk.back();
  		// no push
  	}

  	for(int i=0;i<n;i++) {
  		if(ngr[i]!=-1) ngr[i] = nums[ngr[i]];
  	}
  	return ngr;
}

int main() {
	vi v({1,2,3,4,3});
	vi ans = nextGreaterElements(v);
	for(auto el : v) cout<<el<<" ";
	cout<<endl;
	for(auto el : ans) cout<<el<<" ";	
	return 0;
} 