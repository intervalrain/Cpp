/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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
class FindElements {
public:
    TreeNode* root_;
    FindElements(TreeNode* root):root_(root) {}
    
    bool find(int target) {
        stack<int> st;
        TreeNode* curr = root_;
        while (target > 0){
            st.push((target-1)%2);  // 0 for left, 1 for right
            target = (target-1)/2;
        }
        while (!st.empty()){
            if (st.top() == 0){
                curr = curr->left;
                if (!curr) return false;
            } else {
                curr = curr->right;
                if (!curr) return false;
            }
            st.pop();
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

