// 9_UglyNumber3.cpp
// https://leetcode.com/problems/ugly-number-iii/
// https://www.youtube.com/watch?v=0FMKNDEopR0


// Approach - 
// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
#define int long long

using namespace std;
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> arr(n+2,0);
        arr[1] = 1;
        int ptra = 1, ptrb = 1, ptrc = 1;
        
        for(int i=2; i<=n+1; i++) {
            int na = arr[ptra]*a;
            int nb = arr[ptrb]*b;
        	int nc = arr[ptrc]*c;

            int mn = min(na,min(nb,nc));
            if(mn == na) ptra++;
            if(mn == nb) ptrb++;
            if(mn == nc) ptrc++;

            arr[i] = mn;
        }
        for(auto el : arr) cout<<el<<" ";
        cout<<endl;
        return arr[n+1];
    }
};

int32_t main() {
	Solution S;
	cout<<S.nthUglyNumber(3,2,3,5)<<endl;
	cout<<S.nthUglyNumber(1000000000,2,217983653,336916467)<<endl;

	return 0;
}