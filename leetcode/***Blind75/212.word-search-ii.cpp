#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Board{
private:
    vector<vector<char>> board;
    int m, n;
    int charLen;
    int dict[26] = {0};
    int dirc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool backtrack(string& word, int row, int col, int i){
        if (i == word.length()) return true;
        if (row < 0 || col < 0 || row >= m || col >= n || word[i] != board[row][col]) return false;
        char old = board[row][col];
        board[row][col] = '#';
        bool res = false;
        for (const auto& d : dirc){
            res = backtrack(word, row+d[0], col+d[1], i+1);
            if (res) {
                board[row][col] = old;
                return true;
            }
        }
        board[row][col] = old;
        return false;
    }
    bool lengthCheck(string& word){
        return word.length() <= charLen;
    }
    bool dictCheck(string& word){
        int cnt[26] = {0};
        for (char c : word){
            cnt[c-'a']++;
            if (cnt[c-'a'] > dict[c-'a']) return false;
        }
        return true;
    }
    bool prefixAdjust(string& word){
        char first = word[0], last = word[word.length()-1];
        int left = word.find_first_not_of(first);
        int right = word.length()-word.find_last_not_of(last);
        if (left > right) {
            reverse(word.begin(), word.end());
            return true;
        }
        return false;
    }
    bool search(string& word){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (backtrack(word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    
public:    
    Board(vector<vector<char>>& board){
        this->board = board;
        m = board.size();
        n = board[0].size();
        charLen = m * n;
        for (const auto& row : board)
            for (const auto& c : row)
                dict[c-'a']++;
    }
    vector<string> findWords(vector<string>& words){
        vector<string> res;
        for (string word : words){
            if (!lengthCheck(word) || !dictCheck(word)) continue;
            bool rev = prefixAdjust(word);
            if (search(word)){
                if (rev) reverse(word.begin(), word.end());
                res.push_back(word);
            }
        }
        return res;
    }

    
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Board b(board);
        return b.findWords(words);
    }
};
// @lc code=end

