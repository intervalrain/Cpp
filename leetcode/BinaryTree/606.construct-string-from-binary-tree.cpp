#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string tree2str(TreeNode* root) {
        string res = to_string(root->val);
        if (!root->left && !root->right)
            return res;
        else if (!root->left && root->right)
            return res + "()(" + tree2str(root->right) + ")";
        else if (!root->right && root->left)
            return res + "(" + tree2str(root->left) + ")";
        return res + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";

    }
};
// @lc code=end

