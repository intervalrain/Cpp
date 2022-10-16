/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    vector<TreeNode*> dp[21];
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if (dp[n].size() > 0) return dp[n];
        if (n == 1){
            res.push_back(new TreeNode());
        } else if (n % 2 == 1){
            for (int i = 1; i <= n-2; i+=2){
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(n-1-i);
                for (int i = 0; i < left.size(); i++){
                    for (int j = 0; j < right.size(); j++){
                        res.push_back(new TreeNode(0, left[i], right[j]));
                    }
                }
            }
        }
        dp[n] = res;
        return res;
    }
};
// @lc code=end

