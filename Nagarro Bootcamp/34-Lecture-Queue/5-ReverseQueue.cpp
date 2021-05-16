// 5-ReverseQueue.cpp
//without using any other DS
#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q) {
	if(q.empty()) return;
	int fr = q.front();
	q.pop();
	reverse(q);
	q.push(fr);
	return;
}

void printQ(queue<int> q) {
	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return;
}

int main() {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	printQ(q);
	reverse(q);
	printQ(q);
	
	return 0;
}