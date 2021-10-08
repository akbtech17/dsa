// 3-JohnKnowsNothing.cpp
#include<bits/stdc++.h>
using namespace std;

int minLength = INT_MAX;

void findMinLength(string A, string D, string E, string F) {
	// search for presence of substrings in main string
	size_t idx_D = A.find(D);
	size_t idx_E = A.find(E);
	size_t idx_F = A.find(F);

	// base case
	// if no substring is present in Main String
	if(idx_D == string::npos and idx_E == string::npos and idx_F == string::npos) {
		minLength = min(minLength, int(A.size()));              // int type casting, bytes->int
		return;
	}

	// case : if D is present in A
	if(idx_D != string::npos) {
		string temp(A);
		temp.erase(idx_D, int(D.size()));
		findMinLength(temp,D,E,F);         // case: removing D, A-D
	}
	// case : D is not removed (D might be present or absent here)
	
	// case : if E is present in A
	if(idx_E != string::npos) {
		string temp(A);
		temp.erase(idx_E, int(E.size()));
		findMinLength(temp,D,E,F);         // case: removing E, A-E
	}
	// case : E is not removed (E might be present or absent here)

	// case : if F is present in A
	if(idx_F != string::npos) {
		string temp(A);
		temp.erase(idx_F, int(F.size()));
		findMinLength(temp,D,E,F);         // case: removing F, A-F
	}
	// case : F is not removed (F might be present or absent here)
	// simply exit, all casses are checked!
	return;
}


int main() {
	string A("aaabccd");
	string D("abc");
	string E("ac");
	string F("aaa");

	// string A("abcdefabcd");
	// string D("ab");
	// string E("cd");
	// string F("e");
	
	findMinLength(A, D, E, F);
	cout<<minLength<<endl;
	
	return 0;
}