#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        dfs(root, res, path);
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, vector<int> path){
        path.push_back(root->val);
        if (!root->left && !root->right){
            res.push_back(combine(path));
        }
        if (root->left) dfs(root->left, res, path);
        if (root->right) dfs(root->right, res, path);
        path.pop_back();
    }
    string combine(vector<int> path){
        string s;
        for (int i = 0; i < path.size()-1; i++){
            s += (to_string(path[i]) + "->");
        }
        s += (to_string(path[path.size()-1]));
        return s;
    }
};
// @lc code=end

