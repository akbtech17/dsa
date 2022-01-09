// 8_PositiveNegativePairs.cpp
// Question - https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1#
// Code - https://ide.codingblocks.com/s/650086
#include <bits/stdc++.h>
using namespace std;

// A1 - Bruteforce
// TC - O(N^2)
// SC - O(N)

// A2 - Using Map/Set
// Twist: 1- We have to return those pairs 1st, of which
//           we get closing partner close
//        2- Pairs should be in INC order.

// so for ith number, we will check if we have got its pair 
// previously, if yes, we will add them to our ans,
// and for ith num, add them to our map/set to keep track

// TC - O(N^2)
// SC - O(N)

class Solution{
  public:
    vector <int> findPairs(int arr[], int n) {
       vector<int> ans;
       unordered_map<int,int> mp;
       
       for(int i = 0; i<n; i++){
           if(mp.count(-1*arr[i]) != 0){
               ans.push_back(-1*abs(arr[i]));
               ans.push_back(abs(arr[i]));
           }
           mp[arr[i]] = 1;
       }
       return ans;
   }
};