// 1-NGE-InRight.cpp
// geeksforgeeks.org/next-greater-element/
#include <iostream>
#include <stack>
using std::cout;
using std::stack;
using std::endl;

void printNGR(int *arr, int n) {
	stack<int> stk;
	int *ans = new int[n];

	for(int i=n-1;i>=0;i--) {
		while(stk.empty() == false and stk.top()<=arr[i]) 
			stk.pop();
			ans[i] = stk.empty() == true  ? -1 : stk.top();
			stk.push(arr[i]);
	}
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" ";
	}
	return;
}

int main() {
	int arr[] = {8,2,7,4,3,6};
	int n = 6;
	
	printNGR(arr, n);

	return 0;
}