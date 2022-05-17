#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool isValid(vector<vector<int>>& grid){
        int n = grid.size();
        int xs, ys, xe, ye;
        vector<vector<bool>> used (n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    used[i][j] = true;
                } else if (grid[i][j] == 1){
                    xs = i;
                    ys = j;
                } else if (grid[i][j] == 2){
                    xe = i;
                    ye = j;
                }
            }
        }
        return traverse(grid, xs, ys, xe, ye, used);
    }

    bool traverse(vector<vector<int>> grid, int xs, int ys, int xe, int ye, vector<vector<bool>>& used){
        int n = grid.size();
        if (xs < 0 || ys < 0 || xs >= n || ys >= n) return false;
        if (xs == xe && ys == ye) return true;
        if (used[xs][ys]) return false;

        used[xs][ys] = true;

        return traverse(grid, xs+1, ys, xe, ye, used) ||
               traverse(grid, xs-1, ys, xe, ye, used) ||
               traverse(grid, xs, ys+1, xe, ye, used) ||
               traverse(grid, xs, ys-1, xe, ye, used);
    }
};

int main(){

    vector<vector<int>> grid1 = {{3,0,3,0,0},
                                 {3,0,0,0,3},
                                 {3,3,3,3,3},
                                 {0,2,3,0,0},
                                 {3,0,0,1,3}};
    vector<vector<int>> grid2 = {{1,3},
                                 {3,2}};
    Solution* sol = new Solution;
    cout << sol->isValid(grid1) << endl;
    cout << sol->isValid(grid2) << endl;

    return 0;
}
