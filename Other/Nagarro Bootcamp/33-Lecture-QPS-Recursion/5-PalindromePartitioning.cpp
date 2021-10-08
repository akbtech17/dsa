// 5-PalindromePartitioning.cpp
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {
	int s = 0;
	int e = str.size()-1;

	while(s<e) {
		if(str[s]!=str[e]) return false;
		s++;
		e--;
	}
	return true;
}

void recurse(string s, vector<string> v) {
	if(s.size() == 0) {
		//print the partition
		for(int i=0;i<v.size();i++) {
			cout<<v[i];
			if(i+1 != v.size()) cout<<":";
		}
		cout<<endl;
		return;
	}

	string part;
	for(int i=0;i<s.size();i++) {
		part = s.substr(0,i+1);
		if(isPalindrome(part)) {
			//push in the list 
			v.push_back(part);
			recurse(s.substr(i+1),v);
			v.pop_back();
		}
	}
	return;
}

int main() {
	string s = "aabcb";
	vector<string> v;
	recurse(s,v);
	return 0;
}