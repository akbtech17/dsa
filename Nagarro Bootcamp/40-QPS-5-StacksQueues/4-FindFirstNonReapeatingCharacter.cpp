// 4-FindFirstNonReapeatingCharacter.cpp

// Input   : a a  b c 
// Output  : a -1 b b

#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<char> q;
	int fre[26] = {0};

	char ch;
	cin>>ch;

	while(ch!='.') {
		// add this char to queue
		q.push(ch);
		// then update its fre
		fre[ch-'a']++;

		while(!q.empty() and fre[q.front()-'a'] > 1) {
			q.pop();
		}
		if(q.empty()) cout<<"-1 ";
		else cout<<q.front()<<" ";

		cin>>ch;
	}

	return 0;
}