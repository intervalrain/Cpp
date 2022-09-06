#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        queue<int> q;
        int n = inorder.size();
        for (int i = 0; i < preorder.size(); i++){
            map[inorder[i]] = i;
            q.push(preorder[i]);
        }
        return build(inorder, map, q, 0, n-1);
    }
    TreeNode* build(vector<int>& inorder, unordered_map<int,int>& map, queue<int>& q, int left, int right){
        if (q.empty() || left > right) return NULL;
        if (left == right) {
            q.pop();
            return new TreeNode(inorder[left]);
        }
        int val = q.front();
        q.pop();
        int mid = map[val];
        return new TreeNode(val, 
                           build(inorder, map, q, left, mid-1),
                           build(inorder, map, q, mid+1, right));
    }
};
// @lc code=end

