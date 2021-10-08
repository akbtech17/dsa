// 1-Introduction.cpp
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::list;

// OOP allows us to deal with real world entities 
// in our program using classes and objects, and OOPs features.

// class is blueprint of real world objects
// class is user defined datatype
class YoutubeChannel {
	// data members - by default private
public:    // access modifiers
	string Name;
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideosTitles;
};

int main() {
	YoutubeChannel ytChannel;
	
	// initializing the data members of our object
	ytChannel.Name = "Akb.tech17";
	ytChannel.OwnerName = "Anshul Bansal";
	ytChannel.SubscribersCount = 512;
	ytChannel.PublishedVideosTitles = {"Video1", "Video2", "Video3"};

	// printing the data of our object
	cout<<"Name of the Channel : "<<ytChannel.Name<<endl;
	cout<<"Name of the Owner : "<<ytChannel.OwnerName<<endl;
	cout<<"No of Subscribers : "<<ytChannel.SubscribersCount<<endl;
	cout<<"List of Videos : "<<endl;

	int i = 1;
	for(string videoTitle : ytChannel.PublishedVideosTitles) {
		cout<<i<<" -> "<<videoTitle<<endl;
		i++;
	}

	return 0;
}