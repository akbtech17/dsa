// 3_FindTheWinnerOfCircularGame_Recursion.cpp
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int recurse(vector<int> &friends, int k, int pos = 0) {
        if(friends.size() == 1) return friends[0];
        
        int n = friends.size();
        int rem = (pos+k)%n;
        pos = rem;
        auto it = friends.begin()+rem;
        
        // cout<<"removed "<<friends[pos]<<endl;
        friends.erase(it);
     
        return recurse(friends, k, pos);
    }
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for(int i=1;i<=n;i++) friends.push_back(i);
        return recurse(friends,k-1,0);
    }
};

int main() {
	Solution S;
	cout<<S.findTheWinner(5,2)<<endl;
	cout<<S.findTheWinner(6,5)<<endl;
}