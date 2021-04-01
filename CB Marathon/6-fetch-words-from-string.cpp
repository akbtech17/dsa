// 6 - fetch - words - from - string.cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	string s;
	s = "welcome    to CB, we are learning strings.";

	char arr[100005];
	strcpy(arr, s.c_str()); // copy string to char array

	//(starting address of char array(static variable), string of delim)
	//return pointer to first word
	char* word = strtok(arr, " ");
	cout << word << endl;
	while (word != NULL) {
		word = strtok(NULL, " ,.");
		cout << word << endl;
	}

	return 0;
}