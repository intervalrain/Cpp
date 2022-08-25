#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    unordered_map<TreeNode*, int> map;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (map.count(root)) return map[root];

        int val = 0;

        if (root->left) val += rob(root->left->left) + rob(root->left->right);
        if (root->right) val += rob(root->right->left) + rob(root->right->right);

        val = max(val + root->val, rob(root->left) + rob(root->right));
        map[root] = val;
        return val;
    }

    // int rob(TreeNode* root) {
    //     pair<int, int> p = sub(root);
    //     return max(p.first, p.second);
    // }
    // pair<int,int> sub(TreeNode* root){
    //     if (!root) return {0, 0};
    //     pair<int,int> left = sub(root->left);
    //     pair<int,int> right = sub(root->right);
        
    //     int rob = root->val + left.first + right.first;
    //     int pass = max(left.first, left.second) + max(right.first, right.second);
        
    //     return {pass, rob};
    // }
};
// @lc code=end

