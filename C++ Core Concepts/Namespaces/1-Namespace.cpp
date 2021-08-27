// 1-Namespace.cpp
#include<iostream>
using namespace std;

// Namespace 
// it helps us resolving conflicts, 
// when user wants to define and use two things with a same name


// namespace is a keyword here...
namespace n1 {
	int age = 27;
	string name = "Abhishek";
}

namespace n2 {
	int age = 22;
	string name = "Anshul";
}

int main() {
	cout<<n1::age<<" "<<n1::name<<endl;
	cout<<n2::age<<" "<<n2::name<<endl;

	return 0;
}