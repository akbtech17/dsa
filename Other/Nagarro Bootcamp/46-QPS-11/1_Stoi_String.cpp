// 1_Stoi_String.cpp
// https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long strToInt(string str) {
		long long int n = str.size();
		long long int res = 0;
		for(int i=0; i<n; i++) {
			if(!isdigit(str[i])) break;
			int cd = str[i]-'0';
			res = res*10 + cd;
		}
		return res;
	}
    int myAtoi(string s) {
        // 1 - Ignore White Spaces
        long long int i = 0;
        while(i<s.size() and s[i] == ' ') i++;
        s = s.substr(i);
        // 2 - Identify - Sign if any
        bool isNeg = false;
        // 3 - Convert the Remaining Digits into Long Long
        long long int res = 0;
        if(s[0] == '-' or s[0] == '+') {
        	if(s[0] == '-') isNeg = true;
        	res = strToInt(s.substr(1));
        	res = isNeg ? -res : res;
        }
        else res = strToInt(s);
        // 4 - Check the range of Long Long
        return res<INT_MIN ? INT_MIN : res>INT_MAX ? INT_MAX : res;
    }
};