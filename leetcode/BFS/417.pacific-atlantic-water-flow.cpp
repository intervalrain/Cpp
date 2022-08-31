/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int,int>> pacific, atlantic;
        vector<vector<bool>> visited_p(m, vector<bool>(n, false));
        vector<vector<bool>> visited_a(m, vector<bool>(n, false));
        vector<vector<int>> res;

        for (int i = 0; i < m; i++){
            pacific.push({i, 0});
            atlantic.push({i, n-1});
            visited_p[i][0] = true;
            visited_a[i][n-1] = true;
        }
        for (int j = 0; j < n; j++){
            pacific.push({0, j});
            atlantic.push({m-1, j});
            visited_p[0][j] = true;
            visited_a[m-1][j] = true;
        }

        bfs(heights, pacific, visited_p);
        bfs(heights, atlantic, visited_a);


        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (visited_p[i][j] && visited_a[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited){
        int m = heights.size(), n = heights[0].size();
        while (!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for (auto d : dirc){
                int row = p.first + d[0];
                int col = p.second + d[1];
            if (row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || heights[row][col] < heights[p.first][p.second]) continue;
                visited[row][col] = true;
                q.push({row, col});
            }
        }
    }
};
// @lc code=end

