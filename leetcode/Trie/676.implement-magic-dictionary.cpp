#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

// @lc code=start
class TrieNode {
public:
    int entry;
    bool end;
    vector<TrieNode*> child;

    TrieNode(){
        this->entry = 0;
        this->end = false;
        this->child = vector<TrieNode*>(26);
    }
};
class MagicDictionary {
private:
    TrieNode* root;
    
    void addWord(string word){
        TrieNode* curr = root;
        for (char c : word){
            if (!curr->child[c-'a']){
                curr->child[c-'a'] = new TrieNode();
                curr->entry++;
            }
            curr = curr->child[c-'a'];
        }
        curr->end = true;
    }

    bool search(string word, int token, TrieNode* curr){
        if (token < 0) return false;
        for (int i = 0; i < word.length(); i++){
            char c = word[i];
            if (!curr->child[c-'a'] || curr->entry > 1){
                for (int j = 0; j < 26; j++){
                    if (!curr->child[j] || c-'a' == j) continue;
                    if (search(word.substr(i+1), token-1, curr->child[j])) return true;
                }
            }
            if (!curr->child[c-'a']) return false;
            curr = curr->child[c-'a'];
        }
        return curr->end && token == 0;
    }
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string word : dictionary)
            addWord(word);
    }
    
    bool search(string searchWord) {
        return search(searchWord, 1, root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

