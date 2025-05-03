#include <iostream>
using namespace std;

// TC: O(N*M)
// SC: O(N*M)
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
								  int newColor) {
		vector<vector<int>> newImage(image);
		int n = image.size(), m = image[0].size();

		vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		queue<pair<int, int>> q;
		int color = image[sr][sc];

		if (color == newColor) return image;

		q.push({sr, sc});
		newImage[sr][sc] = newColor;

		while (!q.empty()) {
			pair<int, int> currPixel = q.front();
			q.pop();

			int cr = currPixel.first, cc = currPixel.second;

			for (pair<int, int> dir : dirs) {
				int nr = cr + dir.first;
				int nc = cc + dir.second;

				if (nr < 0 || nr >= n || nc < 0 || nc >= m)
					continue;
				else if (newImage[nr][nc] != color)
					continue;

				newImage[nr][nc] = newColor;
				q.push({nr, nc});
			}
		}

		return newImage;
	}
};
