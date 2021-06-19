// 3-UsingPVF.cpp

#include<bits/stdc++.h>
using namespace std;

// base class - abstract class
// A class containing the pure virtual function 
// cannot be used to declare the objects of its own, 
// such classes are known as abstract base classes.

// The main objective of the base class is to provide the traits to the derived classes 
// and to create the base pointer used 
// for achieving the runtime polymorphism.

// If we do not override the pure virtual function in derived class, 
// then derived class also becomes abstract class. 

class A {
	int x = 5;
public:
	// pure virtual function, Vf without definition
	virtual void display() = 0;
};

// derived class
class B : public A{
	int y = 10;
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


	// A a; will give error

	// A class containing the pure virtual function 
	// cannot be used to declare the objects of its own, 
	// such classes are known as abstract base classes.

	return 0;
}