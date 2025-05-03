#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	int orangesRotting(vector<vector<int>> &grid) {
		int mins = 0;

		int n = grid.size(), m = grid[0].size();
		vector<vector<bool>> isvis(n, vector<bool>(m, false));
		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		queue<pair<int, int>> q;

		int totalOranges = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] != 0) totalOranges++;
				if (grid[i][j] == 2) {
					q.push({i, j});
					isvis[i][j] = true;
				}
			}
		}

		int countRotten = 0;

		while (!q.empty()) {
			int qs = q.size();
			countRotten += qs;

			for (int i = 0; i < qs; i++) {
				pair<int, int> currCell = q.front();
				q.pop();

				for (pair<int, int> dir : dirs) {
					int ni = currCell.first + dir.first;
					int nj = currCell.second + dir.second;

					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (grid[ni][nj] == 1 && !isvis[ni][nj]) {
						q.push({ni, nj});
						isvis[ni][nj] = true;
					}
				}
			}
			mins += q.empty() ? 0 : 1;
		}

		return totalOranges == countRotten ? mins : -1;
	}
};