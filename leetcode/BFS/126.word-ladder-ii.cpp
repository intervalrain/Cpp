#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start

class Solution {
public:
    unordered_map<string, int> map; 
    vector<vector<string>> res; 
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList){
        
        unordered_set<string> dict(wordList.begin(), wordList.end()); 
        vector<string> path = {endWord};
        bfs(beginWord, endWord, dict);
        if (!map.count(endWord)) return res;
        dfs(endWord, beginWord, path); 
        
        return res; 
    }
    void bfs(string& beginWord, string& endWord, unordered_set<string>& dict){
        queue<string> q;
        q.push(beginWord);
        map[beginWord] = 1;
        dict.erase(beginWord);
        while(!q.empty()) {
            string word = q.front(); 
            int steps = map[word]; 
            q.pop(); 
            if (word == endWord) break; 
            for (int i = 0; i < word.length(); i++) {
                string old = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (dict.count(word)) {
                        q.push(word); 
                        dict.erase(word); 
                        map[word] = steps + 1;
                    }
                }
                word = old;
            }
        }
    }
    void dfs(string& word, string& target, vector<string> &path) {
        if (word == target) {
            reverse(path.begin(), path.end()); 
            res.push_back(path); 
            reverse(path.begin(), path.end()); 
            return; 
        }
         int steps = map[word]; 
         int sz = word.size(); 
         for (int i = 0; i < sz; i++) {
            char original = word[i]; 
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch; 
                if (map.count(word) && map[word] == steps-1) {
                    path.push_back(word); 
                    dfs(word, target, path); 
                    path.pop_back(); 
                }
            }
             word[i] = original; 
         }
    }

    
};

// @lc code=end

