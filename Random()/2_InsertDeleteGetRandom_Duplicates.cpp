// 2_InsertDeleteGetRandom_Duplicates.cpp
// Question - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Code - https://ide.codingblocks.com/s/649956
// Resource - https://www.youtube.com/watch?v=a-UYY_DvCBY&t=614s
#include <bits/stdc++.h>
using namespace std;

// Approach - using Rand(), vector, set(to improve complexcity) and hmap
// TC - O(1)
// SC - O(N)
class RandomizedCollection {
    unordered_map<int,set<int>> mp; // to map the element with their idx
    vector<int> nums; 				// to contain the org set of all numbers present (with duplicacy)
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        bool ans;
        // if element is present
        if(mp.count(val) != 0) ans = false;
        // else el is not present
        else ans = true;
        mp[val].insert(nums.size());
        nums.push_back(val);
        return ans;
    }
    
    bool remove(int val) {
        // if el is not present
        if(mp.count(val) == 0) return false;
        // else el is present
        
        // step1 - find the idx of the present val using hmap
        auto it = mp[val].end();
        it--;
        int ridx = *it;
        mp[val].erase(it);
        if(mp[val].empty()) mp.erase(val);
        // cout<<"ridx"<<ridx;
        
        // step2 - get the last idx
        int lidx = nums.size()-1;
        int lval = nums[lidx];
        // cout<<"lidx"<<lidx;
        
        // --important check--
        if(lidx == ridx) {
            nums.pop_back();
            return true;
        }
        
        // step3 - swap and delete the last element of the vector
        swap(nums[ridx],nums[lidx]);
        nums.pop_back();
        
        // step4 - update the swapped element's idx in hmap
        mp[lval].erase(mp[lval].find(lidx));
        mp[lval].insert(ridx);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

int main() {

}