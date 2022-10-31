/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;   // {row, col, path length, k}
        q.push({0,0,0,k});
        while (!q.empty()) {
            auto info = q.front();
            q.pop();

            int row = info[0], col = info[1], len = info[2], bomb = info[3];

            // out of bound
            if (row < 0 || col < 0 || row >= m || col >= n) continue;

            // destination
            if (row == m-1 && col == n-1) return len;

            // meet obstatcle
            if (grid[row][col] == 1) {
                if (bomb > 0)
                    bomb--;
                else
                    continue;
            }

            if (visited[row][col] != -1 && visited[row][col] >= bomb)
                continue;
            visited[row][col] = bomb;

            q.push({row+1,col,len+1,bomb});
            q.push({row,col+1,len+1,bomb});
            q.push({row-1,col,len+1,bomb});
            q.push({row,col-1,len+1,bomb});
        }
        return -1;
    }
};
// @lc code=end

