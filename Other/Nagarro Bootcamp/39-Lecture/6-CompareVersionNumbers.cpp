// 6-CompareVersionNumbers.cpp
// https://leetcode.com/problems/compare-version-numbers/

#include<bits/stdc++.h>
using namespace std;

vector<string> getTokens(string str) {
	stringstream check1(str);
	vector<string> tokens;
	string intermediate;
	while(getline(check1, intermediate, '.')) {
		tokens.push_back(intermediate);
	}

	return tokens;
}

int compareVersion(string version1, string version2) {
	vector<string> t1,t2;
	t1 = getTokens(version1);    
	t2 = getTokens(version2);    
	int i = 0;
	int j =0;
	int n1 = t1.size();
	int n2 = t2.size();
	while(i<n1 and j<n2) {
		int num1 = stoi(t1[i]);
		int num2 = stoi(t2[i]);

		if(num1 == num2) {
			i++;
			j++;
			continue;
		}

		return num1<num2 ? -1 : 1;
	}

	while(i<n1) {
		int num1 = stoi(t1[i]);
		if(num1>0) return 1;
		i++;
	}

	while(j<n2) {
		int num2 = stoi(t2[j]);
		if(num2>0) return -1;
		j++;
	}
	// if(j<n2) return -1
	
	return 0;
}	

int main() {
	string version1 = "7.5.2.4", version2 = "7.5.3";
	cout<<compareVersion(version1,version2);

	return 0;
}