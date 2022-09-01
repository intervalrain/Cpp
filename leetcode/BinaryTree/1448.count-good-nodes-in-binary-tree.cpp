/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int cnt;
    int goodNodes(TreeNode* root) {
        cnt = 0;
        traverse(root, root->val);
        return cnt;
    }
    void traverse(TreeNode* root, int curr){
        if (!root) return;
        if (root->val >= curr) cnt++;
        traverse(root->left, max(curr, root->val));
        traverse(root->right, max(curr, root->val));
    }
};
// @lc code=end

