#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()){
            res.push_back({});
            vector<int>& arr = res[level];
            int sz = q.size();
            while (sz--){
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return res;
    }
    // vector<vector<int>> levelOrderDFS(TreeNode* root) {
    //     vector<vector<int>> res;
    //     dfs(root, 0, res);
    //     return res;
    // }
    // void dfs(TreeNode* root, int level, vector<vector<int>>& res){
    //     if (!root) return;
    //     if (res.size() == level) res.push_back({});
    //     dfs(root->left, level+1, res);
    //     res[level].push_back(root->val);
    //     dfs(root->right, level+1, res);
    // }
};
// @lc code=end

