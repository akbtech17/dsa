// ImplementationQueue.cpp
//Circular Queue
#include<bits/stdc++.h>
using namespace std;

class Queue {
	int *arr;
	int cs;
	int n;
	int f;
	int e;
public:

	Queue(int n = 5) {
		this->n = n;
		arr = new int[n];
		cs = f = 0;
		e = n-1;
	} 

	int front() {
		return arr[f];
	}

	int size() {
		return cs;
	}

	void push(int val) {
		if(cs == n) {
			cout<<"Queue OverFlow\n";
			return;
		}
		e = (e+1)%n;
		arr[e] = val;
		cs++;
		return;
	}
	void pop() {
		if(cs == 0) {
			cout<<"Queue UnderFlow\n";
			return;
		}	
		f = (f+1)%n;
		cs--;
		return;
	}

	bool empty() {
		return cs == 0;
	}

};

int main() {
	Queue q;
	cout<<q.size()<<endl;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	cout<<q.size()<<endl;

	while(!q.empty()) {
		cout<<q.front()<<":";
		q.pop();
	}

	return 0;
}