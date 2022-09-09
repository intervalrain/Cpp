#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Board {
private:
    int m, n;
    int total;
    int cnt[128] = {};
    int dirc[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<char>> board;
    bool backtrack(int row, int col, string word, int i){
        if (i == word.length()) return true;
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[i]) return false;
        char tmp = board[row][col];
        board[row][col] = '#';
        for (auto d : dirc){
            bool res = backtrack(row+d[0], col+d[1], word, i+1);
            if (res) {
                board[row][col] = tmp;
                return true;
            }
        }
        board[row][col] = tmp;
        return false;        
    }
public:
    Board(vector<vector<char>>& board){
        this->board = board;
        m = board.size(), n = board[0].size();
        total = m * n;
        for (const auto& v:board)
            for (const auto& c:v)
                cnt[c]++;
    }
    bool check(string& word){
        // # prune 1
        if (word.length() > total) return false;
        // # prune 2
        unordered_map<char, int> map;
        for (const char& c : word) map[c]++;
        for (auto m : map){
            if (cnt[m.first] < m.second) return false;
        }
        return true;
    }
    bool longerPrefix(string& word){
        // # prune 3
        int left = word.find_first_not_of(word[0]);
        int right = word.length() - word.find_last_not_of(word[word.length()-1]);
        if (left > right) {
            reverse(word.begin(), word.end());
            return true;
        }
        return false;
    }
    bool search(string& word){
        if (!check(word)) return false;
        bool rev = longerPrefix(word);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (backtrack(i, j, word, 0)) {
                    if (rev) reverse(word.begin(), word.end());
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Board b(board);
        vector<string> res;
        for (string s : words)
            if (b.search(s)) res.push_back(s);
        return res;
    }
};
// @lc code=end

