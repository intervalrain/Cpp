#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return sum;
    }
    void dfs(TreeNode* root, TreeNode* papa, TreeNode* grandpa){
        if (!root) return;
        if (grandpa && (grandpa->val & 1) == 0){
            sum += root->val;
        }
        dfs(root->left, root, papa);
        dfs(root->right, root, papa);
    }
};
// @lc code=end

