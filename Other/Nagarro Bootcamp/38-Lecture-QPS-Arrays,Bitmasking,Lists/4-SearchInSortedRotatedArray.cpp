// 4-SearchInSortedRotatedArray.cpp

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int s, int e, int key) {
        if(s>e) return -1;
        int mid = (s+e)/2;
        if(nums[mid] == key) return mid;
        // key lie in first pane
        if(nums[s]<=nums[mid]) {
            if(key>=nums[s] and key<=nums[key])
                return helper(nums,s,mid-1,key);
            else return helper(nums,mid+1,e,key);
        }
        //means key lie in second plane
        if(key>=nums[mid] and key<=nums[e]) 
            return helper(nums,mid+1,e,key);
        return helper(nums,s,mid-1,key);
}
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }