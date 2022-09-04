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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // {shift, depth, val}
        queue<pair<TreeNode*, pair<int,int>>> q; // {root, {shift, depth}}
        q.push({root, {0,0}});
        
        int leftMost = 0;
        int rightMost = 0;

        while (!q.empty()){
            TreeNode* node = q.front().first;
            int shift = q.front().second.first;
            int depth = q.front().second.second;
            leftMost = min(shift, leftMost);
            rightMost = max(shift, rightMost);
            q.pop();
            mp[shift][depth].insert(node->val);
            if (node->left) q.push({node->left, {shift-1, depth+1}});
            if (node->right) q.push({node->right, {shift+1, depth+1}});
        }
        vector<vector<int>> res(rightMost-leftMost+1);

        for (auto s : mp){
            int shift = s.first;
            for (auto d : s.second){    
                for (auto v : d.second){
                    res[shift-leftMost].push_back(v);
                }
            }
        }
        return res;
    }
};
// @lc code=end

