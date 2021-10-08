// WithoutVF.cpp

#include<bits/stdc++.h>
using namespace std;

// base class
class A {
	int x = 5;
public:
	void display() {
		cout<<"In class A : "<<x;
	}
};

// derived class
class B : public A{
	int y = 5;
public:
	void display() {
		cout<<"In class B : "<<y;
	}
};
	
int main() {
	// pointer to base class
	A *bs;
	// object of derived class
	B b;
	// assign the refernce of dericed object to the base ptr
	bs = &b;

	bs->display();

	return 0;
}

// The pointer can only access the base class members 
// but not the members of the derived class. 
// Although C++ permits the base pointer 
// to point to any object derived from the base class, 
// it cannot directly access the members of the derived class. 
// Therefore, there is a need for virtual function which allows 
// the base pointer to access the members of the derived class.