// MinWindowSubstring.cpp

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> t_map;        
        map<char,int> s_map;

        int ans = INT_MAX;
        for(auto el : t) t_map[el]++;
        int k = t.size();

        // cout<<"k :: "<<k<<endl;
       
        int st = 0;
        int i = 0;
        
        int start = -1;
        
        while(i < s.size()) {
            
            char ch = s[i];
            s_map[ch]++;
            
            if(t_map.count(ch) > 0 and s_map[ch] <= t_map[ch])
                k--;
            
            if(k == 0) {
                while(s_map[s[st]] > t_map[s[st]] and st<=i) {
                    s_map[s[st]]--;
                    st++;
                }
                int len = i-st+1;
                // cout<<"len::"<<len<<endl;
                if(len < ans) {
                    start = st;
                    ans = min(ans,len);
                }
                st;
            }
            i++;
        }
        // cout<<ans;
        return start == -1 ? "" : s.substr(start,ans);
    }
};


int main() {
	Solution S;
	cout<<S.minWindow("ADOBECODEBANC","ABC");
	return 0;
}