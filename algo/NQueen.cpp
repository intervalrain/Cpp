#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, res);
        return res;
    }
    int solveNQueensNums(int n){
        vector<string> board(n, string(n, '.'));
        int cnt = 0;
        backtrackhalf(board, 0, cnt);
        return cnt;
    }

    void backtrackhalf(vector<string>& board, int row, int& cnt){
        int n = board.size();
        if (row == n){
            cnt++;
            return;
        }
        for (int col = 0; col < n; col++){
            if (!isValid(board, row, col)) continue;
            board[row][col] = 'Q';
            backtrackhalf(board, row+1, cnt);
            board[row][col] = '.';
        }
    }
    
    void backtrack(vector<string>& board, int row, vector<vector<string>>& res){
        if (row == board.size()){
            vector<string> vec;
            for (int i = 0; i < board.size(); i++){
                vec.push_back(board[i]);   
            }
            res.push_back(vec);
            return;
        }
        int n = board.size();
        for (int col = 0; col < n; col++){
            if (!isValid(board, row, col)) continue;
            board[row][col] = 'Q';
            backtrack(board, row+1, res);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int& row, int& col){
        int n = board.size();
        if (row == n) return true;
        for (int i = row - 1; i >= 0; i--)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    
};

int main(){
    Solution* sol = new Solution;
    vector<vector<string>> res = sol->solveNQueens(4);
    for (vector<string> row : res){
        for (string s : row){
            cout << s << endl;
        }
        cout << endl;
    }
    cout << "The numbers of the probable solution: " << sol->solveNQueensNums(4);
    delete sol;
    return 0;
}