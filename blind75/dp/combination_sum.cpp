#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int combinationSum(vector<int>& nums, int target){
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++){
            for (int num : nums){
                if (i >= num){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};

int main(){
    Solution* sol = new Solution();
    cout << "n = ";
    int n;
    cin >> n;
    cout << "nums = ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << "target = ";
    int target;
    cin >> target;

    cout << sol->combinationSum(nums, target) << endl;

    return 0;
}
