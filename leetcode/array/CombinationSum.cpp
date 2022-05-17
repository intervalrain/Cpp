#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> comb;
        combine(res, comb, k, 1, n);
        return res;
    }
    
    void combine(vector<vector<int> > res, vector<int> comb, int k, int start, int n){
        if (comb.size() == k && n == 0){
            vector<int> li (comb);
            res.push_back(li);
            return;
        }
        for (int i = start; i <= 9; i++){
            comb.push_back(i);
            combine(res, comb, k, i+1, n-i);
            comb.pop_back();
        }
    }
};

int main(){
    int k = 3, n = 7;
    Solution* sol = new Solution;
    vector<vector<int> > res = sol->combinationSum3(k, n);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}