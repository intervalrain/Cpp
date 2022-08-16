/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
    vector<TreeNode*> buildTree(int left, int right){
        if (left > right) return {NULL};
        if (left == right) return {new TreeNode(left)};
        vector<TreeNode*> res;

        for (int i = left; i <= right; i++){
            vector<TreeNode*> leftTree = buildTree(left, i-1);
            vector<TreeNode*> rightTree = buildTree(i+1, right);
            for (TreeNode* lnode : leftTree){
                for (TreeNode* rnode : rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

