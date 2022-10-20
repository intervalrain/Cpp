#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int theLongestLength(vector<vector<int>>& grid){
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid.size(); j++){
                res = max(res, dfs(grid, i, j, dp));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        if (dp[row][col] != -1) return dp[row][col];
        int curr = grid[row][col];
        int res = 1;
        for (int i = 0; i < grid.size(); i++){
            if (curr < grid[i][col]){
                res = max(res, 1 + dfs(grid, i, col, dp));
            }
        }
        for (int j = 0; j < grid[0].size(); j++){
            if (curr < grid[row][j]){
                res = max(res, 1 + dfs(grid, row, j, dp));
            }
        }
        dp[row][col] = res;
        return res;
    }
    vector<int> theLongestPath(vector<vector<int>>& grid){
        vector<int> res;
        vector<int> path;
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                dfs(grid, i, j, dp, res, path);
            }
        }
        return res;
    }
    vector<int> dfs(vector<vector<int>>& grid, int row, int col, vector<vector<vector<int>>>& dp, vector<int>& res, vector<int>& path){
        if (dp[row][col].size() > 0){
            vector<int> vec = dp[row][col];
            if (path.size() + vec.size() > res.size()){
                for (const int& x : vec){
                    path.push_back(x);
                }
                res = path;
                int sz = vec.size();
                while (sz--) path.pop_back();
            }
            return dp[row][col];
        }
        int curr = grid[row][col];
        path.push_back(curr);
        vector<int> longestPath;
        if (path.size() > res.size()){
            res = path;
        }
        for (int i = 0; i < grid.size(); i++){
            if (curr < grid[i][col]){
                vector<int> next = dfs(grid, i, col, dp, res, path);
                if (next.size() > longestPath.size()) longestPath = next;
            }
        }
        for (int j = 0; j < grid[0].size(); j++){
            if (curr < grid[row][j]){
                vector<int> next = dfs(grid, row, j, dp, res, path);
                if (next.size() > longestPath.size()) longestPath = next;
            }
        }
        path.pop_back();
        dp[row][col] = longestPath;
        return longestPath;
    }
};


int main(){
    vector<vector<int>> grid = {{ 1, 3, 2, 4},
                                { 6, 7, 8, 5},
                                {11,12, 9,10},
                                {14,13,15,16}};

    Solution* sol = new Solution();

    cout << sol->theLongestLength(grid) << endl;
    vector<int> res = sol->theLongestPath(grid);
    for_each(res.begin(), res.end(), [](int x){cout << x << " ";});

    return 0;
}
