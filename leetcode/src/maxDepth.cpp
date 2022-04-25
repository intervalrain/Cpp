#include <iostream>
#include <stddef.h>
#include <cmath>

using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }
    
    int traverse(TreeNode* root, int depth){
        if (root == NULL)
            return depth;
        return max(traverse(root->left, depth + 1), traverse(root->right, depth + 1));
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution *sol = new Solution();
    std::cout << sol->maxDepth(root) << std::endl;

    return 0;
}