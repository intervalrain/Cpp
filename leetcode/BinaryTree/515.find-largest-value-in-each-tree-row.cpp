#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        traverse(root, res, 0);
        return res;
    }
    void traverse(TreeNode* root, vector<int>& res, int depth){
        if (!root) return;
        if (res.size() == depth){
            res.push_back({});
            res[depth] = root->val;
        } else if (root->val > res[depth]){
            res[depth] = root->val;
        }
        traverse(root->left, res, depth+1);
        traverse(root->right, res, depth+1);
    }
};
// @lc code=end

