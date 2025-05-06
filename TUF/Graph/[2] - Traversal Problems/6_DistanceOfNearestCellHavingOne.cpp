#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	vector<vector<int>> nearest(vector<vector<int>> grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> ansGrid(n, vector<int>(m, -1));
		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		queue<pair<int, int>> q;
		int currDist = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					q.push({i, j});
					ansGrid[i][j] = currDist;
				}
			}
		}
		currDist += 1;

		while (!q.empty()) {
			int qs = q.size();

			for (int i = 0; i < qs; i++) {
				pair<int, int> currCell = q.front();
				q.pop();

				for (pair<int, int> dir : dirs) {
					int ni = currCell.first + dir.first;
					int nj = currCell.second + dir.second;

					if (ni < 0 || ni >= n || nj < 0 || nj >= m)
						continue;
					else if (grid[ni][nj] == 1 || ansGrid[ni][nj] != -1)
						continue;

					ansGrid[ni][nj] = currDist;
					q.push({ni, nj});
				}
			}

			currDist++;
		}

		return ansGrid;
	}
};