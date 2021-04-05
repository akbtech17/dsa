// 8 - reverse - word - in - string.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str = "my name is anshul";
	char arr[100005];
	strcpy(arr, str.c_str());

	char* word = strtok(arr, " ");
	vector<string> v;
	while (word != NULL) {
		string w(word);
		v.push_back(w);
		// ans += ' ';
		word = strtok(NULL, " ,.");
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		cout <<
	}
	return 0;
}