// 6 - PrintAllPossibleSentences.cpp
// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/

#include <iostream>
using namespace std;
#define R 3
#define C 3

void printAllSentences(string arr[][C], int i = 0, string sentence = "") {
	if (i == R) {
		//print sentence
		cout << sentence << endl;
		return;
	}
	for (int j = 0; arr[i][j].size() > 0 and j < C; j++) {
		string curr_word = arr[i][j];
		//include it in sentence
		printAllSentences(arr, i + 1, sentence + curr_word + " ");
	}
	return;
}

int main() {
	string arr[R][C]  = {{"you", "we"},
		{"have", "are"},
		{"sleep", "eat", "drink"}
	};

	printAllSentences(arr);

	return 0;
}