#include <iostream>
#include <vector>

using namespace std;

class Ball{
public:
    int pos;
    bool arrive;
    Ball(int index){
        pos = index;
        arrive = true;
    }
    void update(vector<int>& row, vector<bool>& die){
        this->pos += row[this->pos];
        if (die[this->pos]) this->arrive = false;
    }
    int output(){
        return arrive ? pos : -1;
    }
};

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<Ball*> balls(n);
        for (int i = 0; i < n; i++){
            balls[i] = new Ball(i);
        }
        
        for (int i = 0; i < m; i++){
            vector<bool> die(n, false);
            vector<int> row = grid[i];
            for (int j = 1; j < n; j++){
                if (row[j-1] == 1 && row[j] == -1){
                    die[j-1] = true;
                    die[j] = true;
                }
            }
            for (int j = 0; j < n; j++){
                balls[j]->update(row, die);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++){
            res.push_back(balls[i]->output());
        }
        return res;   
    }
};

int main(){
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    Solution* sol = new Solution();
    vector<int> res = sol->findBall(grid);

    return 0;
}