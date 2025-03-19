#include <iostream>
using namespace std;

// Approach1: Bruteforce
// TC: O(N^2)
// SC: O(1)
class Solution1 {
public:
  vector<int> nextLargerElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[j] > nums[i]) {
          ans[i] = nums[j];
          break;
        }
      }
    }

    return ans;
  }
};

// Approach2: Monotonic Stack
// TC: O(N)
// SC: O(N)
class Solution2 {
public:
  vector<int> nextLargerElement(vector<int> &nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--) {
      // 1. Pop all elements smaller and equal than current element
      while (!stk.empty() && stk.top() <= nums[i])
        stk.pop();
      // 2. Store the answer
      ans[i] = stk.empty() ? -1 : stk.top();
      // 3. Push the current element
      stk.push(nums[i]);
    }

    return ans;
  }
};

int main() {
  Solution2 sol;
  vector<int> nums = {1, 3, 2, 4};

  vector<int> ans = sol.nextLargerElement(nums);
  for (int el : ans)
    cout << el << " ";

  return 0;
}