// 7 - remove - extra - spaces.cpp and also sort words
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str, ans;
	str = "welcome    to CB    we are     learning    strings";

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
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		ans += v[i];
		if (i != v.size() - 1) {
			ans += ' ';
		}
	}
	cout << ans;
	return 0;
}