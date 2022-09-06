#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        // return isValid(root, INT_MIN, INT_MAX);
        return isValid(root, NULL, NULL);
    }
    bool isValid(TreeNode* root, TreeNode* minTree, TreeNode* maxTree){
        if (!root) return true;
        if (minTree && root->val <= minTree->val) return false;
        if (maxTree && root->val >= maxTree->val) return false;
        return isValid(root->left, minTree, root) && isValid(root->right, root, maxTree);
    }
};
// @lc code=end

