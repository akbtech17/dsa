// 8-ReverseStringWithoutUsingTemp.cpp

#include<bits/stdc++.h>
using namespace std;

string reverseString(string s) {
	int i = 0; 
	int j = s.size()-1;

	while(i<j) {
		s[i] = s[i]^s[j];
		s[j] = s[i]^s[j];
		s[i] = s[i]^s[j];

		i++;
		j--;
	}

	return s;
}

int main() {
	cout<<reverseString("abc");

	return 0;
}