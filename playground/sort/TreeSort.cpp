#include "agtr.h"

class TreeNode {
private:
    TreeNode* left, *right;
    int val;
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }
    void dfs(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
public:
    TreeNode() {}
    TreeNode(int val)
        : val(val) {}
    TreeNode(int val, TreeNode* left, TreeNode* right)
        : val(val), left(left), right(right) {}

    void insert(int val) {
        insert(this, val);
    }
    vector<int> getArray() {
        vector<int> nums;
        dfs(this, nums);
        return nums;
    }

};

void sort(vector<int>& nums) {
    TreeNode* root = new TreeNode(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        root->insert(nums[i]);
    }
    nums = root->getArray();
}

int main() {
    agtr::judge(sort);
    return 0;
}
