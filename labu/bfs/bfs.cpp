#include <iostream>
#include "treenode.cpp"
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> preorder(TreeNode* root){
        vector<int> res;
        preorder_traverse(root, res);
        return res;
    }
    vector<int> postorder(TreeNode* root){
        vector<int> res;
        postorder_traverse(root, res);
        return res;
    }
    vector<int> inorder(TreeNode* root){
        vector<int> res;
        inorder_traverse(root, res);
        return res;
    }
    vector<int> bfs(TreeNode* root){
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> used;
        
        q.push(root);
        used.insert(root);
        int step = 0;

        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                res.push_back(curr->val);
                // for (child : node)
                if (curr->left != nullptr && !used.count(curr->left)){
                    q.push(curr->left);
                    used.insert(curr->left);
                }
                if (curr->right != nullptr && !used.count(curr->right)){
                    q.push(curr->right);
                    used.insert(curr->right);
                }
            }
            step++;
        }
        
        return res;
    }
private:
    void preorder_traverse(TreeNode* root, vector<int>& res){
        if (root == nullptr) return;
        res.push_back(root->val);
        preorder_traverse(root->left, res);
        preorder_traverse(root->right, res);
    }
    void postorder_traverse(TreeNode* root, vector<int>& res){
        if (root == nullptr) return;
        postorder_traverse(root->left, res);
        postorder_traverse(root->right, res);
        res.push_back(root->val);
    }
    void inorder_traverse(TreeNode* root, vector<int>& res){
        if (root == nullptr) return;
        inorder_traverse(root->left, res);
        res.push_back(root->val);
        inorder_traverse(root->right, res);
    }
};


void print(vector<int> vec){
    cout << "[";
    int n = vec.size();
    for (int i = 0; i < n-1; i++){
        cout << vec[i] << ",";        
    }
    cout << vec[n-1] << "]";
}

int main(){
    int nums[] = {1,2,3,4,5,6,7};
    TreeNode* node = buildTree(nums, 7);
    Solution* sol = new Solution();
    vector<vector<int>> res(4);
    res[0] = sol->preorder(node);
    res[1] = sol->inorder(node);
    res[2] = sol->postorder(node);
    res[3] = sol->bfs(node);

    for (int i = 0; i < 4; i++){
        print(res[i]); 
        cout << endl;
    }
    
    return 0;
}
