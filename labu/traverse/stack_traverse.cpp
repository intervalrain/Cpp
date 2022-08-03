#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define null INT_MIN

using namespace std;

class TreeNode;
TreeNode* build(int[], int);
TreeNode* build(vector<int>);

class TreeNode{
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
    }
    TreeNode(vector<int> nums){
        TreeNode* root = build(nums);
        this->val = root->val;
        this->left = root->left;
        this->right = root->right;
    }
};
TreeNode* build(int nums[], int n){
    vector<int> vec(nums, nums+n);
    return build(vec);
}

TreeNode* build(vector<int> nums){
    if (nums.size() == 0) return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nums[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()){
        int n = q.size();
        for (int j = 0; j < n; j++){
            TreeNode* curr = q.front();
            q.pop();
            if (nums[i] != null){
                curr->left = new TreeNode(nums[i++]);
                q.push(curr->left);
            }
            if (i < nums.size() && nums[i] != null){
                curr->right = new TreeNode(nums[i++]);
                q.push(curr->right);
            }
        }
    }
    return root;
}

vector<int> preorder;
vector<int> inorder;
vector<int> postorder;



void traverse(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> st;
    while (root != NULL || !st.empty()){
        while (root != NULL){
            st.push(root);
            // preorder
            preorder.push_back(root->val);
            root = root->left;
        }
        root = st.top();
        st.pop();
        // inorder
        inorder.push_back(root->val);
        root = root->right;
        // postorder
//        postorder.push_back(root->val);
    }

}

void print(vector<int> nums){
    for (int x:nums){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    TreeNode* root = new TreeNode(vec);
    traverse(root);
    print(preorder);
    print(inorder);
//    print(postorder);


    return 0;
}
