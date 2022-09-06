#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int len = word.length();
        // prune #1
        if (len > m*n) return false;

        // prune #2
        int cnt[128] = {};
        for (const auto& v : board){
            for (const auto& c : v) cnt[c]++;
        }
        for (const auto& c : word)
            if (--cnt[c] < 0) return false;

        // prune #3
        int left = word.find_first_not_of(word[0]);
        int right = len - word.find_last_not_of(word[len-1]);
        if (left > right) reverse(word.begin(), word.end());

        // dfs
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (backtrack(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool backtrack(vector<vector<char>>& board, int row, int col, string word, int i){
        if (i == word.length()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[i]) return false;
        char tmp = board[row][col];
        board[row][col] = '#';
        for (auto d : dirc){
            bool res = backtrack(board, row+d[0], col+d[1], word, i+1);
            if (res) return true;
        }
        board[row][col] = tmp;
        return false;
    }
};
// @lc code=end

