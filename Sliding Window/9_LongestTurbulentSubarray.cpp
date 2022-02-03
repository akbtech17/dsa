// vw3-longest_turbulent_subarray.cpp
// https://leetcode.com/problems/longest-turbulent-subarray/

// TC - O(N)
// SC - O(N)

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    void pv(vector<int> &v) {
        for(auto el : v) cout<<el<<":";
        return;
    }
    
    // try to find the Max Subarray with alternate 1 and -1
    int maxTurbulenceSize(vector<int> arr) {
        // if arr is of size <=2 then it is always true
        if(arr.size()<=1) return arr.size();
        
        
        int n = arr.size();
        // int ans = 0;
        
        vector<int> temp;
        for(int i=0; i<n-1; i++) {
            if(arr[i]<arr[i+1]) temp.pb(1);
            else if(arr[i]>arr[i+1]) temp.pb(-1);
            else temp.pb(0);
        }
        // pv(temp);
        // cout<<endl;
        
        int s = 0;
        int e = 0;
        int ans = 0;
        
        while(e < n-1) {
            // trying to find MTL including the eth el
            if(temp[e] == 0) {
                while(e<n-1 and temp[e] == 0) {
                    e++;
                }
                s = e;
            }
            if(e!=0 and e<n-1 and temp[e-1] == temp[e]) {
                s = e;
            }
            e++;
            // save the MTL till eth el
            if(s<=e and e<n) ans = max(e-s,ans); 
        }

        return ans+1;
    }
};


int main() {
    Solution S;
    cout<<S.maxTurbulenceSize({100,100,100})<<endl;          // 1
    cout<<S.maxTurbulenceSize({9,9})<<endl;                  // 1
    cout<<S.maxTurbulenceSize({0,1,1,0,1,0,1,1,0,0})<<endl;  // 5
    cout<<S.maxTurbulenceSize({4,8,12,16})<<endl;            // 2
	return 0;
}