#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	void runBFS(int i, int j, vector<vector<bool>> &isvis,
				vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		queue<pair<int, int>> q;

		q.push({i, j});
		isvis[i][j] = true;

		while (!q.empty()) {
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

		return;
	}

	int numberOfEnclaves(vector<vector<int>> &grid) {
		int ans = 0;

		int n = grid.size(), m = grid[0].size();
		vector<vector<bool>> isvis(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
					grid[i][j] == 1 && isvis[i][j] == false) {
					runBFS(i, j, isvis, grid);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1 && isvis[i][j] == false) {
					ans++;
				}
			}
		}

		return ans;
	}
};
