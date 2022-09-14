#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> map(10, 0);
        map[root->val]++;
        backtrack(root, map);
        return cnt;
    }
    void backtrack(TreeNode* root, vector<int>& map){
        if (!root) return;
        if (!root->left && !root->right){
            if (isPalindrome(map)) cnt++;
            return;
        }
        if (root->left) {
            map[root->left->val]++;
            backtrack(root->left, map);
            map[root->left->val]--;
        }
        if (root->right) {
            map[root->right->val]++;
            backtrack(root->right, map);
            map[root->right->val]--;
        }
    }
    bool isPalindrome(vector<int>& map){
        int odd = 0;
        for (int& x : map)
            if ((x & 1) == 1)
                odd++;
        return odd < 2;
    }
};
// @lc code=end

