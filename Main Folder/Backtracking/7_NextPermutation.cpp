// 7_NextPermutation.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    vector<vector<int>> allPermutations;
public:
    void permute(vector<int>& nums, int i=0) {
        int n = nums.size();
        if(i == n) {
            allPermutations.push_back(nums);
            return;
        }
        for(int j=i; j<n; j++) {
            swap(nums[i],nums[j]);
            permute(nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    bool isEqual(vector<int> &v1, vector<int> &v2) {
        for(int i=0; i<v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    } 
    void nextPermutation(vector<int>& nums) {
        nums = next_permutation(nums.begin(),nums.end());
    }
};

class Solution2 {
    vector<vector<int>> allPermutations;
public:
    void permute(vector<int>& nums, int i=0) {
        int n = nums.size();
        if(i == n) {
            allPermutations.push_back(nums);
            return;
        }
        for(int j=i; j<n; j++) {
            swap(nums[i],nums[j]);
            permute(nums,i+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    bool isEqual(vector<int> &v1, vector<int> &v2) {
        for(int i=0; i<v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    } 
    void nextPermutation(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permute(nums);
        for(auto v : allPermutations) {
            for(auto el : v) cout<<el<<",";
            cout<<endl;
        }
        for(int i=0; i<allPermutations.size(); i++) {
            if(isEqual(nums,allPermutations[i])) {
                if(i == allPermutations.size()-1)
                    nums = allPermutations[0];
                else nums = allPermutations[i+1];
                return;
            }
        }
        return;
    }
};

int main() {
	Solution1 S;
	vector<int> v({3,2,1});
	S.nextPermutation(v);

	for(auto el : v) cout<<el<<" ";

	return 0;
}