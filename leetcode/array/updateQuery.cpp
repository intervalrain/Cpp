#include <bits/stdc++.h>
using namespace std;

void print(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

class Solution{
    public:
        int n;
        vector<int> updateQuery(int n, int k, vector<vector<int> >& q){
            this->n = n;
            vector<vector<int> > tree(n, vector<int>(n,0));
            for (int i = 0; i < k; i++){
                int l = q[i][0] - 1;
                int r = q[i][1] - 1;
                int x = q[i][2];
                tree[r-l][l] |= x;
            }
            update(tree, 0, n-2);
            update(tree, 1, n-1);

            return tree[0];
        }
        void update(vector<vector<int> >& tree, int left, int right){
            int level = right - left;

            if (left == 0)
                tree[level][0] |= tree[level+1][0];
            else if (right == n-1)
                tree[level][n-1-level] |= tree[level+1][n-1-level-1];
            else {
                tree[level][left] |= tree[level+1][left-1];
                tree[level][left] |= tree[level+1][left];
            }
            
            if (level == 0) return;
            update(tree, left, right-1);
            update(tree, left+1, right);
        }
};



int main(){
    int n = 2;
    int k = 2;
    vector<vector<int> > q;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(7);
    q.push_back(vec);
    vec.clear();
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(3);
    vec.clear();
    q.push_back(vec);

    Solution sol;
    print(sol.updateQuery(n,k,q));
}