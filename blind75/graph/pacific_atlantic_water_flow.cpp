#include <iostream>

/**
 * -Pacific Ocean--
 * |  1 2 2 3 5   |
 * |  3 2 3 4 4   |
 * P  2 4 5 3 1   A
 * |  6 7 1 4 5   |
 * |  5 1 1 2 4   |
 * -Atlantic Ocean-
 */

using namespace std;

class Solution{

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    // dfs
    vector<vector<int>> pacificAtlantic1(vector<vector<int>> heights) {
        int m = height.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> res;

        for (int i = 0; i < m; i++){
            dfs(heights, pacific, i, 0, -1);
            dfs(heights, atlantic, i, n-1, -1);
        }
        for (int i = 0; i < n; i++){
            dfs(heights, pacific, 0, i, -1);
            dfs(heights, atlantic, m-1, i, -1);
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, int height){
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> res;

        for (int i = 0; i < m; i++){
            q_pacific.push(make_pair(i, 0));
            q_atlantic.push(make_pair(i, n-1));
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for (int i = 0; i < n; i++){
            q_pacific.push(make_pair(0, i));
            q_atlantic.push(make_pair(m-1, i));
            pacific[0][i] = true;
            atlantic[m-1][i] = true;
        }
        bfs(heights, q_pacific, pacific);
        bfs(heights, q_atlantic, atlantic);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    // bfs
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> res;

        queue<pair<int,int>> q_pacific;
        queue<pair<int,int>> q_atlantic;

        for (int i = 0; i < m; i++){
            q_pacific.push(make_pair(i, 0));
            q_atlantic.push(make_pair(i, n-1));
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
        }
        for (int i = 0; i < n; i++){
            q_pacific.push(make_pair(0, i));
            q_atlantic.push(make_pair(m-1, i));
            pacific[0][i] = true;
            atlantic[m-1][i] = true;
        }
        bfs(heights, q_pacific, pacific);
        bfs(heights, q_atlantic, atlantic);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& visited){
        int m = heights.size(), n = heights[0].size();
        while (!q.empty){
            pair p = q.front();
            q.pop();
            for (auto d : dir){
                int row = p.first + d[0];
                int col = p.second + d[1];
                if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || heights[row][col] < heights[p.first][p.second]){
                    continue;
                }
                visited[row][col] = true;
                q.push(make_pair(row, col));
            }
        }
    }
};
