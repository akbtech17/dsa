// 1.cpp



// steps to follow - 

// 1-Need of OO
// 2-Gloabal Overloading
// 3-Member Function Operator Overloading
// 4-In some cases we need to define fns for other operators,
//   to make out base OO run error-free
// 5-Sometimes it demadns to make arg list and function const 


#include<bits/stdc++.h>
using namespace std;

// OPerator Functions - 
// functions of operators are defined, like + means addition

// but if we have user-defined datatype,
// car1+car2, now how will this operator will behave

// in this case we can create our own function for + operator
// which will be invoked depending upon condition


struct YoutubeChannel {
	string name;
	int subscribersCount;

	//constructor
	YoutubeChannel(string n, int cnt) {
		// cout<<"constructor invoked!!!\n";
		name = n;
		subscribersCount = cnt;
	}

	// to resolve error for  == comaprison of -= operator, remove method
	// we have to make function and arggs as const, 
	// so that function cannot change anything, only compare,
	// otherwise it will give an error
	bool operator==(const YoutubeChannel& yt) const{
		return this->name == yt.name;
	}
};

// operator keyword + (operator symbol)
// as insertion operator works with two operands,
// we have to pass two operands by reference (always)
// COUT is of type ostream&
// yt1 is of type YoutubeChannel 

// we use refernce pass - to avoid copying cost line vectors, strings
// we pass by value for only parameters which are cheap to copy
// like, numbers

// global operator function
// void operator<<(ostream& COUT, YoutubeChannel& ytChannel) {
ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel) {
	COUT<<"Name of the channel : "<<ytChannel.name<<endl;
	COUT<<"Number of subs : "<<ytChannel.subscribersCount<<endl;
	return COUT;
}

struct MyCollection {
	list<YoutubeChannel> myChannels;

	//operator overloading function as member function of the struct
	// no need to pass the struct type as arg
	// only one arg is passed because
	// this is implicity binded to every member function call by compiler

	void operator+=(YoutubeChannel& channel) {
		this->myChannels.push_back(channel);
	}

	void operator-=(YoutubeChannel& yt) {
		this->myChannels.remove(yt);
	}
};

ostream& operator<<(ostream& COUT, MyCollection& collec) {
		for(auto el : collec.myChannels) {
			COUT<<el;
		}
		return COUT;
	}

int main() {
	YoutubeChannel yt1 = YoutubeChannel("akb.tech",17);
	YoutubeChannel yt2 = YoutubeChannel("ab94111",11);


	// cout<<5; - it will print 5 simply
	// cout<<yt1; - it will give an error
	// no matching operands(cout and yt1) for insertion operator(<<)

	// now we have to overload insertion operator
	// cout<<yt1;

	// now to do nesting operation, we need to chance the
	// return type of opertor function, to ostream&
	// and we have to return COUT object
	// cout<<yt1<<yt2;

	// operator<<(cout,yt2); - we can call operator function, as normal funciton also


	MyCollection myCollection;
	myCollection += yt1;
	myCollection += yt2;

	cout<<myCollection;


	// try overloading for -= to remove channels
	myCollection -= yt2;
	cout<<myCollection;

	return 0;
}