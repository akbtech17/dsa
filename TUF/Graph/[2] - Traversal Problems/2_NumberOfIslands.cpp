#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	void runBFS(int srci, int srcj, vector<vector<char>> &grid,
				vector<vector<bool>> &isvis) {
		int n = grid.size(), m = grid[0].size();
		queue<pair<int, int>> q;

		q.push({srci, srcj});
		isvis[srci][srcj] = true;

		vector<pair<int, int>> dirs = {{0, 1},	 {1, 0}, {-1, 0}, {0, -1},
									   {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

		while (!q.empty()) {
			pair<int, int> currCell = q.front();
			q.pop();

			int curri = currCell.first;
			int currj = currCell.second;

			for (pair<int, int> dir : dirs) {
				int ni = curri + dir.first;
				int nj = currj + dir.second;

				if (ni < 0 || ni >= n || nj < 0 || nj >= m)
					continue;
				else if (isvis[ni][nj] == true || grid[ni][nj] == '0')
					continue;

				isvis[ni][nj] = true;
				q.push({ni, nj});
			}
		}

		return;
	}

	int numIslands(vector<vector<char>> &grid) {
		int ans = 0;
		int n = grid.size(), m = grid[0].size();

		vector<vector<bool>> isvis(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1' && isvis[i][j] == false) {
					runBFS(i, j, grid, isvis);
					ans += 1;
				}
			}
		}

		return ans;
	}
};
