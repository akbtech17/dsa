// 17-CelebrityProblem.cpp
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// A celebrity is a person who is known to all but 
// does not know anyone at a party. 
// If you go to a party of N people, 
// find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party 
// uch that if an element of row i and column j  
// is set to 1 it means ith person knows jth person. 
// Here M[i][i] will always be 0.

#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
  	stack<int> stk;

  	// psuh all celeb in stack
  	for(int i=0;i<n;i++) {
  		stk.push(i);
  	}

  	//extract two celeb
  	int ans = -1;
  	while(!stk.empty()) {
  		int c1 = stk.top();
  		stk.pop();

  		if(stk.empty()) {
  			ans = c1;
  			break;
  		}
  		int c2 = stk.top();
  		stk.pop();

  		// now find which one is not celeb, insert the other one
  		if(M[c1][c2] == 1) stk.push(c2);
  		else if(M[c1][c2] == 0) stk.push(c1);
  	}

  	if(ans == -1) return -1;
  	// check if ans does not know anyone, he is confiemed celeb
  	for(int i=0;i<n;i++) {
  		if(M[ans][i] != 0) return -1;
  		if(i!=ans and M[i][ans] == 0) return -1;
  	}
  	return ans;
}

int main() {
	int N = 3;
	vector<vector<int>> M;
	M.push_back(vector<int>({0,0,0}));
	M.push_back(vector<int>({0,0,0}));
	M.push_back(vector<int>({0,0,0}));

	cout<<celebrity(M,N)<<endl;

	return 0;
}