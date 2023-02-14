#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int _val)
      :val(_val) {}
};

TreeNode* genTree(int n) {
    if (n == 0) return NULL;
    queue<TreeNode*> q;
    int i = 0;
    TreeNode* root = new TreeNode(i++);
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* curr = q.front();
            q.pop();
            if (i < n) curr->left = new TreeNode(i++);
            if (i < n) curr->right = new TreeNode(i++);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void levelorder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

bool find(TreeNode* root, int target) {
//    if (!root) return false;
//    if (root->val == target) return true;
//    return find(root->left, target) || find(root->right, target);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->val == target) return true;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    TreeNode* root = genTree(n);

    cout << (find(root, 5) ? "yes" : "no");

    return 0;
}
