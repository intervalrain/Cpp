#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    int rob(vector<int>& nums){
        vector<vector<int>> dp(2, vector<int>(nums.size()+1));
        if (nums.size() == 1) return nums[0];
        int res = max(nums[0],nums[1]);
        if (nums.size() == 2) return res;
        if (nums.size() == 3) return max(res, nums[2]);

        dp[0][1] = nums[0];
        dp[1][2] = nums[1];

        for (int i = 2; i < nums.size()-1; i++){
            dp[0][i+1] = nums[i] + max(dp[0][i-1], dp[0][i-2]);
            res = max(res, dp[0][i+1]);
        }
        for (int i = 2; i < nums.size(); i++){
            dp[1][i+1] = nums[i] + max(dp[1][i-1], dp[1][i-2]);
            res = max(res, dp[1][i+1]);
        }
        return res;
    }
};

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> nums(n);
    cout << "nums = ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution* sol = new Solution();
    cout << sol->rob(nums) << endl;

    return 0;
}
