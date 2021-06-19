// vw1-longest-substring-without-repeating-chars.cpp
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string str) {
	int s = 0;
	int e = 0;
	int ans = 0;

	map<char,int> mp;
	int rep = 0;
	while(e<str.size()) {
		// include current calc
		mp[str[e]]++;
		if(mp[str[e]] > 1) rep++;
		// if unique
		if(rep == 0) {
			ans = max(ans,e-s+1);
			e++;
		}

		// if not unique - shrink till it become unique
		else {
			while(s<e and rep!=0) {
				// shrink
				
				mp[str[s]]--;
				if(mp[str[s]] == 1) rep--;
				s++;
			}
			e++;
		}

		// for(auto p : mp ) {
		// 	cout<<p.first<<":"<<p.second<<" "; 
		// }
		// cout<<"rep:"<<rep<<endl;
	} 	
	return ans;	
}

int main() {
	string s = "pwwkew";
	cout<<lengthOfLongestSubstring(s)<<endl;

	return 0;
}