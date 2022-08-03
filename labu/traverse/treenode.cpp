#include <iostream>
#include <deque>
using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
    TreeNode(int val){
        this->val = val;
    }
};

TreeNode* buildTree(int* nums, int n){
    deque<TreeNode*> dq;
    TreeNode* root = new TreeNode(nums[0]);
    dq.push_back(root);
    int i = 1;
    while (i < n){
        int len = dq.size();
        for (int j = 0; j < len; j++){
            TreeNode* curr = dq.front();
            dq.pop_front();
            if (i >= n) break;
            if (nums[i] != INT_MIN){
                curr->left = new TreeNode(nums[i]);
                dq.push_back(curr->left);
            }
            i++;
            if (i >= n) break;
            if (nums[i] != INT_MIN){
                curr->right = new TreeNode(nums[i]);
                dq.push_back(curr->right);
            }
            i++;
        }
    }
    return root;
}
