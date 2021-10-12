// 0_WhatArePriorityQueues.cpp

// Need - 
// suppose we are inserting a collection of data one by one, and at any point of time
// we wish to extract the element with highest/lowest priority from the collection of elements
// stored so far, in O(1) time, 

// We can impose three types of conditions on PQs -
// 1 - Min Priority Element
// 2 - Max Priority Element
// 3 - Heap with custom datattypes and comparator


// Technical Terms
// 0. It is basically an implementation of MinHeap/MaxHeap.
// 1. std::priority_queue is a container adaptor tha provides
//    constant time lookup of the largest OR smallest emelment.
// 2. By deafult std::vector is the container used inside.
// 3. Cost of insertion/deletion is logarithmic 
//    as upheapfication/perculate-up and downheapification/perculate-down
//    is involed which works in O(logN)
// 4. std::priority_queue is implemented internally using the following methods.
//    std::make_heap
//    std::push_heap
//    std::pop_heap


// some of the common methods :->
// 1 - empty() - true if the underlying container's size is 0, false otherwise.
// 2 - push()  - insert element.
// 3 - pop()   - removes the element on top of the priority_queue.
// 4 - size()  - returns the size of underlying container (unsigned integral type) O(1)
// 5 - top()   - returns the reference to the top element in the priority_queue.
// 6 - swap()  - to swap the PQs in O(1) => pq1.swap(pq2);


// Syntax
// std::priority_queue<datatype, underlying data structure, comparator> pq;

#include <iostream>
#include <queue>                     // header file which implements PQ
using namespace std;


class Person {
public: 
	int age;
	int height;

	Person(int n1, int n2) {
		age = n1;
		height = n2;
	}

	printPerson() {
		cout<<"age : "<<age<<", height : "<<height<<endl;
	}
};

// operator overloading
class CustomComparator {
public:
	bool operator()(Person const& p1, Person const& p2) {
		return p1.height < p2.height;   // descending sorting
		return p1.height > p2.height;   // ascending sorting
	}
};


int main () {
	// by default it is max heap
	priority_queue<int> maxHeap;

	// min heap
	priority_queue<int, vector<int>, greater<int>> minHeap; 

	// heap with custom datattypes and comparator
	priority_queue<Person, vector<Person>, CustomComparator> customHeap; 
	customHeap.push(Person(1,2));
	customHeap.push(Person(1,3));
	customHeap.push(Person(1,4));
	customHeap.push(Person(1,5));
	customHeap.push(Person(1,6));


	// print PQ
	while(customHeap.empty() == false) {
		Person top = customHeap.top();
		top.printPerson();
		customHeap.pop();
	}

	return 0;    
}