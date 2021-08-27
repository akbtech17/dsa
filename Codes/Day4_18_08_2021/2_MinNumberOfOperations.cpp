// 2_MinNumberOfOperations.cpp
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	void printAns(vector<int> v){ 
		for(auto el : v) cout<<el<<" ";
		cout<<endl;
		return ;
	}
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);

        for(int i=0; i<boxes.size(); i++) {
        	int ccnt = 0;
        	// cout<<"box :: "<<i<<endl;
        	for(int j=0; j<boxes.size();j++) {
        		if(i == j or boxes[j] == '0') continue;
        		int disp = 0;
        		// cout<<j<<endl;
        		// cout<<"i-j"<<i-j<<endl;
        		if(boxes[j] == '1') {
        			if(j>i) disp = j-i;
        			else disp = i-j;
        		}
        		ccnt += disp;
        		// cout<<disp<<" ";
        	}
        	// cout<<endl;
        	ans[i] = ccnt;
        }
        printAns(ans);
        return ans;
    }
};

int main() {
	Solution S;
	S.minOperations("110");
	S.minOperations("001011");
	return 0;
}