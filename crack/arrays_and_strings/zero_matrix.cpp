#include <iostream>
#include <vector>

/**
 * Write an algorithm such that if an element in an MxN matrix is 0,
 * its entire row and column are set to 0.
 */

using namespace std;

class Solution{
  public:
    void setZeros(vector<vector<int>>& matrix){
        vector<vector<bool>> dp(matrix.size(), vector<bool>(matrix[0].size(), false));

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0) setBool(dp, i, j);
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (dp[i][j]) matrix[i][j] = 0;
            }
        }
    }
    void setBool(vector<vector<bool>>& dp, int row, int col){
        for (int i = 0; i < dp.size(); i++){
            dp[i][col] = true;
        }
        for (int j = 0; j < dp[0].size(); j++){
            dp[row][j] = true;
        }
    }
};

void print(vector<vector<int>>& matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    vector<vector<int>> matrix = {{0,1,2,3},
                                  {1,3,2,1},
                                  {3,1,2,3},
                                  {0,3,2,1}};
    Solution* sol = new Solution();
    print(matrix);
    sol->setZeros(matrix);
    cout << "-----------" << endl;
    print(matrix);

    return 0;
}
