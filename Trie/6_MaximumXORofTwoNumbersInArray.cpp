// 6_MaximumXORofTwoNumbersInArray.cpp
// Question Link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Solution Link - 
// Resource - https://www.youtube.com/watch?v=OUNfpFswJq8
#include <bits/stdc++.h>
using namespace std;


// A1: Bruteforce (N^2) => TLE
// A2: Using Trie
//     Idea is to try to find the number,
//     which can maximise the msb's of the curr number
// TC: O(N*32)
// SC: O(N*32)
class TrieNode {
public:
    TrieNode *left, *right;
    TrieNode() : left(nullptr) ,right(nullptr) {}
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        
        TrieNode *curr = root;

        for(int bidx=30; bidx>=0; bidx--) {
            
            int mask = (1<<bidx);
            int ibit = (mask&num)>0 ? 1 : 0;
            
            if(ibit == 0) {
                if(curr->left == NULL) {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
            
            else {
                if(curr->right == NULL) {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }
    
    int find(int num) {
        TrieNode *curr = root;
        int ans = 0;

        for(int bidx = 30; bidx >= 0; bidx--) {
            int mask = (1<<bidx);
            int ibit = (mask&num)>0 ? 1 : 0;
            
            if(ibit == 0) {
            	// we have to look for 1
                if(curr->right == NULL) {
                    curr = curr->left;
                }
                else {
                    ans += pow(2,bidx);
                    curr = curr->right;
                }
            }
            else {
            	// we want 0
                if(curr->left == NULL) {
                	ans += pow(2,bidx);
                    curr = curr->right;
                }
                else {
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> nums) {
        Trie trie;
        for(auto el: nums) {
            trie.insert(el);
        }
        int ans = 0;
        for(auto el: nums) {
            int el2 = trie.find(el);
            // cout<<el2<<" ";
            ans = max(ans,el^el2);
        }
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.findMaximumXOR({3,10,5,25,2,8});
	return 0;
}