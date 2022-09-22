#include <bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

string to_string(TreeNode* root){
    if (!root) return "[]";

    string s;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if (!curr){
            s += "null, ";
            continue;
        }

        s += to_string(curr->val) + ", ";
        q.push(curr->left);
        q.push(curr->right);
    }

    return "[" + s.substr(0, s.length()-2) + "]";
}

void trim(string& s){
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

TreeNode* buildTree(string input) {
    trim(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trim(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trim(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void print(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        print(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        print(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

void bfs(TreeNode* root, vector<int>& res){
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        res.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

void dfs(TreeNode* root, vector<int>& res){
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        res.push_back(curr->val);
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

void print(vector<int> vec){
    for (int x : vec) cout << x << " ";
    cout << endl;
}

int main(){

    string tree = "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]";
    TreeNode* root = buildTree(tree);
    print(root);

    vector<int> dvec, bvec;
    dfs(root, dvec);
    bfs(root, bvec);

    print(dvec);
    print(bvec);


    return 0;
}
