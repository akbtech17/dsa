// 3-RefinedCode.cpp
#include<iostream>
using std::cout;
using std::string;
using std::endl;

// Why using namespace is BAD?
// we have lot of members in std, so using namespace std
// imports all the members in our Program

// while importing only required members is recommended...

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