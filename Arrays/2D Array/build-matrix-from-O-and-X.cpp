#include <iostream>
#define MX 100
using namespace std;

void printMat(char arr[][MX], int row, int col) {
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

//tc - n square
//sc - 1
void spiralClockwise(char arr[][MX], int row, int col) {
	int sr, sc, er, ec;
	sr = sc = 0; 	
	er = row - 1;
	ec = col - 1;
	char ch = 'O';
	while (sr <= er and sc <= ec) {
		if (ch == 'X') ch = 'O';
		else ch = 'X';
		//print top row
		for (int j = sc; j <= ec; ++j) arr[sr][j] = ch;
		sr++;
		//print right col
		for (int i = sr; i <= er; ++i) arr[i][ec] = ch;
		ec--;
		//print bottom row
		if (sr <= er) {
			for (int j = ec; j >= sc; --j) arr[er][j] = ch;
			er--;
		}
		//print left col
		if (sc <= ec) {
			for (int i = er; i >= sr; --i) arr[i][sc] = ch;
			sc++;
		}
	}
	return;
}

int main() {
	int row, col;
	cin >> row >> col;
	char arr[MX][MX];
	spiralClockwise(arr, row, col);
	printMat(arr, row, col);
	return 0;
}