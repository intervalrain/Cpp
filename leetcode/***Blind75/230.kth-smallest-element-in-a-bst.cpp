#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    TreeNode* curr;
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        inorder(root, k, i);
        return curr->val;
    }
    void inorder(TreeNode* root, int k, int& i){
        if (!root) return;
        inorder(root->left, k, i);
        i++;
        if (i == k) curr = root;
        inorder(root->right, k, i);
        
    }
};
// @lc code=end

