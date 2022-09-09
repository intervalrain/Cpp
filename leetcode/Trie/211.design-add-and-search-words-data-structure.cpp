#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class TrieNode {
public:
    TrieNode* children[26];
    bool tail;
    TrieNode() {
        this->tail = false;
        memset(children, NULL, sizeof(children));
    }
};
class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    bool len[26];
    bool search(const char* word, TrieNode* curr){
        for (int i = 0; word[i]; i++){
            if (word[i] != '.'){
                if (curr->children[word[i]-'a'] == NULL) return false;
                curr = curr->children[word[i]-'a'];
            } else {
                for (int j = 0; j < 26; j++){
                    if (!curr->children[j]) continue;
                    if (search(word + i + 1, curr->children[j])) return true;
                    
                }
                return false;
            }
        }
        return curr->tail;
    }
public:
    WordDictionary() {
        memset(len, false, sizeof(len));
    }
    
    void addWord(string word) {
        len[word.length()] = true;
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c-'a'])
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->tail = true;
    }
    
    bool search(string word) {
        if (!len[word.length()]) return false;
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

