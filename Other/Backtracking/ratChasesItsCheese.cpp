// ratChasesItsCheese.cpp
#include <iostream>
#define MX 11
using namespace std;

int cnt = 0;
int sol[MX][MX] ;

bool findCheese(char mat[][MX], int row, int col, int i = 0, int j = 0) {
	//base case
	//keep 'X' case above so that if there's X at last cell, the answer is no path found
	if (mat[i][j] == 'X') return false;
	if (i == row - 1 and j == col - 1) {
		sol[i][j] = 1;
		if (cnt == 0) {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cout << sol[i][j] << " ";
				}
				cout << endl;
			}
			cnt++;
		}
		return true;
	}
	if (cnt == 1) return true;
	if (i >= row or j >= col or i < 0 or j < 0) return false;

	sol[i][j] = 1;
	//edit- first call i+1,j then i,j+1
	//initially all variables are false
	bool leftAnsHai = false, neecheAnsHai = false, rightAnsHai = false, uparAnsHai = false;
	//check if next cell has 0 in sol matrix
	if (sol[i + 1][j] == 0)
		leftAnsHai = findCheese(mat, row, col, i + 1, j );
	if (sol[i][j + 1] == 0 && !leftAnsHai)
		neecheAnsHai = findCheese(mat, row, col, i, j + 1);
	if (sol[i - 1][j] == 0 && !leftAnsHai && !neecheAnsHai)
		uparAnsHai = findCheese(mat, row, col, i - 1 , j);
	if (sol[i][j - 1] == 0 && !leftAnsHai && !neecheAnsHai && !uparAnsHai)
		rightAnsHai = findCheese(mat, row, col, i , j - 1);

	if (neecheAnsHai or leftAnsHai or uparAnsHai or rightAnsHai) return true;
	//backtrack
	sol[i][j] = 0;
	return false;
}


int main() {
	char mat[MX][MX];
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> mat[i][j];
			sol[i][j] = 0;
		}
	}

	if (!findCheese(mat, row, col)) cout << "NO PATH FOUND";

	return 0;
}
