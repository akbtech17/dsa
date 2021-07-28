// 3-JohnKnowsNothing.cpp
#include<bits/stdc++.h>
using namespace std;

int recurse(string str, string s1, string s2, string s3) {
	if(str.empty()) return 0;
	int l1 = binary_search(str.begin(),str.end(),s1);
	int l2 = binary_search(str.begin(),str.end(),s1);
	int l3 = binary_search(str.begin(),str.end(),s1);

	// if
	return 0;
}

int main() {
	// cout<<solve("aaabccd","abc","ac","aaa")<<endl;
	string s1 = "anshul bansal";
	int n = binary_search(s1.begin(),s1.end(),"l b");
	cout<<n;
	return 0;
}