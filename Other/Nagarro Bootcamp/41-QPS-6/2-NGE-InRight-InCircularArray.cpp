// 2-NGE-InRight-InCircularArray.cpp
// https://leetcode.com/problems/next-greater-element-ii/
// tc linear
// sc linear
#include<iostream>
#include<vector>
#include<stack>
using std::vector;
using std::cout;
using std::endl;
using std::stack;

#define pb push_back
#define vi vector<int>


vi Ngr(vi &arr) {
	stack<int> stk;
	int n = arr.size();
	vi ans(n);

	for(int i=n-1;i>=0;i--) {
		while(stk.empty() == false and stk.top()<=arr[i]) 
			stk.pop();
			ans[i] = stk.empty() == true  ? -1 : stk.top();
			stk.push(arr[i]);
	}
	return ans;
}


vector<int> nextGreaterElements(vector<int>& nums) {
  	// vi ans(nums.size());
  	vi temp(nums);
  	for(auto el : nums) temp.pb(el);
    vi ngr = Ngr(temp);
	int n = nums.size();
	while(n--) ngr.pop_back();

  	return ngr;
}

int main() {
	vi v({1,2,1});

	vi ans = nextGreaterElements(v);
	for(auto el : v) cout<<el<<" ";
	cout<<endl;
	for(auto el : ans) cout<<el<<" ";
	return 0;
} 