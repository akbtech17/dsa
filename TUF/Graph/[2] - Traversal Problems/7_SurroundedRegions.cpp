#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	vector<vector<char>> fill(vector<vector<char>> mat) {
		int n = mat.size(), m = mat[0].size();
		queue<pair<int, int>> q;
		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

		for (int i = 0; i < n; i++) {
			if (mat[i][0] == 'O') {
				q.push({i, 0});
				mat[i][0] = 'T';
			}
			if (mat[i][m - 1] == 'O') {
				q.push({i, m - 1});
				mat[i][m - 1] = 'T';
			}
		}

		for (int j = 0; j < m; j++) {
			if (mat[0][j] == 'O') {
				q.push({0, j});
				mat[0][j] = 'T';
			}
			if (mat[n - 1][j] == 'O') {
				q.push({n - 1, j});
				mat[n - 1][j] = 'T';
			}
		}

		while (!q.empty()) {
			pair<int, int> curCell = q.front();
			q.pop();

			for (pair<int, int> dir : dirs) {
				int ni = curCell.first + dir.first;
				int nj = curCell.second + dir.second;

				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				if (mat[ni][nj] == 'O') {
					q.push({ni, nj});
					mat[ni][nj] = 'T';
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'O')
					mat[i][j] = 'X';
				else if (mat[i][j] == 'T')
					mat[i][j] = 'O';
			}
		}

		return mat;
	}
};