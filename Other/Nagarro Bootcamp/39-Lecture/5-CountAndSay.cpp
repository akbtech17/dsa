// 5-CountAndSay.cpp
// https://leetcode.com/problems/count-and-say/

#include<bits/stdc++.h>
using namespace std;

string say(string str) {
	string ans = "";
	for(int i=0;i<str.size();i++) {
		int fre = 1;
		int ch = str[i];
		while(i+1<str.size() and str[i] == str[i+1]) {
			fre++;
			i++;
		}
		string s1 = to_string(fre);
		ans.append(s1);
		ans += ch;
	}

	return ans;
} 

string countAndSay(int n) {
	// base case
	if(n == 1) return "1";
	return say(countAndSay(n-1));
}

int main() {
	cout<<countAndSay(1)<<endl;
	cout<<countAndSay(4)<<endl;
	// cout<<countAndSay(6)<<endl;
	// cout<<say("3322251")<<endl;	
	return 0;
}