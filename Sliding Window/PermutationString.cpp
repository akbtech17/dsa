// PermutationString.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1, mp2;
        for(auto ch: s1) mp1[ch]++;
        
        int s = 0;
        int e = 0;
        
        int n1 = s1.size();
        int n2 = s2.size();
        int cfsf = 0;
        
        while(e < n2) {
            char ch = s2[e];
            mp2[ch]++;
            if(mp1.count(ch)>0 and mp1[ch] >= mp2[ch]) cfsf++;
            int ws = e-s+1;
            if(ws < n1) {
                e++;
            }
            else if(ws == n1) {
                // cout<<ws<<":";
                // cout<<s2.substr(s,ws)<<endl;
                if(cfsf == n1) return true;
                cout<<s2.substr(s,ws)<<":"<<cfsf<<endl;
                mp2[s2[s]]--;
                if(mp1.count(s2[s])>0 and mp2[s2[s]] < mp1[s2[s]]) 
                    cfsf--;

                s++;
                e++;
            }
        }
        return false;
    }
};

int main () {
	Solution S;
	cout<<S.checkInclusion("ab","eidbaooo");

	return 0;
}