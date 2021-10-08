// 14_MergeIntervals.cpp
// https://leetcode.com/problems/merge-intervals/

// TC - O(NlogN){to sort} + O(N){to traverse}
// SC - O(1) {inplace}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        // 1 - Sort the Intervals based on Starting Time
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        // 2 - Ptr to trace the non overlapped Intervals
        //     as 1st interval will never be an overlapped, 
        //     if it is alone
        int prev = 0;

        // 3 - start iteration of intervals, from 2nd interval
        for(int i=1; i<n; i++) {
            // if the starting of next el is <= prev interval
            // then they are overlapping
            if(intervals[i][0] <= intervals[prev][1]) {
                // merge the curr interval, with the prev one
                intervals[prev][0] = min(intervals[prev][0], intervals[i][0]);                             
                intervals[prev][1] = max(intervals[prev][1], intervals[i][1]);   
            }
            else {
                // then to store the new not overlapping interval
                // first increment the prev ptr
                prev++;
                intervals[prev][0] = intervals[i][0];                                                     
                intervals[prev][1] = intervals[i][1];
            }
        }
        
        intervals.resize(prev+1);
        return intervals;
    }
};

int main() {
	Solution S;
	vector<vector<int>> ans = S.merge({{1,3},{2,6},{8,10},{15,18}});

	for(auto v : ans) {
		for(auto el : v) cout<<el<<" ";
		cout<<endl;
	}

	return 0;
}