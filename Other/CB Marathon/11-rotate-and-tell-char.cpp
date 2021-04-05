// 11 - rotate - and - tell - char.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "ababab";
	string str_org(str);

	//append the same string at the end
	str += str;

	//heck for every i=1 pos if we have org string found!
	for (int i = 1; i < str_org.length(); ++i) {
		string temp = str.substr(i, str_org.length());
		if (temp == str_org) {
			cout << "roatate it " << i << " times";
			break;
		}
	}

	return 0;
}