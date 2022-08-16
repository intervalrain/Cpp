/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        maxDepth(root);
        return res;
    }
    int maxDepth(TreeNode* root){
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};
// @lc code=end

