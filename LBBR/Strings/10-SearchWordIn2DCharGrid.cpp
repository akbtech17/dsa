// 10 - SearchWordIn2DCharGrid.cpp
// https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/

#include <iostream>
#include <string>
using namespace std;

bool search2D(char* grid, int i, int j , string word, int row, int col) {
	
}

void patternSearch(char *grid, string word, int R, int C) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (search2D(grid, i, j, word, R, C)) {
				cout << "patter found at " << i << " " << j << endl;
			}
		}
	}
	return;
}

int main() {
	int R = 3, C = 13;
	char grid[R][C] = { "GEEKSFORGEEKS",
	                    "GEEKSQUIZGEEK",
	                    "IDEQAPRACTICE"
	                  };

	patternSearch((char *)grid, "GEEKS", R, C);
	cout << endl;
	patternSearch((char *)grid, "EEE", R, C);
	return 0;
}