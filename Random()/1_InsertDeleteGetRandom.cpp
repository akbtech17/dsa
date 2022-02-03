// 1_InsertDeleteGetRandom.cpp
// Question - https://leetcode.com/problems/insert-delete-getrandom-o1/
// Code - https://ide.codingblocks.com/s/649955
// Resource - https://www.youtube.com/watch?v=UqrcuLv3BnA&t=84s
#include <bits/stdc++.h>
using namespace std;

// Approach - using Rand(), vector and hmap
// TC - O(1)
// SC - O(N)
class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val] = 1;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 0) return false;
        v.erase(find(v.begin(),v.end(),val));
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rid = rand()%v.size();
        return v[rid];
    }
};


int main() {

}