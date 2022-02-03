// temp.cpp
#include <iostream>
using std::cout;

class Temp {
public:
	Temp() {
		cout<<"cont";
	}
	~Temp() {
		cout<<"memory freed!";
	}
};

Temp globalObj;

int main () {
	{Temp scopedObj;}
	cout<<"1";
	return 0;
}