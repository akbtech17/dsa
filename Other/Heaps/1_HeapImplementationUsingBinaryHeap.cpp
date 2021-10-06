// 1_HeapImplementationUsingBinaryHeap.cpp
// Max Heap


// Implementaion of Heaps can be done in following ways - 

// 1 - Unsorted Arrays
// Insertion - O(1)
// Deletion - O(N) [need searching]
// Get - O(N) [need searching]

// 2 - Sorted Arrays
// Insertion - O(N) [need sorting, aka shifting of elements]
// Deletion - O(1) or O(N) [need searching + shifting]
// Get - O(N) or O(1) [need searching]

// 3 - Unsorted Lists
// Insertion - O(1)
// Deletion - O(N) [need searching]
// Get - O(N) [need searching]

// 4 - Sorted Lists
// Insertion - O(N) [need sorting, aka shifting of elements]
// Deletion - O(1) or O(N) [need searching + shifting]
// Get - O(N) or O(1) [need searching]

// 5 - BST 
// Insertion - O(h) 
// Deletion - O(h) 
// Get - O(h)
// and for BST height can be N(case of skewed tree) or logN 
// and in HBST it will be always LogN

// 6 - Binary Heap [Complete Binary Tree]
// Note - Every child has Priority less than the parent [in Max Heap]
// Insertion - O(logN) 
// Deletion - O(logN) 
// Get - O(1)


// What is Complete BT?
// Every Level except the last one is full 
// and the last level is filled from left to right/

// if K no of levels are present, 
// then Kth and K-1th all leaf node should be present
// this ensures the height = LogN





// Why only BT, not Ternary or Other Trees ?









// Types of Binary Heaps ?
// 1 - Min Heap [P(Root) is always less than P(Child)] 
// 2 - Max Heap [P(Root) is always greater than P(Child)] 



// How we can represent Heaps ?
// WE can use any Linear DS [Array, Lists, Vectors] using Level Order Traversal.
// Benefits - (1) it provides two way access, ie
//            from parent we can access its childs, and vice-versa.
//            (2) last level which might not be full, will not require an
//            extra memory to fulill the emptiness.

// if we store the parent on ith idx [in 0-based indexing]
// then position of its childs should be
// left  - 2*i+1 
// right - 2*i+2
// child(jth idx) -> parent floor((j-1)/2)




// Operations in Heap


// 1 - push() - insertion of values in heap
// First we will add the element in the last of our DS, 
// then we will upheapify(recursive fn), accoding to the type of Heap.

// 2 - upheapify() - Perculate UP [recursive fn]
// Base, if we reached to the root node, idx == 0, return.
// Recursive, find the parent, if p(par) > p(ch), swap, and upheapify for par
// else return.

// 3 - get() - getting the top-most element 
// simply return heap[0]

// 4 - pop() - deletion of the topmost element 
// overrite the topmost element with the last element
// shrink the heap by 1
// perform downheapification from 0th idx

// 5 - downheapify - Perculate DOWN [recursive fn]
// 

// 6 - empty() - checking whether heap is empty or not!


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