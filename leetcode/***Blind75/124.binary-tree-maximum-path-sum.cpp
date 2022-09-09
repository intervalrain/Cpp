#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSideSum(root);
        return res;
    }
    int maxSideSum(TreeNode* root){
        if (!root) return 0;
        int left = max(maxSideSum(root->left), 0);
        int right = max(maxSideSum(root->right), 0);
        int sum = left + right + root->val;
        res = max(res, sum);
        return root->val + max(left, right);
    }
};
// @lc code=end

