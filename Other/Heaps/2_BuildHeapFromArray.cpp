// 2_BuildHeapFromArray.cpp
// Max Heap

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Heap {
	vector<int> heap;
public:
	Heap() {
		cout<<"Heap is Created!\n";
	}
	void upheapify(int idx) {
		// base case
		if(idx == 0) return;
		// find parent
		int pidx = (idx-1)/2;
		if(heap[pidx] < heap[idx]) {
			swap(heap[pidx],heap[idx]);
			upheapify(pidx);
			return;
		}
		// else
		return;
	}
	void push(int data) {
		heap.pb(data);
		upheapify(heap.size()-1);
		return;
	}
	void downheapify(int idx) {
		int lch = 2*idx + 1;
		int rch = 2*idx + 2;
		int n = heap.size(); 

		// base case
		if(lch >= n and rch >= n) return;

		int largestidx = idx;
		if(lch <= n and heap[lch] > heap[largestidx]) largestidx = lch;
		if(rch <= n and heap[rch] > heap[largestidx]) largestidx = rch;

		if(largestidx == idx) return;
		// else 
		swap(heap[largestidx],heap[idx]);
		downheapify(largestidx);
		return;
	}	
	void pop() {
		if(heap.size() == 0) {
			cout<<"heap is empty!";
			return;
		}
		// store the last element on the top
		heap[0] = heap[heap.size()-1];
 		// reduce the heap
		heap.resize(heap.size()-1);
		// perform downheapification
		downheapify(0);
		return;
	}
	int top() {
		if(heap.size() == 0) {
			cout<<"heap is empty!";
			return INT_MIN;
		}
		return heap[0];
	}
	bool empty() {
		return heap.size() == 0 ? true : false;
	}
	void printHeap() {
		while(!empty()) {
			cout<<top()<<" ";
			pop();
		}
		return;
	}
};

void buildHeap(vector<int> vals, Heap &heap) {
	for(auto el : vals) heap.push(el);
	heap.printHeap();
	return;
}

int main() {
	Heap myheap;
	buildHeap({3,4,2,5,1,7,9},myheap);
	return 0;
}