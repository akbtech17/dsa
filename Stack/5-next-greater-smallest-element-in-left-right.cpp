// 5 - next - greater - smallest - element - in - left - right
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int* ngr(int *arr, int n) {
	int ans[100000] = {0};
	stack<int> stk;
	for (int i = n - 1; i >= 0; --i)
	{
		while (!stk.empty() and stk.top() <= arr[i]) stk.pop();
		if (stk.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = stk.top();
		}
		stk.push(arr[i]);
	}
	return ans;
}

int main() {
	int n = 4;
	int arr[] = {1 , 3, 2, 4};
	int* ans;
	ans = ngr(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}