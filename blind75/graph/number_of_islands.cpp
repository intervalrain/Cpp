#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        grid[i][j] = '0';
        for (const auto& d : dir){
            dfs(grid, visited, i+d[0], j+d[1]);
        }
    }
};
