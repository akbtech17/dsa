// 3 - CountWordInString.cpp
#include <iostream>
#include <cstring>
using namespace std;

int findCountOfOccurences(string str, string word) {
	int cnt = 0;

	//extracting word using strtok
	//converted tring into char array using c_str()
	//typecasted into char*
	char* p = strtok((char*)str.c_str(), " ");
	while (p != nullptr) {
		//check here
		string w(p); // converting char array into string
		if (w == word) cnt++; //if word found, cnt++
		p = strtok(nullptr, " "); //move to the next char
	}
	return cnt;
}

void tellCount(string str, string word) {
	cout << "count is : ";
	cout << findCountOfOccurences(str, word) << endl;
	return;
}

int main() {
	// string str,word;
	// getline(cin,str);
	// cin>>word;
	tellCount("anshul is anshul", "anshul");
	return 0;
}