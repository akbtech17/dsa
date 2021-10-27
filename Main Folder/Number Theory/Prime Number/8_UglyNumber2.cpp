// 8_UglyNumber2.cpp
// https://leetcode.com/problems/ugly-number-ii/
// https://www.youtube.com/watch?v=Lj68VJ1wu84&t=881s


// Approach - 
// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1,0);
        arr[1] = 1;
        int ptr2 = 1, ptr3 = 1, ptr5 = 1;
        

        for(int i=2; i<=n; i++) {
            int n2 = arr[ptr2]*2;
            int n3 = arr[ptr3]*3;
        	int n5 = arr[ptr5]*5;

            int mn = min(n2,min(n3,n5));
            if(mn == n2) ptr2++;
            if(mn == n3) ptr3++;
            if(mn == n5) ptr5++;

            arr[i] = mn;
        }
        return arr[n];
    }
};

int main() {
	Solution S;
	cout<<S.nthUglyNumber(10)<<endl;
	cout<<S.nthUglyNumber(1)<<endl;

	return 0;
}