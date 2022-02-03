// 2-Std.cpp
#include<iostream>
// using namespace std;

// std -> standard, 
// namespace std is the standard namespace 
// wich is used 

// std namespace have lot of members defined inside it
// in our program, string, cout, endl are members of std namespace

namespace n1 {
	int age = 27;
	std::string name = "Abhishek";
}

namespace n2 {
	int age = 22;
	std::string name = "Anshul";
}

int main() {
	std::cout<<n1::age<<" "<<n1::name<<std::endl;
	std::cout<<n2::age<<" "<<n2::name<<std::endl;

	return 0;
}