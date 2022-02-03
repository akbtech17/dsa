// 7_RobotBoundedInACircle.cpp
// Question - https://leetcode.com/problems/robot-bounded-in-circle/
// Code - https://ide.codingblocks.com/s/650078
#include <bits/stdc++.h>
using namespace std;

// Approach - Linear Iteration
// after completing one set of instructions, 
// we have to track 2 casses -
// case 1 - if displacement is 0, means the commands are in loop
// case 2 - if direction is apart from N, then after 3 sequence of 
//          commands, it will repeat the same movement, ie in loop
// if these 2 casses showup, return true!
// TC - O(N)
// SC - O(1)

class Solution {
public:
    void moveAhead(int &i, int &j, int d) {
        switch(d) {
            // north
            case 0: 
                i++;
                break;
            // east
            case 1:
                j++;
                break;
            // south
            case 2:
                i--;
                break;
            // west
            case 3:
                j--;
                break;
        }
        return;
    }
    bool isRobotBounded(string instructions) {
        vector<char> directions({'N', 'E', 'S', 'W'});
        int i = 0;
        int j = 0;
        int d = 0;
        
        for(auto cm: instructions) {
            switch(cm) {
                case 'G' : 
                    moveAhead(i,j,d);
                    break;
                case 'L' : 
                    d = ((4+d)-1)%4;
                    break;
                case 'R' : 
                    d = (d+1)%4;
                    break;
            }
        }
        
        if(d != 0 or (i == 0 and j == 0)) return true;
        return false;
    }
};

int main() {
	Solution S;
	cout<<S.isRobotBounded("GGLLGG")<<endl;
	cout<<S.isRobotBounded("GG")<<endl;
	cout<<S.isRobotBounded("GL")<<endl;

	return 0;
}