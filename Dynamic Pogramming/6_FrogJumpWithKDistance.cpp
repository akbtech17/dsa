// 6_FrogJumpWithKDistance.cpp
// Problem Link - 
// Code Link - 
// Reference Link - 
#include<bits/stdc++.h>
using namespace std;

// A1 : 
// TC : O()
// SC : O() 
int helper(vector<int> &heights, int k, int idx) {
    if(idx == 0) return 0;

    int mn_cost = INT_MAX;
    for(int step=1; step<=k; step++) {
        if(idx-step>=0) {
            mn_cost = min(mn_cost, abs(heights[idx]-heights[idx-step]) + helper(heights, k, idx-step));
        }
    }
    return mn_cost;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> heights(n,0);
    for(int i=0; i<n; i++) cin>>heights[i];

    cout<<helper(heights,k,n-1);

    return 0;
}
