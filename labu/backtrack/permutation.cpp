#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int>> permutation(vector<int> nums){
        vector<int> path;
        unordered_map<int,int> map;
        vector<vector<int>> res;
        for (int x : nums) map[x]++;
        backtrack(nums, path, map, res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& path, unordered_map<int,int>& map, vector<vector<int>>& res){
        if (path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for (int x : nums){
            if (map[x] == 0){
                continue;
            }
            path.push_back(x);
            map[x]--;
            backtrack(nums, path, map, res);
            path.pop_back();
            map[x]++;
        }
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums = {1,2,3};
    vector<vector<int>> permutations = sol->permutation(nums);
    for (auto v : permutations){
        for (auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}