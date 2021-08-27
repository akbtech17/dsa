// 3-JohnKnowsNothing.cpp
#include<bits/stdc++.h>
using namespace std;

int minLength = INT_MAX;

void findMinLength(string A, string D, string E, string F) {
	size_t idx_D = A.find(D);
	size_t idx_E = A.find(E);
	size_t idx_F = A.find(F);

	if(idx_D == string::npos and idx_E == string::npos and idx_F == string::npos) {
		minLength = min(minLength, int(A.size()));              
		return;
	}

	if(idx_D != string::npos) {
		string temp(A);
		temp.erase(idx_D, int(D.size()));
		findMinLength(temp,D,E,F);        
	}
	
	if(idx_E != string::npos) {
		string temp(A);
		temp.erase(idx_E, int(E.size()));
		findMinLength(temp,D,E,F);         
	}
	
	if(idx_F != string::npos) {
		string temp(A);
		temp.erase(idx_F, int(F.size()));
		findMinLength(temp,D,E,F);         
	}
	
	return;
}


int main() {
	string A("aaabccd");
	string D("abc");
	string E("ac");
	string F("aaa");


	
	findMinLength(A, D, E, F);
	cout<<minLength<<endl;
	
	return 0;
}