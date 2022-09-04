#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    int leftMost = 0;
    int rightMost = 0;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> pq;
        dfs(root, 0, 0, pq);
        sort(pq.begin(), pq.end());
        vector<vector<int>> res(rightMost-leftMost+1);
        for (int i = 0; i < pq.size(); i++){
            int shift = pq[i][0];
            int val = pq[i][2];
            res[shift-leftMost].push_back(val);
        }
        return res;
    }
    void dfs(TreeNode* root, int level, int shift, vector<vector<int>>& pq){
        if (!root) return;
        leftMost = min(leftMost, shift);
        rightMost = max(rightMost, shift);
        
        dfs(root->left, level+1, shift-1, pq);
        pq.push_back({shift, level, root->val});
        dfs(root->right, level+1, shift+1, pq);
    }
};
// @lc code=end

