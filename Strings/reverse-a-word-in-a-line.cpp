// reverse - a - word - in - a - line.cpp
#include <iostream>
#define MX 10000
using namespace std;


void reverseWord(char *line, int s, int e) {

	while (s < e) {
		swap(line[s], line[e]);
		s++;
		e--;
	}
	return;
}

void reverseWordInLine(char *line, int len) {

	int s = -1;
	int e;

	for (int i = 0; i < len; ++i)
	{
		if (s == -1) {
			while (s == -1 and line[i] == ' ') {
				i++;
			}
			s = i;
			continue;
		}
		if (line[i] == ' ') {
			int e = i - 1;
			reverseWord(line, s, e);
			s = -1;
		}
	}
	return;
}


int main() {
	char line[MX];
	cin.getline(line, MX);
	int len = 0;
	while (line[len] != '\0') len++;
	reverseWordInLine(line, len);
	cout << line;
	return 0;
}