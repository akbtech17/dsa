// 2-ConstructorsAndMethods.cpp
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::list;

class YoutubeChannel {
public:   
	string Name;
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideosTitles;

	// constructor
	// does not have a return type,
	// have the same name as classddddddd
	YoutubeChannel(string Name, string OwnerName, int SubscribersCount, list<string> PublishedVideosTitles) {
		this.Name = Name;
	}

	// member funcitons, or class methods
	void display() {
		cout<<"Name of the Channel : "<<Name<<endl;
		cout<<"Name of the Owner : "<<OwnerName<<endl;
		cout<<"No of Subscribers : "<<SubscribersCount<<endl;
		cout<<"List of Videos : "<<endl;

		int i = 1;
		for(string videoTitle : PublishedVideosTitles) {
			cout<<i<<" -> "<<videoTitle<<endl;
			i++;
		}
		return;
	}
};

int main() {
	string Name = "Akb.tech17";
	string OwnerName = "Anshul Bansal";
	int SubscribersCount = 512;
	list<string> PublishedVideosTitles = {"Video1", "Video2", "Video3"};

	YoutubeChannel ytChannel(Name,OwnerName,SubscribersCount,PublishedVideosTitles);
	
	// printing the data of our object
	ytChannel.display();

	return 0;
}