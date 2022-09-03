#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
#define ll long long int
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<ll>> path;
        vector<double> res;
        dfs(root, path, 0);
        for (int i = 0; i < path.size(); i++){
            ll sum = 0;
            for (int j = 0; j < path[i].size(); j++){
                sum += path[i][j];
            }
            res.push_back(((double)sum)/path[i].size());
        }
        return res;
    }
    void dfs(TreeNode* root, vector<vector<ll>>& path, int level){
        if (path.size() == level) path.push_back(vector<ll>());
        path[level].push_back(root->val);
        if (root->left) dfs(root->left, path, level+1);
        if (root->right) dfs(root->right, path, level+1);
    }
};
// @lc code=end

