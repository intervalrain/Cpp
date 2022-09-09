#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
    vector<Trie*> node;
    bool tail;
    char ch;
    Trie() {
        node = vector<Trie*>(26);
        tail = false;
        ch = '*';
    }
    Trie(char c) {
        node = vector<Trie*>(26);
        tail = false;
        ch = c;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for (char c : word){
            if (!curr->node[c-'a'])
                curr->node[c-'a'] = new Trie(c);
            curr = curr->node[c-'a'];
        }
        curr->tail = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (char c : word){
            if (!curr->node[c-'a']) return false;
            curr = curr->node[c-'a'];
        }
        return curr->tail;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (char c : prefix){
            if (!curr->node[c-'a']) return false;
            curr = curr->node[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

