// vw2-KUniqueChar.cpp
#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string str, int k) {
    int s = 0;
    int e = 0;
    map<char,int> mp;
    int ans = 0;

    while(e<str.size()) {
    	mp[str[e]]++;
    	if(str[e] == 1) k--;
    	
    	if(k == 0) {
    		ans = 
    	}

    	if(k == 0) {
    		ans = max(ans,e-s+1);

    	}
    }

    return ans;
}


int main() {
	string S = "aabacbebebe";
	int K = 3;

	return 0;
}