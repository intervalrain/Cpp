#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++){
            if (map.count(target - nums[i])){
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main(){
    Solution* sol = new Solution();
    int n;
    int target;

    cout << "n = ";
    cin >> n;

    vector<int> nums(n, 0);

    cout << "nums = ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "target = ";
    cin >> target;


    vector<int> res = sol->twoSum(nums, target);
    cout << res[0] << ", " << res[1] << endl;

    return 0;
}
