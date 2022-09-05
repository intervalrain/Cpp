#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()){
            if (level == res.size()){
                res.push_back(vector<int>());
            }
            int sz = q.size();
            while (sz--){
                Node* curr = q.front();
                q.pop();
                res[level].push_back(curr->val);
                for (Node* child : curr->children){
                    if (child){
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return res;
    }
};
// @lc code=end

