// OddEvenAlternatePosition.cpp
#include<iostream> 
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

int main() {
	int arr[1000] = {1,3,5,2,4,6};
	int n = 6;
	sort(arr,arr+n);
	vector<int> odd,even;
	bool evenFirst = true;

	if(arr[0] %2!= 0) evenFirst = false;
	for(int i=0;i<n;i++) {
		if(arr[i]%2 == 0) even.pb(arr[i]);
		else odd.pb(arr[i]);
	}

	int i = 0; //to iterate even  
	int j = 0;	//to iterate odd

	for(int k=0;k<n;k++) {
		if(evenFirst) {
			arr[k] = even[i++];
			evenFirst = false;
		}
		else {
			arr[k] = odd[j++];
			evenFirst = true;
		}
		cout<<arr[k]<<" ";
	}

	return 0;
}