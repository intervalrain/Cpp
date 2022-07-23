#include <iostream>
#include "treenode.cpp"

using namespace std;

void traverse(TreeNode* root){
    if (root == NULL){
        return;
    }
    // preorder position
    traverse(root->left);
    // inorder position
    cout << root->val << " ";

    traverse(root->right);
    // postorder position
}

int main(){

    int nums[] = {1,2,3,4,5,6,7,8,9,0};
    TreeNode* root = buildTree(nums, 10);
    traverse(root);

    return 0;
}
