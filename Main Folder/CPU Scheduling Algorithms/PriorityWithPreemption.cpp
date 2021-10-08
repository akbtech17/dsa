// PriorityWithPreemption.cpp
#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
using namespace std;

class Process {
public:
	int arrTime;
	int exeTime;
	int priority;
	Process(int p, int e, int a) {
		priority = p;
		exeTime = e;
		arrTime = a;
	}
};

// this is an structure which implements the
// operator overloading
class MyComp {
public:
	bool operator()(Process const& p1, Process const& p2) {
		// if prio is same, sort them accor to arrival time
		if(p1.priority == p2.priority) {
			return p1.arrTime >= p2.arrTime;
		}
		// else sort wrt to prio
		return p1.priority < p2.priority; 
	}
};

int solve(int n,vi prio, vi exe, vi arr) {
	priority_queue<Process, vector<Process>, MyComp> pq;
	
	int itr = 0;
	int time = 0;

	while(itr<n) {
		// cout<<"time : "<<time<<endl;
		
		while(itr<n and arr[itr] == time) {
			pq.push(Process(prio[itr],exe[itr],arr[itr]));
			itr++;
		}
		if(!pq.empty() and pq.top().exeTime == 0) pq.pop();
		if(!pq.empty() and pq.top().exeTime >= 1) {
			Process tp = pq.top();
			pq.pop();
			tp.exeTime -= 1;
			pq.push(tp);
		}
		time++;
	}
	while(!pq.empty()) {
		if(pq.top().exeTime == 0) pq.pop();
		if(!pq.empty() and pq.top().exeTime >= 1) {
			Process tp = pq.top();
			pq.pop();
			tp.exeTime -= 1;
			pq.push(tp);
		}
		time++;
	}
	return time-1;
} 

int main() {
	cout<<solve(6,{2,1,2,2,1,2},{1,1,1,2,3,2},{0,0,2,2,5,7})<<endl;
	cout<<solve(1,{1},{5},{2})<<endl;
	return 0;
}