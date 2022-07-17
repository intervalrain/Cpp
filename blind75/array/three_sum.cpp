#include <iostream>
#include <vector>
#include "snippet.cpp"
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        unordered_map<int,int> map;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 2; i++){
            if (nums[i] > 0) break;
            for (int j = i + 1; j < nums.size() - 1; j++){
                int toFind = -(nums[i] + nums[j]);
                if (map.count(toFind) && map[toFind] > j){
                    vector<int> vec = {nums[i], nums[j], toFind};
                    res.push_back(vec);
                }
                j = map[nums[j]];
            }
            i = map[nums[i]];
        }
        return res;
    }
};

int main(){
    Solution* sol = new Solution();
    vector<int> nums;
    input(nums);
    vector<vector<int>> vvec = sol->threeSum(nums);
    for (auto vec : vvec){
        for (auto v: vec){
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
