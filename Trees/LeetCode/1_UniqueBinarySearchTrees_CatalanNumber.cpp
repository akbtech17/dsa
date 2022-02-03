// 1_UniqueBinarySearchTrees_CatalanNumber.cpp
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n2)
// DP Approach - BU

// Catalan Recursive
// C0 = 1
// C1 = 1
// C (n) = Summation [i=0->n-1] {C(i-1)*C(n-i-1)}

class Solution2 {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        unsigned long long int res = 0;
        for(int i=0; i<n; i++) {
            res += numTrees(i)*numTrees(n-i-1);
        }
        return res;
    }
};

class Solution3 {
public:
    int numTrees(int num) {
        vector<int> dp(num+1, 0);

        // Base Cases
        dp[0] = 1;
        dp[1] = 1;

        for(int n=2; n<=num; n++) {
            for(int i=0; i<n; i++) {
                dp[n] += dp[i]*dp[n-i-1];
            }
        }

        return dp[num];
    }
};

int main() {
	Solution3 S;
	
	cout<<S.numTrees(3)<<endl;
	cout<<S.numTrees(1)<<endl;

	return 0;
}