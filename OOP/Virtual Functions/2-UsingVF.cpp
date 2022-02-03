// 2-UsingVF.cpp

#include<bits/stdc++.h>
using namespace std;

// base class
class A {
	int x = 5;
public:
	// virtual function
	virtual void display() {
		cout<<"In class A : "<<x;
	}
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

	return 0;
}